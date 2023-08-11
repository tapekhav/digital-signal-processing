#include <fft_autocorrelation_function.h>

#include <numeric>
#include <algorithm>

#include <math_tools.h>


//! Carefully with changing _signals
std::vector<double> FFTAutoCorrelation::estimateSignals()
{
    double meanValue = std::accumulate(_signals.begin(), _signals.end(), 0.0) / static_cast<double>(_signals.size());
    std::for_each(_signals.begin(), _signals.end(), [meanValue](double &value) { value -= meanValue; });

    //! Ф(t) ~ Re ifft (|fft(x)|^2)

    std::vector<ftype> fft = MathTools::iterativeFFT(MathTools::castToComplex(_signals));

    //! |fft(x)|^2 = Re^2_{x_i} + Im^2_{x_i}

    std::for_each(fft.begin(), fft.end(), [](ftype& value)
    {
        ftype copy(std::pow(value.real(), 2) + std::pow(value.imag(), 2));
        value = copy;
    });

    fft = MathTools::inverseFFT(fft);

    std::vector<double> result;
    double k_prop = fft.at(0).real();
    for (auto i : fft)
    {
        result.push_back(i.real() / k_prop);
    }

    return result;
}
