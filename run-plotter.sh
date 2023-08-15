#!/bin/bash

python_file=plotters/plotter.py
signal=plotters/files/signal.txt
dist=plotters/files/distribution_function.txt
filter=plotters/files/filter.txt
autocorr=plotters/files/autocorrelation.txt

python3 $python_file $signal $dist $filter $autocorr