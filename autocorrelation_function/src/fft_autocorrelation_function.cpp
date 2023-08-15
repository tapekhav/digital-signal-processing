#include <fft_autocorrelation_function.h>

#include <numeric>
#include <algorithm>
#include <iostream>

#include <math_tools.h>


//! Carefully with changing _signals
std::vector<double> FFTAutoCorrelation::estimateSignals()
{
    double meanValue = std::accumulate(_signals.begin(), _signals.end(), 0.0) / static_cast<double>(_signals.size());
    std::for_each(_signals.begin(), _signals.end(), [meanValue](double &value) { value -= meanValue; });

    //! Ф(t) ~ Re ifft (|fft(x)|^2)

    std::vector<ftype> fft = MathTools::FFT(MathTools::castToComplex(_signals));

    //! |fft(x)|^2 = Re^2_{x_i} + Im^2_{x_i}

    std::for_each(fft.begin(), fft.end(), [](ftype& value)
    {
        ftype copy(std::pow(value.real(), 2) + std::pow(value.imag(), 2));
        value = copy;
    });

    std::vector<ftype> ifft = MathTools::inverseFFT(fft);

    /*for (auto i : fft)
    {
        std::cout << "(" << i.real() << "; " << i.imag() << ")" << "\n";
    }*/

    std::vector<double> result;
    double k_prop = ifft.at(0).real();
    for (auto i : ifft)
    {
        result.push_back(i.real() / k_prop);
        _plt->addPoint(result.back());
    }

    return result;
}
