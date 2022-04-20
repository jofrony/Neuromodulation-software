import os
import argparse
args = argparse.Namespace()
args.action = "simulate"
args.disable_gj = False
args.exportCoreNeuron = False
args.input_file = None
args.mech_dir=None
args.network_file=None
args.neuromodulation=os.path.join("data", "modulation", "dopamine_modulation.json")
args.output_file=os.path.join("dopamine-trial-network", "simulation", "network-voltage-DA-trial.hdf5")
args.path="dopamine-trial-network"
args.profile=False
args.randomseed=None
args.record_all=None
args.record_volt=True
args.time= 3.0
args.verbose=False

from snudda.core import Snudda
os.environ["SNUDDA_DATA"] = "data"
s = Snudda(network_path=args.path)
s.simulate(args=args)


os.system("mpiexec -n 4 snudda simulate dopamine-trial-network --time 3.0 --outputFile 'dopamine-trial-network/simulation/network-voltage-DA-trial.hdf5' --neuromodulation data/modulation/dopamine_modulation.json")