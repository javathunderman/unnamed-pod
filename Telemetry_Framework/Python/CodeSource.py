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
    source += defines(tlm)
    source += main_thread(tlm)
    source += build_tlm(tlm)
    
    return source

def imports():
    imports = '#include <sys/socket.h>\n'
    imports += '#include <string.h>\n'
    imports += '#include <stdlib.h>\n'
    imports += '#include <time.h>\n'
    imports += '#include <errno.h>\n'
    imports += '#include <stdio.h>\n'
    imports += '#include "telemetry.h"\n\n\n'
    
    return imports

def defines(tlm):
    # Determine packet length
    pkt_length = 0
    for item in tlm.get_all():
        try:
            pkt_length += int(item.high_rate) * int(item.bit_length)
        except:
            pkt_length += int(item.bit_length)
    
    # Convert bits to bytes, round up
    pkt_length = math.ceil(pkt_length / 8)
    
    # Calculate packet period in nanoseconds
    total_ns = int(1000000000 / tlm.config["packet_frequency"])
    
    defines = f'#define PKT_LENGTH {pkt_length}\n'
    defines += f'#define TLM_FREQ {total_ns}L\n'
    defines += '#define NS_IN_SEC 1000000000L\n'
    defines += '#define UPDATE_DELAY(name) name.tv_sec = name.tv_sec + ((name.tv_nsec + TLM_FREQ) / NS_IN_SEC);\\\n'
    defines += '                           name.tv_nsec = (name.tv_nsec + TLM_FREQ) % NS_IN_SEC;\n'
    defines += '#define INIT_TIMES(name, time) sec = name.tv_sec + ((name.tv_nsec + time) / NS_IN_SEC);\\\n'
    defines += '                               nsec = (name.tv_nsec + time) % NS_IN_SEC;\n\n'
    return defines

def main_thread(tlm):
    # Begin writing send_tlm function
    main = 'void send_tlm(int socket, SA * dest_addr, socklen_t dest_len) {\n'
    main += '    Telemetry tlm;\n\n'
    
    main += current_time()
    
    # Create time structs for delays between tlm udpates
    time = 0
    total_ns = 1000000000 / tlm.config["packet_frequency"]
    fns = CodeHeader.function_headers(tlm).splitlines()
    for i in range(0, len(fns)):
        numerator = int(re.sub('(?!_)\D', '', fns[i]).split('_')[2])
        denominator = int(re.sub('(?!_)\D', '', fns[i]).split('_')[3])
        
        delay = int((total_ns * numerator / denominator) - time);
        time = total_ns * numerator / denominator
        
        if i == 0:
            main += f'    INIT_TIMES(now, {delay}L)\n'
        else:
            main += f'    INIT_TIMES(delay_{i}, {delay}L)\n'
        main += f'    struct timespec delay_{i+1} = {{sec, nsec}};\n\n'
    main += '\n'
        
    # Open infinite loop to send telemetry
    main += '    while(1) {\n'
    
    # Call update functions and send telemetry
    fns = CodeHeader.function_headers(tlm).splitlines()
    clk = 'CLOCK_MONOTONIC'
    for i in range(0, len(fns)):
        call = fns[i][5:].replace("Telemetry *", "&")
        main += f'        clock_nanosleep({clk}, 0, &delay_{i+1}, NULL);\n'
        main += f'        {call}\n\n'
    
    main += '        if(sendto(socket, &tlm, PKT_LENGTH, MSG_NOSIGNAL, dest_addr, dest_len) == -1) {\n'
    main += '            printf("%s\\n", strerror(errno));\n'
    main += '            break;\n'
    main += '        }\n\n'
    
    for i in range(0, len(fns)):
        main += f'        UPDATE_DELAY(delay_{i+1})\n'
    
    main += '    }\n}\n\n'
    
    return main

def current_time():
    return """    struct timespec now;
    if(clock_gettime(CLOCK_MONOTONIC, &now) == -1) {
        printf("clock_gettime() error: %s\\n", strerror(errno));
        exit(-3);
    }
    __time_t sec = now.tv_sec;
    __syscall_slong_t nsec = now.tv_nsec;\n\n"""

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
