###############################################################################
#  Project: UMDLoop
#  Module: CodeSource
#  File: CodeSource.py
###############################################################################
#  Purpose:
#
#     This class will contain functions to generate a C source file
#     that defines code to build and send telemetry packets.
###############################################################################
#  Change History:
#
#    Author      Date      Description of Change
#  ----------  --------  --------------------------------------------------
#  Ryan W.     11-11-18  Initial version.
###############################################################################

import re
import math
from fractions import Fraction
import CodeHeader

def source_definition(tlm):
    source = imports()
    source += main_thread(tlm)
    source += build_tlm(tlm)
    
    return source

def imports():
    imports = '#include <sys/socket.h>\n'
    imports += '#include <arpa/inet.h>\n'
    imports += '#include <string.h>\n'
    imports += '#include <stdlib.h>\n'
    imports += '#include <time.h>\n'
    imports += '#include "telemetry.h"\n\n\n'
    
    return imports

def main_thread(tlm):
    # Determine packet length
    pkt_length = 0
    for item in tlm.get_all():
        try:
            pkt_length += int(item.high_rate) * int(item.bit_length)
        except:
            pkt_length += int(item.bit_length)
    
    # Convert bits to bytes, round up
    pkt_length = math.ceil(pkt_length / 8)
    
    
    main = f'#define PORT {tlm.config["udp_read_port"]}\n'
    main += f'#define HOST "{tlm.config["host_ip"]}"\n'
    main += f'#define PKT_LENGTH {pkt_length}\n'
    main += '\n'
    main += 'void main_thread(void) {\n'
    main += '    Telemetry tlm;\n'
    main += '    int s;\n'
    main += '    struct sockaddr_in sa;\n\n'
    
    # Create time structs for delays between tlm udpates
    time = 0
    total_ns = 1000000000 / tlm.config["packet_frequency"]
    fns = CodeHeader.function_headers(tlm).splitlines()
    for i in range(0, len(fns)):
        numerator = int(re.sub('(?!_)\D', '', fns[i]).split('_')[2])
        denominator = int(re.sub('(?!_)\D', '', fns[i]).split('_')[3])
        
        delay = int((total_ns * numerator / denominator) - time);
        time = total_ns * numerator / denominator
        
        (sec, ns) = divmod(delay, 1000000000)
        main += f'    struct timespec delay_{i+1} = {{{sec}, {ns}L}};\n'
    main += '\n'
        
    
    main += '    memset((char *) &sa, 0, sizeof(sa));\n'
    main += '    sa.sin_family = AF_INET;\n'
    main += '    sa.sin_port = htons(PORT);\n\n'
    main += '    if(inet_aton(HOST, &(sa.sin_addr)) == 0)\n'
    main += '        exit(1);\n\n'
    main += '    if((s = socket(AF_INET, SOCK_DGRAM, 0)) == -1)\n'
    main += '        exit(2);\n\n'
    main += '    while(1) {\n'
    
    # Call update functions and send telemetry
    fns = CodeHeader.function_headers(tlm).splitlines()
    clk = 'CLOCK_MONOTONIC'
    for i in range(0, len(fns)):
        call = fns[i][5:].replace("Telemetry *", "&")
        main += f'        clock_nanosleep({clk}, 0, &delay_{i+1}, NULL);\n'
        main += f'        {call}\n\n'
    
    main += '        if(sendto(s, &tlm, PKT_LENGTH, 0, (struct sockaddr *)&sa, sizeof(sa)) == -1)\n'
    main += '            exit(3);\n'
    main += '    }\n}\n\n'
    
    return main

def build_tlm(tlm):
    fns = CodeHeader.function_headers(tlm).splitlines()
    all_rates = tlm.get_all_rates()
    build_fns = ''
    
    # Get set of numeric rate divisions
    rates = set([int(x) for x in tlm.rates if valid_int(x)])
    
    for fn in fns:
        # Remove semicolon and open curly brace
        fn = fn[:-1] + ' {\n'
        
        # Get fraction of current update function
        numerator = int(re.sub('(?!_)\D', '', fn).split('_')[2])
        denominator = int(re.sub('(?!_)\D', '', fn).split('_')[3])
        fn_frac = Fraction(numerator, denominator)
        
        # Determine which rates to update in this function
        update_list = []
        for r in rates:
            for i in range(1, r+1):
                frac = Fraction(i, r)
                if frac == fn_frac:
                    update_list.append(r)
                
        # If fn_frac is 1, then update all parameters
        if fn_frac == 1:
            for item in tlm.get_all():
                fn += item.update_definition(False)
        else:
            for x in update_list:
                for item in all_rates[str(x)]:
                    fn += item.update_definition(fn_frac)
        
        # Close curly brace
        fn += '}\n\n'
        
        build_fns += fn
    
    return build_fns

def valid_int(input):
    try:
        int(input)
        return True
    except:
        return False
