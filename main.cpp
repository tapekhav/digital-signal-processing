#include <iostream>

#include <signal_generate.h>
#include <windowing_filter.h>
#include <fft_autocorrelation_function.h>
#include <ring_shift_function.h>
#include <math_tools.h>
#include <distribution_function.h>

//! TODO Add plotters tomorrow for test
int main() {
    SignalGenerate gen_signals(new SignalFunction(1, 1, 0));
    gen_signals.setPlotter(new Plotter(p_signal));

    auto vec = gen_signals.getSignals(0, 5, 0.02);

    for (auto i: vec) {
        std::cout << i << " ";
    }

    std::cout << "\n\n";

    WindowingFilter zxc(5);
    zxc.setPlotter(new Plotter(p_filter));

    auto res = zxc.smoothSignals(vec);

    for (auto i: res) {
        std::cout << i << " ";
    }

    for (auto i: vec) {
        std::cout << i << " ";
    }

    DistributionFunction aaa(vec, res);
    aaa.setPlotter(new Plotter(p_dist));

    aaa.getDistributionFunction();

    RingShiftFunction abc(vec);
    abc.setPlotter(new Plotter(p_autocorr));
    abc.estimateSignals();



    return 0;
}