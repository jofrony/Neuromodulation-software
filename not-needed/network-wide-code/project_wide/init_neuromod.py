from project_wide.neuromodulationInit import neuromodulationInit
from collections import OrderedDict
import os
import sys

print(sys.argv)
neuron_data_folder = sys.argv[1]
neurons_dir = os.path.abspath(neuron_data_folder)
print(neurons_dir)
network_path = sys.argv[2]
config_name= network_path + "/network-config.json"


cnc = neuromodulationInit(config_file=config_name,random_seed=12345)

cnc.define_striatum_neuromodulation(num_dSPN=5000,num_iSPN=5000,num_FS=100,volume_type="cube",neurons_dir=neurons_dir)  
dirName = os.path.dirname(config_name)

if not os.path.exists(dirName):
    os.makedirs(dirName)

cnc.write_json(config_name)

