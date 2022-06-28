# python3 Network_plot_traces.py save/traces/network-voltage-0.csv save/network-connect-synapse-file-0.hdf5

# Modified code from Johannes Hjorth, by Johanna Frost Nylen 2020-07-12

from snudda.utils.load_network_simulation import SnuddaLoadNetworkSimulation
import sys
import os
import numpy as np
from snudda.utils.load import SnuddaLoad
import re
import ntpath
import time
import neo
import elephant
import quantities as pq


class compareTraces:

    ############################################################################

    def __init__(self, fileNames, networkFiles=None, labels=None, colours=None):

        self.fileNames = dict()
        self.time = dict()
        self.spikeID = dict()
        self.labels = labels
        self.networkFiles = networkFiles
        self.time = dict()
        self.voltage = dict()
        self.colours = colours
        self.neuronNameRemap = {"FSN": "FS"}
        self.networkInfos = dict()

        simulations_i = 0

        for fileName in fileNames:
            self.fileNames.update({simulations_i: fileName})
            self.time.update({simulations_i: list()})
            self.spikeID.update({simulations_i: list()})
            simulations_i = simulations_i + 1

        for i, f in enumerate(fileNames):
            network_path = os.path.dirname(f)
            sns = SnuddaLoadNetworkSimulation(network_simulation_output_file=f, network_path=network_path)
            self.networkInfos.update({i: sns})

    def neuronName(self, neuronType):

        if neuronType in self.neuronNameRemap:
            return self.neuronNameRemap[neuronType]
        else:
            return neuronType

    ############################################################################

    def get_traces(self, neuronType):

        data = dict()

        for ctr, networkInfo in self.networkInfos.items():

            data.update({ctr: dict()})

            traceID = networkInfo.get_id_of_neuron_type(neuronType)

            for r in traceID:
                data[ctr].update({r: networkInfo.get_voltage(r).T[0]})

        return data

    def get_time(self):

        t = self.networkInfos[0].get_time()

        return t
if __name__ == "__main__":
    from plot import plot_dopamine_control

    current_folder = os.path.dirname(__file__)
    control = os.path.join(current_folder, "dopamine-trial-network", "simulation",
                           "network-voltage-DA-trial-control.hdf5")
    modulated = os.path.join(current_folder, "dopamine-trial-network", "simulation", "network-voltage-DA-trial.hdf5")

    network = os.path.join(current_folder, "dopamine-trial-network", "network-synapses.hdf5")

    kl = compareTraces(fileNames=[control, modulated],
                       networkFiles=network,
                       labels=["control", "DA"],
                       colours=["black", "red"])

    plot_dopamine_control(kl, type_cell="dSPN")
    plot_dopamine_control(kl, type_cell="iSPN")
    plot_dopamine_control(kl, type_cell="FSN")
