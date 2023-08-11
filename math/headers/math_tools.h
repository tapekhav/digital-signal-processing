#ifndef DIGITAL_SIGNAL_PROCESSING_MATH_TOOLS_H
#define DIGITAL_SIGNAL_PROCESSING_MATH_TOOLS_H

#include <vector>
#include <cmath>
#include <complex>
#include <numeric>
#include <iterator>

using ftype = std::complex<double>;

class MathTools
{
public:
    static double meanValue(const std::vector<double>& values, long size);

    static double dispersion(const std::vector<double>& array);

    static inline double rootMeanSquare(const std::vector<double>& array) { return std::sqrt(dispersion(array)); }

    static std::vector<ftype> iterativeFFT(const std::vector<ftype>& values);

    static std::vector<ftype> castToComplex(const std::vector<double>& array);
private:
    static uint32_t bit_reverse(uint32_t num, int bits);

    static void bit_reverse_copy(const std::vector<ftype>& values, std::vector<ftype>& A);
};

#endif //DIGITAL_SIGNAL_PROCESSING_MATH_TOOLS_H
