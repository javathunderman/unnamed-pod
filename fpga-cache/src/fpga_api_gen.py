import re as R
# This is an approximation of a lexer/parser/interpreter that takes the NIFPGA C header
# from the NIFGPA Interface C Generator and creates a file containing a C struct that caches
# values from the FPGA, creates functions for writing values to the FPGA, creates a function
# to update the values cached in the struct, and creates an additional header file for
# interfacing with the FPGA. This handles all of the NIFPGA session tracking and will pass
# notice of errors.

header = 'NiFpga_Indicators.h'

class Block:
    empty = ()
    def __init__(self, s, f = ''):
        self.inner = []
        self.s = s
        self.f = f
        
    def __str__(self):
        def str_h(arr):
            return '\t'.join(arr)
            
        return self.__str_h__(0)

    def __str_h__(self, level):
        assert isinstance(level, int) and level >= 0
        out = ''
        if level > 0 and not self.inner:
            out =  '\t' * level + self.s
        else:
            out = ('\t' * level) + self.s + '\n'
            out += ('\n'.join([x.__str_h__(level + 1) for x in self.inner]).strip('\n'))

        out += ('\n' + self.f if self.f != '' else '')
        out += '\n' if level == 0 else ''

        return out
    def add(self, elem):
        if isinstance(elem, Block):
            self.inner.append(elem)
        else:
            self.inner.append(Block(str(elem)))
        return self

    __repr__ = __str__

# This is the mapping for enum names to datatypes. It is generated with get_dict.py
name_to_type = {
            "Bool": "NiFpga_Bool",
            "I8": "int8_t",
            "U8": "uint8_t",
            "I16": "int16_t",
            "U16": "uint16_t",
            "I32": "int32_t",
            "U32": "uint32_t",
            "I64": "int64_t",
            "U64": "uint64_t",
            "Sgl": "float",
            "Dbl": "double",
}

# the list of includes for the files
includes = [f'"{header}"']

name = ''

decs = []
p_bit = R.compile('^#define NiFpga_Indicators_Bitfile\s*"(.+).lvbitx"$')
p_start = R.compile("^typedef\s*enum$")
p_dec = ''
p_end = ''
p_sig = R.compile('^static\s+const\s+char\*\s+const\s+(.*_Signature).*')
status = 'NiFpga_Status_Success'
path = '/home/admin/ProjectFolder/FPGA/NiFpga_ExampleCompactRIO_Bitfile'
signature = ''
resource = "RIO0";


h = open(header, 'r')
i = 0
for line in h:
    if(p_sig.match(line)):
        signature = R.search(p_sig, line).group(1)
    else:
        if(i == 0 and p_bit.match(line)):
            name = R.search(p_bit, line).group(1)
            p_dec = R.compile(f'\s*{name}_Indicator(.+)_(\w+)\s*=\s*(.+),$')
            i = 1
        elif(i == 1 and p_dec.match(line)):
            r = R.search(p_dec, line)
            decs.append((name_to_type[r.group(1)],r.group(2),r.group(3), r.group(1)))
        
h.close()

h_block = Block('typedef struct {', '} Cache;')

for dec in decs:
    h_block.add(f'{dec[0]} {dec[1]};')

fpga = Block('typedef struct {', '} Fpga;')
new_fpga = f'''const Fpga new_fpga = {{{status}, 
                        "{path}", 
                        {signature}, 
                        {resource}}};\n'''


# Metadata for the connection to the FPGA
fpga.add('NiFpga_Status status;')
fpga.add('char *bit_path;')
fpga.add('char *signature;')
fpga.add('char *resource;')
fpga.add('uint32_t attribute;')
fpga.add('NiFpga_Session session;')


# Cache
fpga.add('Cache cache;')


# Generate header for FPGA cache
header_out = open('fpga_cache.h', 'w')
header_out.write('#ifndef __FPGA_CACHE__\n#define __FPGA_CACHE__\n')
for line in includes:
    header_out.write(f'#include {line}\n')
header_out.write('\n')

header_out.write(str(h_block))
header_out.write('\n')

header_out.write(str(fpga))
header_out.write('\n')

header_out.write(new_fpga)
header_out.write('\n')

# Create update method
header_out.write('NiFpga_Status init_cache(Fpga *fpga);\n')
header_out.write('\n')

header_out.write('Nifpga_Status run_fpga(Fpga *fpga);\n')
header_out.write('\n')

header_out.write('NiFpga_Status refresh_cache(Fpga *Fpga);\n')
header_out.write('\n')

header_out.write('#endif\n')
header_out.close()

src_out = open('fpga_cache.c', 'w')
src_out.write('#include "fpga_cache.h"\n\n')

init = Block('NiFpga_Cache init_fpga(Fpga *fpga){','}')

init.add('NiFpga_IfIsNotError(status, NiFpga_Initalize());')
open_fpga = f'''NiFpga_IfIsNotError(status, NiFpga_Open(fpga->bit_path, fpga->signature, 
                        fpga->resource, 
                        fpga->attribute, 
                        &(fpga->session)));'''
init.add(open_fpga)
init.add('')
init.add('return fpga->status;')

src_out.write(str(init))
src_out.write('\n')


run = Block('Nifpga_Status run_fpga(Fpga *fpga){', '}')

src_out.write(str(run))
src_out.write('\n')


refresh = Block('NiFpga_Status refresh_cache(Fpga *fpga){', '}')

for dec in decs:
    refresh.add(f'NiFpga_IfIsNotError(fpga->status, NiFpga_Read{dec[3]}(fpga->session, {dec[2]}, &(fpga->cache->{dec[1]})));')

refresh.add('return status;\n')

src_out.write(str(refresh))

src_out.close()



