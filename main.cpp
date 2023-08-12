/*<<<<<<< filter
#include <iostream>

#include <signal_generate.h>
#include <windowing_filter.h>

int main()
{
    SignalGenerate gen_signals(new SignalFunction(1, 1, 0));

    auto vec = gen_signals.getSignals(0, 1, 0.01);

    for (auto i : vec)
    {
        std::cout << i << " ";
    }

    std::cout << "\n\n";

    WindowingFilter zxc(5);

    auto res = zxc.smoothSignals(vec);

    for (auto i : res)
    {
        std::cout << i << " ";
    }
=======
*/
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
#include <iostream>
// #include <signal_generate.h>

int main()
{
    /*
    auto* plt = new Plotter(PATH);
    SignalGenerate zxc(new NoiseSignalFunction(1, 1, 0));
    zxc.setPlotter(plt);

    zxc.getSignals(0, 5, 0.01);
    */
    return 0;
}