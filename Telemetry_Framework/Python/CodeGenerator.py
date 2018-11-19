###############################################################################
#  Project: UMDLoop
#  Module: CodeGenerator
#  File: CodeGenerator.py
###############################################################################
#  Purpose:
#
#     This program will generate C code to support telemetry on the cRIO.
#     This program will generate a header file containing a message struct and
#     function headers. The code will sample each telemetry point according to
#     its defined 'HIGH_RATE' frequency and send telemetry packets via a UDP
#     socket to the specified IP.
###############################################################################
#  Change History:
#
#    Author      Date      Description of Change
#  ----------  --------  --------------------------------------------------
#  Ryan W.     11-04-18  Initial version.
###############################################################################

import os
import shutil
from pathlib import Path
import CosmosConfig as cc
from Telemetry import Telemetry
import CodeHeader
import CodeSource

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

# Remove existing code folder
code_folder_path = f'./{config["target_name"].upper()}_Code'
if Path(code_folder_path).exists():
    shutil.rmtree(code_folder_path)

###############################################################################
# Create header file
###############################################################################

# Create new code folder
os.mkdir(code_folder_path)

# Create new header file
header_path = code_folder_path + '/telemetry.h'

# Create Telemetry struct and function headers
with open(header_path, "w") as file:
    file.write(CodeHeader.header_definition(tlm))

###############################################################################
# Create source file
###############################################################################

# Create new source file
source_path = code_folder_path + '/telemetry.c'

# Create telemetry function definitions
with open(source_path, "w") as file:
    file.write(CodeSource.source_definition(tlm))
