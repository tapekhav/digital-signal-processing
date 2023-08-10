#ifndef DIGITAL_SIGNAL_PROCESSING_MATH_TOOLS_H
#define DIGITAL_SIGNAL_PROCESSING_MATH_TOOLS_H

#include <vector>
#include <cmath>
#include <complex>
#include <numeric>
#include <iterator>

using ftype = std::complex<double>;
static const double pi = acos(-1);

class MathTools
{
public:
    static double meanValue(const std::vector<double>& values, long size);

    static double dispersion(const std::vector<double>& array);

    static inline double rootMeanSquare(const std::vector<double>& array) { return std::sqrt(dispersion(array)); }

    static std::vector<ftype> fft(const std::vector<ftype>& values, ftype wn);

    static std::vector<ftype> castToComplex(const std::vector<double>& array);
private:
    std::vector<ftype> evaluate(std::vector<double> values);
};

#endif //DIGITAL_SIGNAL_PROCESSING_MATH_TOOLS_H
