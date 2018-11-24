import re as R
p_dec = R.compile('NiFpga_Status\sNiFpga_Read(.*)\(NiFpga_Session session,\n\s*')
p_val = R.compile('\s*(\w*)[*]?\s*(value)|(data)')
header = 'NiFpga.h'

# This generates a dictionary to be used for converting NiFpga method names into
# datatypes
h = open(header, 'r')
i = 0
temp = ''
print('name_to_type = {');
for line in h:
    if(i % 3 == 0 and p_dec.match(line)):
        temp = R.search(p_dec, line).groups()[0]
        i += 1
    elif(i % 3 == 1):
        i += 1
    elif(i % 3 == 2):
        if(p_val.match(line)):
            print('\t"' +temp +'": "' + R.search(p_val, line).groups()[0] +'",')
        i += 1
print('}')
h.close()



    
