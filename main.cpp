#include <iostream>

#include <signal_generate.h>
#include <windowing_filter.h>
#include <fft_autocorrelation_function.h>
#include <ring_shift_function.h>
#include <math_tools.h>

//! TODO Add plotters tomorrow for test
int main() {
    SignalGenerate gen_signals(new NoiseSignalFunction(1, 1, 0));
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

    // MathTools::addToPowerOfTwo(vec);
    for (auto i: vec) {
        std::cout << i << " ";
    }

    FFTAutoCorrelation abc(vec);
    abc.setPlotter(new Plotter(p_autocorr));
    abc.estimateSignals();


    return 0;
}
/*<<<<<<< autocorrelation
#include <fft_autocorrelation_function.h>
#include <math_tools.h>

int main()
{
    std::vector<double> zv = {1.0, 2.0, 3.0, 4.0, 5.0};
    MathTools::addToPowerOfTwo(zv);
    FFTAutoCorrelation zxc(zv);
    zxc.estimateSignals();
=======
*/