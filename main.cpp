#include <fft_autocorrelation_function.h>
#include <math_tools.h>

int main()
{
    std::vector<double> zv = {1.0, 2.0, 3.0, 4.0, 5.0};
    MathTools::addToPowerOfTwo(zv);
    FFTAutoCorrelation zxc(zv);
    zxc.estimateSignals();

    return 0;
}