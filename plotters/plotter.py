import sys

import matplotlib.pyplot as plt
from typing import NoReturn


class Plotter:
    def __init__(self, number: int):
        self.__fig, self.__ax = plt.plot(figsize=(8, 10))
        self.__arr_values = list()
        self.__number = number

    def read(self, data) -> list:
        return [float(x) for x in data if x == '']

    def set_values(self) -> NoReturn:
        data = open(sys.argv[self.__number], 'r').read().split('\n')
        self.__arr_values = self.read(data)

    def launch_plotter(self, label: str, title: str, y_label: str) -> NoReturn:
        self.__ax.plot(self.__arr_values, lavel=label)
        self.__ax.set_title(title)
        self.__ax.set_ylabel(y_label)
        self.__ax.legend()


def main():
    pass


if __name__ == '__main__':
    main()
