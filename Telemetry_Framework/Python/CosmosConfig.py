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

def define_server_file(config):
    contents = f'INTERFACE {config["target_name"].upper()}_INT udp_interface.rb '
    contents += f'{config["target_ip"]} {config["udp_write_port"]} {config["udp_read_port"]}\n'
    return contents + f'  TARGET {config["target_name"]}\n'

def generate_telemetry_header(config):
    return f'TELEMETRY {config["target_name"].upper()} {config["packet_name"].upper()} BIG_ENDIAN\n'