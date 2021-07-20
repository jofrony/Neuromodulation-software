# python3 Network_plot_traces.py save/traces/network-voltage-0.csv save/network-connect-synapse-file-0.hdf5

# Modified code from Johannes Hjorth, by Johanna Frost Nylen 2020-07-12


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

class compareTraces():

  ############################################################################
  
  def __init__(self, fileNames, networkFiles=None,labels=None,colours=None):

    self.fileNames = dict()
    self.time = dict()
    self.spikeID = dict()
    self.labels = labels
    self.networkFiles = networkFiles
    self.time = dict()
    self.voltage = dict()
    self.colours = colours
    self.neuronNameRemap = {"FSN": "FS"}

    simulations_i = 0
    
    for fileName in fileNames:
      self.fileNames.update({simulations_i : fileName})
      self.time.update({simulations_i : list()})
      self.spikeID.update({simulations_i : list()})
      simulations_i = simulations_i + 1
      
    self.readCSV()
    self.networkInfos = dict()
    try:
      self.ID = int(re.findall('\d+', ntpath.basename(fileName))[0])
    except:
      print("Unable to guess ID, using 666.")
      self.ID = 666
    self.networkInfos = dict()
    simulations_i = 0
    if(type(networkFiles) is not list):
      networkFile = networkFiles
      for r in range(len(fileNames)):
        self.networkInfos.update({simulations_i: SnuddaLoad(networkFile)})
        simulations_i = simulations_i + 1
    elif(type(networkFiles) is list):
      
      for networkFile in networkFiles:
        self.networkInfos.update({simulations_i: SnuddaLoad(networkFile)})
        simulations_i = simulations_i + 1

    else:
      self.networkInfo = None
  ############################################################################
    
  def readCSV(self):

    i = 0

    for fileName in self.fileNames.values():
      data = np.genfromtxt(fileName, delimiter=',')
      assert(data[0,0] == -1) # First column should be time

      self.time[i] = data[0,1:] / 1e3

      self.voltage[i] = dict()
    
      for rows in data[1:,:]:
        cID = int(rows[0])
        self.voltage[i][cID] = rows[1:] * 1e-3
      i=i+1      
  ############################################################################

  def neuronName(self,neuronType):

    if(neuronType in self.neuronNameRemap):
      return self.neuronNameRemap[neuronType]
    else:
      return neuronType

  ############################################################################

  def get_traces(self,neuronType):

    data = dict()

    for ctr,networkInfo in self.networkInfos.items():

      data.update({ctr : dict()})
      neuronTypes = [x["type"] for x in networkInfo.data["neurons"]]

      # Find numbers of the relevant neurons
    
      traceID = [x[0] for x in enumerate(neuronTypes) if x[1] == neuronType]

      timeIdx = range(0,len(self.time))


      for r in traceID:

        data[ctr].update({r : self.voltage[ctr][r]})

    return data
        
  
  
