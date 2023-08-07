#include <math_tools.h>

#include <numeric>
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
