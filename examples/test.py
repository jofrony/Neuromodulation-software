import os
import argparse
args = argparse.Namespace()
args.action = "simulate"
args.disable_gj = False
args.exportCoreNeuron = False
args.input_file = None
args.mech_dir=None
args.network_file=None
args.neuromodulation=os.path.join("data", "modulation", "DA-ACh.json")
args.output_file=os.path.join("dopamine-acetylcholine-adaptive-trial-network", "simulation", "network-voltage-DA-ACh-trial.hdf5")
args.path="dopamine-acetylcholine-adaptive-trial-network"
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
