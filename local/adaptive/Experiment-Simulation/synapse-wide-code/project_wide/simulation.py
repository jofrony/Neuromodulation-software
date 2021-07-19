from mpi4py import MPI  # This must be imported before neuron, to run parallel
from neuron import h  # , gui
import timeit
import os
import sys
import pathlib
from snudda.neuromodulation.neuromodulation_synapse import SnuddaSimulateNeuromodulationSynapse
import json
import snudda
from snudda.neuromodulation.measure_neuromodulation import MeasureNeuromodulation

network_path = sys.argv[1]

network_file = os.path.join(network_path, "network-synapses.hdf5")
input_file = os.path.join(network_path, "input-spikes.hdf5")
path = pathlib.Path(os.path.join(network_path, "simulation"))


name = sys.argv[5]

path.mkdir(parents=True, exist_ok=True)
save_dir = os.path.join(os.path.dirname(network_file), "simulation")
slurm_id = str(666)
volt_file = os.path.join(save_dir, f"network-voltage-{name}.csv")
gpcr_file = os.path.join(save_dir, f"gpcr-{name}.csv")
check_file = os.path.join(save_dir, f"check-{name}.csv")
spikes_file = os.path.join(save_dir, f"network-output-spikes-{name}.txt")
log_file = os.path.join(os.path.dirname(network_file), "log", "network-simulation-log.txt")
disable_gj = True
t_sim = int(sys.argv[4])
name_modulator = os.path.abspath(sys.argv[2])
neuromodulator = json.load(open(name_modulator))

conductance = float(sys.argv[3])

start = timeit.default_timer()
pc = h.ParallelContext()
sim = SnuddaSimulateNeuromodulationSynapse(network_file=network_file,
                                           input_file=input_file,
                                           disable_gap_junctions=disable_gj,
                                           log_file=log_file,
                                           neuromodulator_description=neuromodulator)
sim.setup()
sim.add_external_input()
mn = MeasureNeuromodulation(sim)
sim.add_recording(side_len=None)
mn.recording_gpcr()
stop = timeit.default_timer()
if sim.pc.id() == 0:
    print("Program run time: " + str(stop - start))
start = timeit.default_timer()
sim.run(t_sim)
sim.write_spikes(spikes_file)
sim.write_voltage(volt_file)


mn.write_gpcr_synapses(gpcr_file)
mn.check_mod(check_file)

stop = timeit.default_timer()
if sim.pc.id() == 0:
    print("Program run time: " + str(stop - start))
