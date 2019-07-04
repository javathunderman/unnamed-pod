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
    header += includes()
    header += defines(tlm)
    header += arg_struct()
    header += struct_definition(tlm)
    header += '\n\n'
    header += main_thread_header()
    header += function_headers(tlm)
    header += '\n\n#endif'
    
    return header

def includes():
    return '#include <sys/socket.h>\n\n'

def defines(tlm):
    defines = '#define SA struct sockaddr\n'
    defines += f'#define TO_USEC {tlm.config["comm_timeout_us"]}\n'
    defines += f'#define PORT {tlm.config["target_port"]}\n\n'
    return defines

def arg_struct():
    struct = 'typedef struct {\n'
    struct += '    int socket;\n'
    struct += '    SA * dest_addr;\n'
    struct += '    socklen_t dest_len;\n'
    struct += '} TelemetryArgs;\n\n'
    return struct


def struct_definition(tlm):
    struct = "typedef struct {\n"
    
    for item in tlm.get_all():
        struct += item.header_definition()
    
    struct += "} Telemetry;\n\n"
    return struct

def main_thread_header():
    return 'void *send_tlm(void *args);\n\n'

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
