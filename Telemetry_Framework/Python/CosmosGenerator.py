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
from CosmosConfig import generate_config
from Telemetry import Telemetry

# Verify telemetry configuration database files exist
assert Path("../cosmos_config.yaml").exists(), "Couldn't locate cosmos_config.yaml"
assert Path("../tlm_parms.csv").exists(), "Couldn't locate tlm_parms.csv"

# Load values from cosmos_config.yaml into config dict
config = generate_config()

# Load values from tlm_parms.csv into tlm object
tlm = Telemetry(config)

# Remove existing COSMOS target folder
target_folder_path = f'./{config["target_name"].upper()}'
if Path(target_folder_path).exists():
    shutil.rmtree(target_folder_path)

# Create directory structure for new COSMOS target
os.mkdir(target_folder_path)
os.mkdir(f'{target_folder_path}/cmd_tlm')

# Create tlm definition file
tlm_path = target_folder_path + '/cmd_tlm/' + config["target_name"].lower() + '_tlm.txt'
with open(tlm_path, "w") as file:
    file.write(f'TELEMETRY {config["target_name"].upper()} PACKET BIG_ENDIAN\n')
    for item in tlm.get_all():
        file.write(item.get_definition())
        
# Craete cmd definition file
cmd_path = target_folder_path + '/cmd_tlm/' + config["target_name"].lower() + '_cmd.txt'
with open(cmd_path, "w") as file:
    pass # TODO Add cmd definitions here