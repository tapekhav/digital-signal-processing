import sys
import matplotlib.pyplot as plt


def read_data(filename):
    with open(filename, 'r') as file:
        data = file.read().split('\n')
    return [float(x) for x in data if x != '']


def read_data_dist(filename):
    with open(filename, 'r') as file:
        data = file.read().split('\n')
    return data


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
        self.plotter_filter = Plotter(3)
        self.plotter_autocorr = Plotter(4)
        self.plotter_dist = None

    def set_signal_plotter(self, data):
        self.plotter_signal.launch_plotter(data, 'aa', 'Signal', 'value')

    def __split_file(self, data):
        data1, data2 = [], []

        for i in data:

            arr = i.split(' ')
            if arr[0] != '':
                data1.append(float(arr[0]))
                data2.append(float(arr[1]))

        return data1, data2

    def set_dist_plotter(self, data: list):
        self.plotter_dist = Plotter(2)  # Create the dist plotter
        data1, data2 = self.__split_file(data)
        self.plotter_dist.ax.scatter(data2, data1, marker='o')
        self.plotter_dist.ax.set_title('Distribution function')

    def set_filter_plotter(self, data):
        self.plotter_filter.launch_plotter(data, 'a', 'Windowing filter', 'b')

    def set_autocorr_plotter(self, data):
        self.plotter_autocorr.launch_plotter(data, 'a', 'Autocorrelation function', 'b')

    def set_all_plotters(self, data_signal, data_filter, data_autocorr):
        self.set_signal_plotter(data_signal)
        self.set_filter_plotter(data_filter)
        self.set_autocorr_plotter(data_autocorr)
        self.plotter_dist = None


def main():
    if len(sys.argv) < 5:
        print("Usage: python3 script.py <signal_file> <dist_file> <filter_file> <autocorr_file>")
        return

    signal_data = read_data(sys.argv[1])
    dist_data = read_data_dist(sys.argv[2])
    filter_data = read_data(sys.argv[3])
    autocorr_data = read_data(sys.argv[4])

    graphics = InitClass()
    graphics.set_all_plotters(signal_data, filter_data, autocorr_data)
    graphics.set_dist_plotter(dist_data)

    plt.show()


if __name__ == '__main__':
    main()
