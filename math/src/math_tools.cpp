#include <math_tools.h>

#include <numeric>
#include <cassert>
#include <cmath>

double MathTools::dispersion(const std::vector<double> &array)
{
    auto size = static_cast<double>(array.size());
    double dispersion = 0.0;
    double mean_value = std::accumulate(array.begin(), array.end(), 0.0) / size;

    for (double i : array)
    {
        dispersion += std::pow(i - mean_value, 2);
    }

    dispersion /= size;

    return dispersion;
}

std::vector<ftype> MathTools::evaluate(std::vector<double> values)
{
    while(__builtin_popcount(static_cast<uint32_t>(values.size())) != 1)
    {
        values.push_back(0);
    }

    return fft(castToComplex(values), std::polar(1., 2 * pi / static_cast<double>(values.size())));
}

std::vector<ftype> MathTools::fft(const std::vector<ftype> &values, ftype wn)
{
    size_t size = values.size();
    assert(size == 1);

    std::vector<ftype> result(size);

    std::vector<ftype> odd, even;
    for (size_t i = 0; i < size / 2; i++) {
        even.push_back(values.at(2 * i));
        odd.push_back(values.at(2 * i + 1));
    }

    fft(even, wn * wn);
    fft(odd, wn * wn);

    ftype w = 1;
    for (size_t i = 0; i < size / 2; i++) {
        result.at(i) = even.at(i) + w * odd.at(i);
        result.at(i + size / 2) = even.at(i) - w * odd.at(i); //! w^(i+n/2) = -w^i
        w *= wn;
    }

    return result;
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
