import re as R
# This is an approximation of a lexer/parser/interpreter that takes the NIFPGA C header
# from the NIFGPA Interface C Generator and creates a file containing a C struct that caches
# values from the FPGA, creates functions for writing values to the FPGA, creates a function
# to update the values cached in the struct, and creates an additional header file for
# interfacing with the FPGA. This handles all of the NIFPGA session tracking and will pass
# notice of errors.

header = 'NiFpga_Indicators.h'

class Nest:
    empty = ()
    def __init__(self, s):
        self.inner = []
        self.s = s
        
    def __str__(self):
        def str_h(arr):
            return '\t'.join(arr)
            
        if self.inner:
            return f'{self.s}\n\t{str_h([x.__str__() for x in self.inner])}'
        else:
            return self.s
        
    def add(self, elem):
        assert elem is Nest.empty or isinstance(elem, Nest)
        self.inner.append(elem)
        return self
    __repr__ = __str__
        
# This creates a symple c struct for cacheing values from the FPGA
def gen_struct(decs):
    struct_arr = ['typedef struct {']
    for dec in decs:
        struct_arr.append(f'\t{dec[0]} {dec[1]};')
    struct_arr.append('} FPGA_CACHE;')
    return struct_arr

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

path = '/home/admin/ProjectFolder/FPGA/NiFpga_ExampleCompactRIO_Bitfile'

device = "RIO0";
h = open(header, 'r')
i = 0
for line in h:
    if(i == 0 and p_bit.match(line)):
        name = R.search(p_bit, line).group(1)
        p_dec = R.compile(f'\s*{name}_Indicator(.+)_(\w+)\s*=\s*(.+),$')
        i = 1
    elif(i == 1 and p_dec.match(line)):
        r = R.search(p_dec, line)
        decs.append((name_to_type[r.group(1)],r.group(2),r.group(3)))
h.close()


f_out = open('generated.c', 'w')
for line in includes:
    f_out.write(f'#include {line}\n')
f_out.write('\n')

for line in gen_struct(decs):
    f_out.write(line + '\n')
f_out.write('\n')

# Create update method
f_out.write('Ni refresh_cache(){\n')

f_out.write('\t return 0;\n')
f_out.write('}')
f_out.close()



