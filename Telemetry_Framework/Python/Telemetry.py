###############################################################################
#  Project: UMDLoop
#  Module: Telemetry
#  File: Telemetry.py
###############################################################################
#  Purpose:
#
#     This class will store all telemetry items in a single centralized object. 
#     This class will provide access to all telemetry items in the order they
#     are defined in the database, as well as access to items by group.
###############################################################################
#  Change History:
#
#    Author      Date      Description of Change
#  ----------  --------  --------------------------------------------------
#  Ryan W.     10-03-18  Initial version.
###############################################################################

from TelemetryItem import TelemetryItem as Item

class Telemetry:
    
    def __init__(self, config):
        self.tlm = []
        self.groups = set()
        self.config = config
        self.read_database()
        
    def get_all(self):
        return self.tlm
    
    def get_group(self, group_name):
        group = []
        for item in self.tlm:
            if group_name in item.groups:
                group.append(item)
        return group
    
    def get_all_groups(self):
        groups = []
        for name in self.groups:
            groups.append(self.get_group(name))
        return groups
    
    def read_database(self):
        with open("../tlm_parms.csv") as f:
            next(f)
            for line in f.readlines():
                item = Item(line, self.config)
                self.tlm.append(item)
                self.groups.update(item.groups)
