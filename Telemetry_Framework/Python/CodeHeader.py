###############################################################################
#  Project: UMDLoop
#  Module: CodeHeader
#  File: CodeHeader.py
###############################################################################
#  Purpose:
#
#     This class will contain functions to generate a C header file
#     that defines a Telemetry struct and function headers.
###############################################################################
#  Change History:
#
#    Author      Date      Description of Change
#  ----------  --------  --------------------------------------------------
#  Ryan W.     11-06-18  Initial version.
###############################################################################

from fractions import Fraction


def header_definition(tlm):
    header = '#ifndef TELEMETRY_H\n'
    header += '#define TELEMETRY_H\n\n\n'
    header += port_definition(tlm)
    header += struct_definition(tlm)
    header += '\n\n'
    header += main_thread_header()
    header += function_headers(tlm)
    header += '\n\n#endif'
    
    return header

def port_definition(tlm):
    return f'#define PORT {tlm.config["target_port"]}\n\n'

def struct_definition(tlm):
    struct = "typedef struct {\n"
    
    for item in tlm.get_all():
        struct += item.header_definition()
    
    struct += "} Telemetry;\n\n"
    return struct

def main_thread_header():
    return 'void send_tlm(int socket);\n\n'

def function_headers(tlm):
    fractions = set()
    
    # Get set of numeric rate divisions
    rates = set([int(x) for x in tlm.rates if valid_int(x)])
    
    # Generate set of all fractional update functions needed
    for r in rates:
        for i in range(1, r+1):
            frac = Fraction(i, r)
            fractions.add(frac)
            
    # Add lowest rate update function for rate FALSE
    fractions.add(Fraction(1, 1))
          
    # Sort fractions in ascending order
    functions = list(fractions)
    functions.sort()
    
    # Generate function header for each fraction
    headers = ''
    for i in range(0, len(functions)):
        frac = functions[i]
        headers += 'void update_telemetry_'
        headers += f'{frac.numerator}_{frac.denominator}'
        headers += '(Telemetry *tlm);\n'
    
    return headers

def valid_int(input):
    try:
        int(input)
        return True
    except:
        return False
