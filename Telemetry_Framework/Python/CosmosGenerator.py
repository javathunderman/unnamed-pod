###############################################################################
#  Project: UMDLoop
#  Module: CosmosGenerator
#  File: CosmosGenerator.py
###############################################################################
#  Purpose:
#
#     Program will read from telemetry configuration database files to
#     generate a COSMOS target capable of receiving, interpreting, displaying,
#     and post-processing the specified telemetry configuration.
###############################################################################
#  Change History:
#
#    Author      Date      Description of Change
#  ----------  --------  --------------------------------------------------
#  Ryan W.     10-02-18  Initial version.
###############################################################################

import os
import shutil
from pathlib import Path
import CosmosConfig as cc
from Telemetry import Telemetry

###############################################################################
# Initialization
###############################################################################

# Verify telemetry configuration database files exist
assert Path("../cosmos_config.yaml").exists(), "Couldn't locate cosmos_config.yaml"
assert Path("../tlm_parms.csv").exists(), "Couldn't locate tlm_parms.csv"

# Load values from cosmos_config.yaml into config dict
config = cc.generate_config()

# Load values from tlm_parms.csv into tlm object
tlm = Telemetry(config)

# Remove existing COSMOS target folder
target_folder_path = f'./{config["target_name"].upper()}'
if Path(target_folder_path).exists():
    shutil.rmtree(target_folder_path)
    
###############################################################################
# COSMOS Target CMD and TLM Definition
###############################################################################

# Create directory structure for new COSMOS target
os.mkdir(target_folder_path)
os.mkdir(f'{target_folder_path}/cmd_tlm')

# Create tlm definition file
tlm_path = target_folder_path + '/cmd_tlm/' + config["target_name"].lower() + '_tlm.txt'
with open(tlm_path, "w") as file:
    file.write(cc.generate_telemetry_header(config))
    for item in tlm.get_all():
        file.write(item.get_definition())
        
# Craete cmd definition file
cmd_path = target_folder_path + '/cmd_tlm/' + config["target_name"].lower() + '_cmd.txt'
with open(cmd_path, "w") as file:
    pass # TODO Add cmd definitions here
    
# Create cmd_tlm_server.txt file
server_path = target_folder_path + '/cmd_tlm_server.txt'
with open(server_path, "w") as file:
    file.write(cc.define_server_file(config))
    
###############################################################################
# COSMOS Group Screen Definition
###############################################################################
    
# Create screens folder
screens_path = target_folder_path + "/screens"
os.mkdir(screens_path)

# Create screen definition file for each group
if config["group_screens"]:
    for [name, group] in tlm.get_all_groups().items():
        with open(f'{screens_path}/{name}.txt', "w") as file:
            file.write(cc.get_screen_header(config, name))
            for item in group:
                file.write(item.get_screen_definition() + '\n')
            file.write("END\n")

###############################################################################
# COSMOS Group Post-Processing Definition
###############################################################################

# Create tools folder
tools_path = target_folder_path + "/tools"
os.mkdir(tools_path)

# Create tlm_extractor folder
extractor_path = target_folder_path + "/tools/tlm_extractor"
os.mkdir(extractor_path)

# Create extractor config file for each group
for [name, group] in tlm.get_all_groups().items():
    with open(f'{extractor_path}/{name}.txt', "w") as file:
        if config["dense_logs"]:
            file.write("FILL_DOWN\n\n")
            
        for item in group:
            file.write(item.get_extractor_definition() + '\n')
