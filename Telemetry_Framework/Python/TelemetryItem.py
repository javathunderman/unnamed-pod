###############################################################################
#  Project: UMDLoop
#  Module: TelemetryItem
#  File: TelemetryItem.py
###############################################################################
#  Purpose:
#
#     This class will store all relevant values for a single telemetry
#     item. Objects of this class will provide a COSMOS-style definition based
#     on the values associated with the item.
###############################################################################
#  Change History:
#
#    Author      Date      Description of Change
#  ----------  --------  --------------------------------------------------
#  Ryan W.     10-03-18  Initial version.
###############################################################################

from fractions import Fraction


class TelemetryItem:
    
    def __init__(self, line, config):
        self.config = config
        values = line.rstrip().split(",")
        
        self.tlm_id        = values[0]
        self.mnemonic      = values[1]
        self.bit_length    = values[2]
        self.datatype      = values[3]
        self.units         = values[4]
        self.high_rate     = values[5]
        self.conversion_id = values[6]
        self.red_low       = values[7]
        self.yellow_low    = values[8]
        self.yellow_high   = values[9]
        self.red_high      = values[10]
        self.groups        = values[11:]
        while "" in self.groups: self.groups.remove("")
    
    def get_definition(self):
        # COSMOS telemetry parameter definition
        definition = f'  APPEND_ITEM {self.mnemonic} {self.bit_length} {self.datatype}\n'
        definition += self.conversion_definition();
        definition += self.limits_definition();
        definition += self.units_definition();
        
        # Add more instances if high_rate
        try:
            x = int(self.high_rate)
            for i in range(1, x):
                definition += f'  APPEND_ITEM {self.mnemonic}_{i} {self.bit_length} {self.datatype}\n'
                definition += self.conversion_definition();
                definition += self.limits_definition();
                definition += self.units_definition();
        except:
            pass
        
        return definition
    
    def get_screen_definition(self):
        screen_def = ""
        tgt = self.config["target_name"].upper()
        pkt = self.config["packet_name"].upper()
        width = self.config["screen_value_width"]
        decimals = self.config["screen_decimals"]
        name = self.mnemonic
        
        # If limits are defined, add limits color bubble else add mnemonic label
        if self.limits_definition() == "":
            screen_def += f'  LABEL "      {name}"\n'
        else:
            screen_def += f'  LIMITSCOLOR {tgt} {pkt} {name}\n'
        
        # Add value, only list specified number of decimal points
        if self.datatype == 'FLOAT':
            screen_def += f'  FORMATVALUE {tgt} {pkt} {name} "%.{decimals}f" CONVERTED {width}\n'
        else:
            screen_def += f'  VALUE {tgt} {pkt} {name} CONVERTED {width}\n'
        
        # Add units
        screen_def += f'  LABEL "{self.units}"\n'
        
        # Add spacer before limitsbars
        screen_def += f'  SPACER 50 0 FIXED FIXED\n'
        
        # Add limits, if defined
        if self.limits_definition() == "":
            screen_def += "  SPACER 0 0 FIXED FIXED\n"
            screen_def += "  SPACER 0 0 FIXED FIXED\n"
            screen_def += "  SPACER 0 0 FIXED FIXED\n"
        else:
            screen_def += f'  LABEL "{self.red_low}"\n'
            screen_def += f'  LIMITSBAR {tgt} {pkt} {name}\n'
            screen_def += f'  LABEL "{self.red_high}"\n'
            
        return screen_def

    def get_extractor_definition(self):
        definition = ""
        target_name = self.config["target_name"].upper()
        packet_name = self.config["packet_name"].upper()
        
        if self.config["raw_logs"]:
            definition += f'ITEM {target_name} {packet_name} {self.mnemonic} RAW\n'
        
        return definition + f'ITEM {target_name} {packet_name} {self.mnemonic}'
    
    def conversion_definition(self):
        # TODO implement conversion table parsing
        
        return ""
    
    def limits_definition(self):
        try:
            # Verify valid limits
            float(self.red_low)
            float(self.yellow_low)
            float(self.yellow_high)
            float(self.red_high)
            limits = f'    LIMITS DEFAULT {self.config["limits_persistence"]} ENABLED '
            limits += f'{self.red_low} {self.yellow_low} {self.yellow_high} {self.red_high}\n'
            return limits
        except:
            # At least one limit is invalid
            return ""
    
    def units_definition(self):
        return f'    UNITS "{self.units}" "{self.units}"\n'

    def header_definition(self):
        header = f'    unsigned int {self.mnemonic} : {self.bit_length};\n'
        
        try:
            x = int(self.high_rate)
            for i in range(1, x):
                header += f'    unsigned int {self.mnemonic}_{i} : {self.bit_length};\n'
        except:
            pass
                
        return header
    
    def update_definition(self, fn_frac):
        update = ''
        
        if fn_frac:
            num = 1
            while Fraction(num, int(self.high_rate)) != fn_frac: num += 1
            update += f'    tlm->{self.mnemonic}_{num} = '
        else:
            update += f'    tlm->{self.mnemonic} = '
            
        # TODO figure out with Mark
        update += '???;\n'
        
        return update
