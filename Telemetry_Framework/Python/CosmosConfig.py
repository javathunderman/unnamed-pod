###############################################################################
#  Project: UMDLoop
#  Module: CosmosConfig
#  File: CosmosConfig.py
###############################################################################
#  Purpose:
#
#     This class will store configuration values for COSMOS target
#     generation, which are pulled from the specified file using yaml format.
###############################################################################
#  Change History:
#
#    Author      Date      Description of Change
#  ----------  --------  --------------------------------------------------
#  Ryan W.     10-03-18  Initial version.
###############################################################################

import yaml


def generate_config():
    with open("../cosmos_config.yaml") as f:
        config = yaml.safe_load(f)
    return config