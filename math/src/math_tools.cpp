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

/*
std::vector<ftype> MathTools::evaluate(std::vector<double> values)
{
    while(__builtin_popcount(static_cast<uint32_t>(values.size())) != 1)
    {
        values.push_back(0);
    }

    return fft(castToComplex(values), std::polar(-1., 2 * M_PI / static_cast<double>(values.size())));
}

std::vector<ftype> MathTools::fft(const std::vector<ftype> &values, ftype wn)
{
    size_t size = values.size();
    if (size == 1)
    {
        return {};
    }


    std::vector<ftype> odd, even;
    for (size_t i = 0; i < size / 2; i++)
    {
        even.push_back(values.at(2 * i));
        odd.push_back(values.at(2 * i + 1));
    }

    even = fft(even, wn);
    odd = fft(odd, wn);


    std::vector<ftype> result(size);
    for (size_t i = 0; i < size / 2; i++)
    {
        result.at(i) = even.at(i) + wn * odd.at(i);
        result.at(i + size / 2) = even.at(i) - wn * odd.at(i); //! w^(i+n/2) = -w^i
    }

    return result;
}


uint32_t MathTools::bit_reverse(uint32_t num, int bits)
{
    uint32_t reversed = 0;
    for (int i = 0; i < bits; ++i)
    {
        reversed = (reversed << 1) | (num & 1);
        num >>= 1;
    }

    return reversed;
}

void MathTools::bit_reverse_copy(const std::vector<ftype>& values, std::vector<ftype>& A)
{
    int bits = 0;

    int size = static_cast<int>(values.size());
    while ((1 << bits) < size)
    {
        ++bits;
    }

    for (uint32_t k = 0; k < values.size(); ++k)
    {
        A.at(bit_reverse(k, bits)) = values.at(k);
    }
}


std::vector<ftype> MathTools::iterativeFFT(const std::vector<ftype> &values)
{
    size_t n = values.size();
    assert(n == 0 ? false : (n & (n - 1)) == 0);

    std::vector<ftype> A(n);
    bit_reverse_copy(values, A);

    for (int s = 1; s <= std::log2(n); s++)
    {
        double m = std::pow(2, s);
        ftype omega_m = std::exp(ftype(0, -2.0 * M_PI / m));

        auto q = static_cast<size_t>(m);
        for (size_t k = 0; k < n; k += q)
        {
            ftype omega = 1.0;

            for (size_t j = 0; j < q / 2; j++)
            {
                ftype t = omega * A.at(k + j + q / 2);
                ftype u = A.at(k + j);
                A.at(k + j) = u + t;
                A.at(k + j + q / 2) = u - t;
                omega *= omega_m;
            }
        }
    }

    return A;
}
 */

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

    //! TODO think about this cycle
    /*for (auto &i : result)
    {
        i /= static_cast<double>(size);
    } */

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