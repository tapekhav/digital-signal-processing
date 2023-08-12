#include <iostream>

#include <signal_generate.h>
#include <windowing_filter.h>


//! TODO Add plotters tomorrow for test
int main() {
    SignalGenerate gen_signals(new SignalFunction(1, 1, 0));

    auto vec = gen_signals.getSignals(0, 1, 0.01);

    for (auto i: vec) {
        std::cout << i << " ";
    }

    std::cout << "\n\n";

    WindowingFilter zxc(5);

    auto res = zxc.smoothSignals(vec);

    for (auto i: res) {
        std::cout << i << " ";
    }

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