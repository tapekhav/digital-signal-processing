#include <ring_shift_function.h>

#include <numeric>

#include <math_tools.h>

std::vector<double> RingShiftFunction::estimateSignals()
{
    std::vector<double> result;

    for (size_t i = 0; i < _signals.size(); ++i)
    {
        result.push_back(estimateSignal(i));
    }

    return result;
}

double RingShiftFunction::estimateSignal(size_t offset)
{
    auto size = static_cast<double>(_signals.size() - offset);
    long shift = static_cast<long>(offset);

    double original_mean = std::accumulate(_signals.begin(), _signals.end() - shift, 0.0) / size;
    double shifted_mean = std::accumulate(_signals.begin() + shift, _signals.end(), 0.0) / size;



    return 0.0;
}
