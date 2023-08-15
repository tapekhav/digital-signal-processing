import sys
import matplotlib.pyplot as plt


def read_data(filename):
    with open(filename, 'r') as file:
        data = file.read().split('\n')
    return [float(x) for x in data if x != '']


class Plotter:
    def __init__(self, number):
        self.fig, self.ax = plt.subplots(figsize=(10, 10))
        self.number = number

    def launch_plotter(self, data, label, title, y_label):
        self.ax.plot(data, label=label)
        self.ax.set_title(title)
        self.ax.set_ylabel(y_label)
        self.ax.legend()


class InitClass:
    def __init__(self):
        self.plotter_signal = Plotter(1)
        self.plotter_dist = Plotter(2)
        self.plotter_filter = Plotter(3)
        self.plotter_autocorr = Plotter(4)

    def set_signal_plotter(self, data):
        self.plotter_signal.launch_plotter(data, '', 'Signal', 'value')

    def set_dist_plotter(self, data):
        self.plotter_dist.launch_plotter(data, 'a', 'Distribution function', 'b')

    def set_filter_plotter(self, data):
        self.plotter_filter.launch_plotter(data, 'a', 'Windowing filter', 'b')

    def set_autocorr_plotter(self, data):
        self.plotter_autocorr.launch_plotter(data, 'a', 'Autocorrelation function', 'b')

    def set_all_plotters(self, data_signal, data_dist, data_filter, data_autocorr):
        self.set_signal_plotter(data_signal)
        self.set_dist_plotter(data_dist)
        self.set_filter_plotter(data_filter)
        self.set_autocorr_plotter(data_autocorr)

        plt.show()


def main():
    if len(sys.argv) < 5:
        print("Usage: python script.py <signal_file> <dist_file> <filter_file> <autocorr_file>")
        return

    signal_data = read_data(sys.argv[1])
    dist_data = read_data(sys.argv[2])
    filter_data = read_data(sys.argv[3])
    autocorr_data = read_data(sys.argv[4])

    graphics = InitClass()
    graphics.set_filter_plotter(filter_data)
    graphics.set_all_plotters(signal_data, dist_data, filter_data, autocorr_data)


if __name__ == '__main__':
    main()
