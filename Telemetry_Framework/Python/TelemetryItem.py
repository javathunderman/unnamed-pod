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


class TelemetryItem:
    
    def __init__(self, line, config):
        self.config = config
        values = line.rstrip().split(",")
        
        self.tlm_id        = values[0]
        self.mnemonic      = values[1]
        self.bit_length    = values[2]
        self.datatype      = values[3]
        self.high_rate     = values[4]
        self.conversion_id = values[5]
        self.red_low       = values[6]
        self.yellow_low    = values[7]
        self.yellow_high   = values[8]
        self.red_high      = values[9]
        self.groups        = values[10:]
        while "" in self.groups: self.groups.remove("")
        
    def get_definition(self):
        definition = f'  APPEND_ITEM {self.mnemonic} {self.bit_length} {self.datatype}\n'
        definition += self.conversion_definition();
        definition += self.limits_definition();
        
        return definition
    
    def get_screen_definition(self):
        screen_def = "  HORIZONTAL\n"
        spacer = "    SPACER 10 0 EXPANDING PREFERRED\n"
        
        if self.limits_definition() == "":
            screen_def += f'    LABELVALUE {self.config["target_name"]} '
            screen_def += f'{self.config["packet_name"]} {self.mnemonic} '
            screen_def += f' CONVERTED {self.config["screen_value_width"]}\n'
        else:
            screen_def += f'    LABELVALUELIMITSBAR {self.config["target_name"]} '
            screen_def += f'{self.config["packet_name"]} {self.mnemonic} '
            screen_def += f' CONVERTED {self.config["screen_value_width"]}\n'
        return screen_def + spacer + "  END\n"
    
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