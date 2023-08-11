#ifndef DIGITAL_SIGNAL_PROCESSING_MATH_TOOLS_H
#define DIGITAL_SIGNAL_PROCESSING_MATH_TOOLS_H

#include <vector>
#include <cmath>
#include <complex>
#include <numeric>
#include <iterator>

//! Complex number type
using ftype = std::complex<double>;


/*! \class MathTools
*   \brief Contains math methods
*/
class MathTools
{
public:
    //! Count mean value in array
    static double meanValue(const std::vector<double>& values, long size);
    //! Calculates dispersion of sequence
    static double dispersion(const std::vector<double>& array);
    //! Finds root mean square
    static inline double rootMeanSquare(const std::vector<double>& array) { return std::sqrt(dispersion(array)); }
    //! Implements iterative Fast Fourier Transform
    static std::vector<ftype> iterativeFFT(const std::vector<ftype>& values);
    //! Implements inverse Fast Fourier Transform
    static void inverseFFT(std::vector<ftype>& values);
    //! Casts to complex number
    static std::vector<ftype> castToComplex(const std::vector<double>& array);
    //! Adds array size to power of two
    static void addToPowerOfTwo(std::vector<double>& values);
private:
    //! Finds number with reverse bits
    static uint32_t bit_reverse(uint32_t num, int bits);
    //! Creates array with all bir reverse numbers
    static void bit_reverse_copy(const std::vector<ftype>& values, std::vector<ftype>& A);
};

#endif //DIGITAL_SIGNAL_PROCESSING_MATH_TOOLS_H
