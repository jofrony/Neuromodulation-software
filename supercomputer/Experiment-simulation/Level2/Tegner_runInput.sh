#!/bin/bash -l

SNUDDA_DIR=/cfs/klemming/nobackup/${USER:0:1}/$USER/Snudda/snudda
NEUROMODSOFT=/cfs/klemming/nobackup/${USER:0:1}/$USER/BasalGangliaExperiments/Neuromodulation-software/
DOPAMINELEVELONE=$NEUROMODSOFT/supercomputer/Experiment-simulation/Level2/
JOBDIR=$DOPAMINELEVELONE/pdc_network
PROJECT_CODE=$NEUROMODSOFT/network-wide-code/project_wide

mkdir -p $JOBDIR

if [ $SLURM_PROCID -gt 0 ]; then
	mock_string="Not main process"

else

    # For debug purposes:                                                         
    echo "PATH: "$PATH
    echo "IPYTHONDIR: "$IPYTHONDIR
    echo "PYTHONPATH: "$PYTHONPATH
    echo "LD_LIBRARY_PATH: "$LD_LIBRARY_PATH

    echo ">>>>>> Main process starting ipcluster"
    echo

    echo "Start time: " > start_time_network_connect.txt
    date >> start_time_network_connect.txt

    echo "SLURM_NODELIST = $SLURM_NODELIST"
    
   
    /sbin/ifconfig ib0 | head -n 2 | tail -n 1 | awk '{print $2}' > controller_ip.txt
    CONTROLLERIP=$(<controller_ip.txt)

    let NWORKERS="$SLURM_NTASKS - 1"

    echo ">>> NWORKERS " $NWORKERS
    echo ">>> Starting ipcluster `date`"
    
    #.. Start the ipcluster
    ipcluster start -n ${NWORKERS} \
	      --ip=${CONTROLLERIP} \
	      --location=${CONTROLLERIP} \
	      --profile=${IPYTHON_PROFILE} \
	      --engines=MPIEngineSetLauncher --debug \
	      --HeartMonitor.max_heartmonitor_misses=1000 \
	      --HubFactory.registration_timeout=600 \
	      --HeartMonitor.period=10000 &

    #.. Sleep to allow engines to start
    echo ">>> Wait 120s to allow engines to start"
    sleep 120 #60
 
    cp -a $NEUROMODSOFT/network_parameters/external_input/external-input-dSTR-scaled-level2.json ${JOBDIR}/input.json

    snudda input ${JOBDIR} --parallel --time 5

    ipcluster stop	

    date
    echo "JOB END "`date` start_time_network_connect.txt

fi


