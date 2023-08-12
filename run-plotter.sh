#!/bin/bash

python_file=plotters/plotter.py
signal=plotters/files/signal.txt
dist=plotters/files/distribution_function.txt
autocorr_standard=plotters/files/autocorrelation_standard.txt
autocorr_fft=plotters/files/autocorrelation_fft.txt

python3 $python_file $signal $dist $autocorr_standard $autocorr_fft