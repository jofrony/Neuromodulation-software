from snudda.neuromodulation.modulation_synapse import NeuromodulationSynapse

sw = NeuromodulationSynapse()
sw.set_weight(weight=1e-2)

# Acetylcholine

sw.set_connection_type(connector='concACh', neuromodulation_key='ACh')

sw.add_cell_modulation(neuromodulation_key='ACh',
                       cell='dSPN',
                       ion_channels={
                           "soma": ['kir_ms', 'cal12_ms', 'cal13_ms', 'can_ms', 'Im_ms'],
                           "dendrite": ['kir_ms', 'cal12_ms', 'cal13_ms'],
                           "axon": []},
                       receptors=["tmGabaA", "tmGlut"],
                       extrinsic=["CorticalBase", "CorticalSignal", "Thalamic"],
                       type_connection='spiking-concentration')

# Dopamine

sw.set_connection_type(connector='concDA', neuromodulation_key='DA')

sw.add_cell_modulation(neuromodulation_key='DA',
                       cell='dSPN',
                       ion_channels={
                           "soma": ["cal12_ms", "cal13_ms", "kir_ms", "kas_ms", "naf_ms", "can_ms"],
                           "dendrite": ["kir_ms", "kas_ms", "kaf_ms", "cal12_ms", "cal13_ms"],
                           "axon": []},
                       receptors={"tmGabaA": {"maxMod": 0.8},
                                  "tmGlut": {"maxMod_AMPA": 1.2,
                                             "maxMod_NMDA": 1.3,
                                             "failRate": 0.7}},
                       extrinsic=["CorticalBase", "CorticalSignal", "Thalamic"],
                       type_connection='spiking-concentration')

sw.save(dir_path='data/modulation', name='DA-ACh.json')
