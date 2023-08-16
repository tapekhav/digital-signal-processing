#include <math_tools.h>

#include <fftw3.h>

double MathTools::dispersion(const std::vector<double> &array)
{
    double dispersion = 0.0;
    double mean_value = meanValue(array, array.size());

    for (double i : array)
    {
        dispersion += std::pow(i - mean_value, 2);
    }

    dispersion /= static_cast<double>(array.size());

    return dispersion;
}

std::vector<ftype> MathTools::castToComplex(const std::vector<double> &array)
{
    std::vector<ftype> result;
    for (auto i : array)
    {
        result.emplace_back(i);
    }

    return result;
}

double MathTools::meanValue(const std::vector<double> &values, size_t size)
{
    return std::accumulate(values.begin(), values.end(), 0.0) / static_cast<double>(size);
}


std::vector<ftype> MathTools::inverseFFT(std::vector<ftype> values)
{
    int size = static_cast<int>(values.size());
    std::vector<ftype> result(values.size());

    fftw_plan backward_plan = fftw_plan_dft_1d(size,
                              reinterpret_cast<fftw_complex*>(const_cast<std::complex<double>*>(&values.at(0))),
                              reinterpret_cast<fftw_complex*>(&result.at(0)),
                              FFTW_BACKWARD, FFTW_ESTIMATE);

    fftw_execute(backward_plan);

    fftw_destroy_plan(backward_plan);

    return result;
}

std::vector<ftype> MathTools::FFT(std::vector<ftype> values)
{
    int size = static_cast<int>(values.size());
    std::vector<ftype> result(values.size());

    fftw_plan forward_plan = fftw_plan_dft_1d(size, reinterpret_cast<fftw_complex*>(const_cast<std::complex<double>*>(&values.at(0))),
                                                    reinterpret_cast<fftw_complex*>(&result.at(0)),
                                                    FFTW_FORWARD, FFTW_ESTIMATE);

    fftw_execute(forward_plan);

    fftw_destroy_plan(forward_plan);

    return result;
}