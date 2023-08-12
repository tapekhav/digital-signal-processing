import sys

import matplotlib.pyplot as plt
from typing import NoReturn


# TODO check plotter classes again
class Plotter:
    def __init__(self, number: int):
        self.__fig, self.__ax = plt.plot(figsize=(8, 10))
        self.__arr_values = list()
        self.__number = number

    def __read(self, data) -> list:
        return [float(x) for x in data if x == '']

    def set_values(self) -> NoReturn:
        data = open(sys.argv[self.__number], 'r').read().split('\n')
        self.__arr_values = self.__read(data)

    def launch_plotter(self, label: str, title: str, y_label: str) -> NoReturn:
        self.__ax.plot(self.__arr_values, lavel=label)
        self.__ax.set_title(title)
        self.__ax.set_ylabel(y_label)
        self.__ax.legend()
        plt.show()


class InitClass:
    def __init__(self):
        self.__plotter_signal = Plotter(1)
        self.__plotter_dist = Plotter(2)
        self.__plotter_standard_autocorr = Plotter(3)
        self.__plotter_fft_autocorr = Plotter(4)

    def set_signal_plotter(self) -> NoReturn:
        self.__plotter_signal.set_values()
        self.__plotter_signal.launch_plotter('', 'Signal', '')

    def set_dist_plotter(self) -> NoReturn:
        self.__plotter_dist.set_values()
        self.__plotter_dist.launch_plotter('', 'Distribution function', '')

    def set_standard_autocorr_plotter(self) -> NoReturn:
        self.__plotter_standard_autocorr.set_values()
        self.__plotter_standard_autocorr.launch_plotter('', 'Standard autocorrelation function', '')

    def set_fft_autocorr_plotter(self) -> NoReturn:
        self.__plotter_fft_autocorr.set_values()
        self.__plotter_fft_autocorr.launch_plotter('', 'FFT autocorrelation function', '')

    # check this function
    def set_all_plotters(self) -> NoReturn:
        self.set_signal_plotter()
        self.set_dist_plotter()
        self.set_standard_autocorr_plotter()
        self.set_fft_autocorr_plotter()


def main():
    graphics = InitClass()
    graphics.set_all_plotters()


if __name__ == '__main__':
    main()
