#include <distribution_function.h>

#include <algorithm>

DistributionFunction::DistributionFunction(const std::vector<double>& noise_signals,
                                           const std::vector<double>& filtered_signals) : _plt(nullptr)
{
    size_t size = std::min(noise_signals.size(), filtered_signals.size());
    for (size_t i = 0; i < size; ++i)
    {
        _diff.push_back(std::abs(noise_signals.at(i) - filtered_signals.at(i)));
    }
}

std::map<double, double> DistributionFunction::getDistributionFunction()
{
    std::sort(_diff.begin(), _diff.end());

    std::map<double, double> result;

    double count = 1;
    _plt->add2DPoint(_diff.at(0), result[_diff.at(0)]);
    for (size_t i = 1; i < _diff.size(); ++i)
    {
        ++count;
        result[_diff.at(i)] = count / static_cast<double>(_diff.size());
    }

    for (auto i : result)
    {
        _plt->add2DPoint(i.first, i.second);
    }

    return result;
}
