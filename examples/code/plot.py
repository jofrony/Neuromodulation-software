import numpy as np
import matplotlib.pyplot as plt
import os


def plot_dopamine_control(obj_loaded_traces, type_cell='dSPN', network_path=None):
    data_dict = obj_loaded_traces.get_traces(neuronType=type_cell)

    control = np.array([*data_dict[0].values()])

    da = np.array([*data_dict[1].values()])

    control_m = np.mean(control, axis=0)
    control_std = np.std(control, axis=0)

    da_m = np.mean(da, axis=0)
    da_std = np.std(da, axis=0)

    time = obj_loaded_traces.get_time() * 1e3

    for i in np.arange(len(da)):
        fig = plt.figure()
        ax = fig.add_subplot(111)
        ax.plot(time, control[i] * 1e3, c='black')
        ax.plot(time, da[i] * 1e3, c='red')
        ax.set_ylabel('Membrane potential (mV)')
        ax.set_xlabel('Time(ms)')

        ax.spines['right'].set_visible(False)
        ax.spines['top'].set_visible(False)
        ax.yaxis.set_ticks_position('left')
        ax.xaxis.set_ticks_position('bottom')
        ax.plot(np.arange(2500, 3000), np.ones_like(np.arange(2500, 3000)) * -75, c='black')
        ax.text(2500, -74, '500 ms')

        if max(da[i]) > 0:
            ax.set_ylim([-100, 40])
            ax.plot(2500 * np.ones_like(np.arange(-60, -40)), np.arange(-60, -40), c='black')
            ax.text(2550, -40, '20 mV')
        else:
            ax.set_ylim([-100, -50])
            ax.plot(2500 * np.ones_like(np.arange(-80, -75)), np.arange(-80, -75), c='black')
            ax.text(2550, -78, '5 mV')

        fig.savefig(os.path.join(network_path,'analysis','dopamine-control-traces' + str(i) + type_cell + ".svg"))

    plt.figure(0)

    plt.plot(time, control_m, c='black')
    plt.plot(time, da_m, c='red')
    plt.fill_between(time, control_m - control_std, control_m + control_std, alpha=.1, color='black')
    plt.fill_between(time, da_m - da_std, da_m + da_std, alpha=.1, color='red')

    plt.show()


def plot_dopamine_acetylcholine_control(obj_loaded_traces, type_cell='dSPN', network_path=None):
    data_dict = obj_loaded_traces.get_traces(neuronType=type_cell)

    control = np.array([*data_dict[0].values()])

    ach = np.array([*data_dict[1].values()])

    time = np.linspace(0, len(control[0]) * 0.5, len(control[0]))
    for i in np.arange(len(ach)):
        fig = plt.figure()
        ax = fig.add_subplot(111)
        ax.plot(time, control[i] * 1e3, c='black')
        ax.plot(time, ach[i] * 1e3, c='red')
        ax.set_ylabel('Membrane potential (mV)')
        ax.set_xlabel('Time(ms)')

        ax.spines['right'].set_visible(False)
        ax.spines['top'].set_visible(False)
        ax.yaxis.set_ticks_position('left')
        ax.xaxis.set_ticks_position('bottom')
        ax.plot(np.arange(2500, 3000), np.ones_like(np.arange(2500, 3000)) * -75, c='black')
        ax.text(2500, -74, '500 ms')

        if max(ach[i]) > 0:
            ax.set_ylim([-100, 40])
            ax.plot(2500 * np.ones_like(np.arange(-60, -40)), np.arange(-60, -40), c='black')
            ax.text(2550, -40, '20 mV')
        else:
            ax.set_ylim([-100, -50])
            ax.plot(2500 * np.ones_like(np.arange(-80, -75)), np.arange(-80, -75), c='black')
            ax.text(2550, -78, '5 mV')

        fig.savefig(os.path.join(network_path,'analysis', 'dopamine-acetylcholine-control-traces' + str(
            i) + type_cell + ".svg"))

    plt.show()
