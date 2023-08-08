#ifndef DIGITAL_SIGNAL_PROCESSING_MATH_TOOLS_H
#define DIGITAL_SIGNAL_PROCESSING_MATH_TOOLS_H

#include <vector>
#include <cmath>
#include <complex>

using ftype = std::complex<double>;
static const double pi = acos(-1);

class MathTools
{
public:
    static double dispersion(const std::vector<double>& array);

    static std::vector<ftype> fft(const std::vector<ftype>& values, ftype wn);
private:
    std::vector<ftype> evaluate(std::vector<double> values);

    static std::vector<ftype> castToComplex(const std::vector<double>& array);
};

#endif //DIGITAL_SIGNAL_PROCESSING_MATH_TOOLS_H
