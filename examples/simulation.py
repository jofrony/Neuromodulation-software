from snudda.neuromodulation.neuromodulation import SnuddaSimulateNeuromodulation
import timeit
import os
import sys
import json
import pathlib


network_path =  sys.argv[1]
network_file = os.path.join(network_path, "network-synapses.hdf5")
input_file = os.path.join(network_path, "input-spikes.hdf5")
path = pathlib.Path(os.path.join(network_path, "simulation"))

neuromodulation = json.load(open(sys.argv[2],'r'))

t_sim = int(sys.argv[3])
path.mkdir(parents=True, exist_ok=True)
save_dir = os.path.join(os.path.dirname(network_file), "simulation")
name = sys.argv[4]
volt_file = os.path.join(save_dir, f"network-voltage-{name}.csv")
spikes_file = os.path.join(save_dir, f"network-output-spikes-{name}.txt")
log_file = os.path.join(os.path.dirname(network_file), "log", "network-simulation-log.txt")
disable_gj = False





start = timeit.default_timer()
sim = SnuddaSimulateNeuromodulation(network_file=network_file,
                            input_file=input_file,
                            disable_gap_junctions=disable_gj,
                            log_file=log_file)

sim.load_network_info(network_file)
sim.check_memory_status()
sim.distribute_neurons()
sim.setup_neurons()
sim.check_memory_status()
sim.pc.barrier()

sim.connect_network()
sim.check_memory_status()
sim.pc.barrier()

sim.add_external_input()

sim.apply_neuromodulation(neuromodulation)
sim.neuromodulation_network_wide()

sim.check_memory_status()

sim.add_recording(side_len=None) 
sim.check_memory_status()
sim.run(t_sim) 
sim.write_spikes(spikes_file)
sim.write_voltage(volt_file)
stop = timeit.default_timer()
if sim.pc.id() == 0:
    print("Program run time: " + str(stop - start))
