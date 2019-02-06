import re as R
import tkinter as tk
from tkinter import filedialog
import ntpath as nt
# This is an approximation of a lexer/parser/interpreter that takes the NIFPGA C header
# from the NIFGPA Interface C Generator and creates a file containing a C struct that caches
# values from the FPGA, creates functions for writing values to the FPGA, creates a function
# to update the values cached in the struct, and creates an additional header file for
# interfacing with the FPGA. This handles all of the NIFPGA session tracking and will pass
# notice of errors.



root = tk.Tk()
root.withdraw()

header = filedialog.askopenfilename()
bit = nt.basename(filedialog.askopenfilename()).split('.')[0] + '_Bitfile'

win_path = '/'.join(header.split('/')[0:-1])+'/'
header = nt.basename(header)



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
includes = [f'"{header}"', '"NiFpga.h"']

name = ''

decs = []
conts = []
p_bit = R.compile(f'^#define {bit}\s*"(.+).lvbitx"$')
p_start = R.compile("^typedef\s*enum$")
p_dec = ''
p_cont = ''
p_end = ''
p_sig = R.compile('^static\s+const\s+char\*\s+const\s+(.*_Signature).*')
status = 'NiFpga_Status_Success'
path = '/home/admin/ProjectFolder/FPGA/'
signature = ''
resource = "RIO0";


h = open(win_path + header, 'r')
i = 0
for line in h:
    if(p_sig.match(line)):
        signature = R.search(p_sig, line).group(1)
    else:
        if(i == 0 and p_bit.match(line)):
            name = R.search(p_bit, line).group(1)
            p_dec = R.compile(f'\s*{name}_Indicator(.+)_(\w+)\s*=\s*(.+),$')
            p_cont = R.compile(f'\s*{name}_Control(.+)_(\w+)\s*=\s*(.+),$')
            i = 1
        elif(i == 1 and p_dec.match(line)):
            r = R.search(p_dec, line)
            decs.append((name_to_type[r.group(1)],r.group(2),r.group(3), r.group(1)))
        elif(i == 1 and p_cont.match(line)):
            r = R.search(p_cont, line)
            conts.append((name_to_type[r.group(1)],r.group(2),r.group(3), r.group(1)))
        
h.close()

h_block = Block('typedef struct {', '} Cache;')

for dec in decs:
    h_block.add(f'{dec[0]} {dec[1]};')

fpga = Block('typedef struct {', '} Fpga;')

# Metadata for the connection to the FPGA
fpga.add('NiFpga_Status status;')
fpga.add('char *bit_path;')
fpga.add('char *signature;')
fpga.add('char *resource;')
fpga.add('NiFpga_Session session;')


# Cache
fpga.add('Cache cache;')


# Generate header for FPGA cache
header_out = open(win_path + 'fpga_cache.h', 'w')
header_out.write('#ifndef __FPGA_CACHE__\n#define __FPGA_CACHE__\n')
for line in includes:
    header_out.write(f'#include {line}\n')
header_out.write('\n')

header_out.write(str(h_block))
header_out.write('\n')

header_out.write(str(fpga))
header_out.write('\n')

# Create update method
base_methods ='''
void default_fpga(Fpga *fpga);

NiFpga_Status init_fpga(Fpga *fpga, uint32_t attr);

NiFpga_Status run_fpga(Fpga *fpga, uint32_t attr);

NiFpga_Status refresh_cache(Fpga *Fpga);

NiFpga_Status fpclose(Fpga *fpga, uint32_t attr);

NiFpga_Status fpfinalize(Fpga *fpga);

'''
header_out.write(base_methods)

# Create write methods
for cont in conts:
    header_out.write(f'NiFpga_Status write_{cont[1]}(Fpga *fpga, {cont[0]} v);\n\n')
    
header_out.write('#endif\n')
header_out.close()

#Write FPGA Implementation
src_out = open(win_path + 'fpga_cache.c', 'w')

#Write includes
src_out.write('#include "fpga_cache.h"\n\n')

for line in includes:
    src_out.write(f'#include {line}\n')
src_out.write('\n')

# Create the method for populating the default values into an FPGA struct
default_fpga = Block('void default_fpga(Fpga *fpga, const char*) {','}')
default_fpga.add('fpga->status = NiFpga_Status_Success;')
default_fpga.add('fpga->bit_path')
src_out.write(default_fpga)
src_out.write('\n')

init = Block('NiFpga_Status init_fpga(Fpga *fpga, uint32_t attr) {','}')

init.add('NiFpga_IfIsNotError(fpga->status, NiFpga_Initialize());')
open_fpga = f'''NiFpga_IfIsNotError(fpga->status, NiFpga_Open(fpga->bit_path, fpga->signature, 
                        fpga->resource, 
                        NiFpga_OpenAttribute_NoRun | attr, 
                        &(fpga->session)));'''
init.add(open_fpga)
init.add('')
init.add('return fpga->status;')

src_out.write(str(init))
src_out.write('\n')


run = Block('NiFpga_Status run_fpga(Fpga *fpga, uint32_t attr) {', '}')
run.add('NiFpga_IfIsNotError(fpga->status, NiFpga_Run(fpga->session, attr));')
run.add('')
run.add('return fpga->status;')


src_out.write(str(run))
src_out.write('\n')


refresh = Block('NiFpga_Status refresh_cache(Fpga *fpga) {', '}')

for dec in decs:
    refresh.add(f'NiFpga_IfIsNotError(fpga->status, NiFpga_Read{dec[3]}(fpga->session, {dec[2]}, &(fpga->cache.{dec[1]})));')
refresh.add('return fpga->status;\n')

src_out.write(str(refresh))
src_out.write('\n')


close = Block('NiFpga_Status fpclose(Fpga *fpga, uint32_t attr) {', '}')
close.add('NiFpga_MergeStatus(&(fpga->status), NiFpga_Close(fpga->session, attr));')
close.add('')
close.add('return fpga->status')

finalize = Block('NiFpga_Status fpfinalize(Fpga *fpga) {', '}')
close.add('NiFpga_MergeStatus(&(fpga->status), NiFpga_Finalize());')
finalize.add('')
finalize.add('return fpga->status')

for cont in conts:
    c_block = Block(f'NiFpga_Status write_{cont[1]}(Fpga *fpga, {cont[0]} v) {{', '}')
    c_block.add(f'NiFpga_IfIsNotError(fpga->status, NiFpga_Write{dec[3]}(fpga->session, {dec[2]}, v));')
    c_block.add('return fpga->status;')

    src_out.write(str(c_block))
    src_out.write('\n')
src_out.close()

#Create Mock Cache .c
src_test = open(win_path + 'fpga_cache.c', 'w')

#Includes
src_test.write('#include "fpga_cache.h"\n\n')
for line in includes:
    src_test.write(f'#include {line}\n')
src_test.write('\n')

default_fpga = Block('void default_fpga(Fpga *fpga, const char*) {','}')
default_fpga.add('fpga->status = NiFpga_Status_Success;')
default_fpga.add('fpga->bit_path')


src_test.close()


