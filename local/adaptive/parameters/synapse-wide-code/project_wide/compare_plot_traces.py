
# Modified code from Johannes Hjorth, by Johanna Frost Nylen 2020-07-12


import sys
import os
import numpy as np
from snudda.utils.load import SnuddaLoad
import re
import ntpath
import time
import matplotlib.pyplot as plt

class comparePlotTraces():

  ############################################################################
  
  def __init__(self,fileNames,networkFiles=None,labels=None,colours=None,save_dir=None):

    self.fileNames = dict()
    self.time = dict()
    self.spikeID = dict()
    self.labels = labels
    self.networkFiles = networkFiles
    self.time = dict()
    self.voltage = dict()
    self.colours = colours
    self.neuronNameRemap = {"FSN" : "FS"}
    self.save_dir = save_dir

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
  
  
  def plotTraces(self,traceID=None,offset=150e-3,colours=None,skipTime=None,
                 title=None,fig=None,ctr=None):

    chosenColor = self.colours
    
    if(colours is None):
      colours = {"dSPN" : (77./255,151./255,1.0),
                 "iSPN" : (67./255,55./255,181./255),
                 "FSN" : (6./255,31./255,85./255),
                 "ChIN" : [252./255,102./255,0],
                 "LTS" : [150./255,63./255,212./255]}


    networkInfo=self.networkInfos[ctr]

    typesInPlot = set()

    if(networkInfo is not None):
      cellTypes = [n["type"] for n in networkInfo.data["neurons"]]
      cellIDcheck = [n["neuronID"] for n in networkInfo.data["neurons"]]

    cols = [colours[c] if c in colours else [0,0,0] for c in cellTypes]


    ofs = 0

    if(skipTime is not None):
      timeIdx = np.where(self.time[ctr] >= skipTime)[0]



    else:
      skipTime = 0.0
      timeIdx = range(0,len(self.time))

    plotCount = 0

    for r in traceID:

      if(r not in self.voltage[ctr]):
        print("Missing data for trace " + str(r))
        continue


      plotCount += 1
      typesInPlot.add(networkInfo.data["neurons"][r]["type"])

      if(colours is None or networkInfo is None):
        colour = "black"
      else:
        try:
          colour = cols[r]
        except:
          import traceback
          tstr = traceback.format_exc()
          print(tstr)
          import pdb
          pdb.set_trace()


      plt.plot(self.time[ctr][timeIdx]-skipTime,\
               (self.voltage[ctr][r][timeIdx] + ofs)*1e3,\
               color=chosenColor[ctr])
      ofs += offset

       
      



  ############################################################################

  def plotTraceNeuronType(self,neuronType,nTraces=10,offset=0,skipTime=0.0):
    
    assert self.networkInfos is not None, "You need to specify networkInfo file"

    fig = plt.figure()

    for dictIndx,networkInfo in self.networkInfos.items():
      neuronTypes = [x["type"] for x in networkInfo.data["neurons"]]

      # Find numbers of the relevant neurons
    
      traceID = [x[0] for x in enumerate(neuronTypes) if x[1] == neuronType]
    
      nTraces = min(len(traceID),nTraces)

      if(nTraces <= 0):
        print("No traces of " + str(neuronType) + " to show")
        return
     
      self.plotTraces(offset=offset,traceID=traceID[:nTraces],skipTime=skipTime,fig=fig,ctr=dictIndx)

    plt.xlabel('Time (s)')
    plt.ylabel('Membrane potential (mV)')
    title = self.neuronName(neuronType)

    if (title is not None):
      plt.title(title)

    if (offset != 0):
      ax = fig.axes[0]
      ax.set_yticklabels([])
    plt.legend()
    plt.tight_layout()

    figPath = os.path.dirname(self.save_dir) + "/figs"
    if (not os.path.exists(figPath)):
      os.makedirs(figPath)


    figName = figPath + '/Network-spikes-' + str(self.ID) \
              + "-" + title + "-colour.svg"

    plt.savefig(figName,
                dpi=300)
    print("Saving to figure " + str(figName))
    time.sleep(1)
    
  ############################################################################
    
if __name__ == "__main__":

  print('Main')
