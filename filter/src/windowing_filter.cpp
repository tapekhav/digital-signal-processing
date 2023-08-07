#include <windowing_filter.h>

#include <cassert>
#include <cstddef>

std::vector<double> WindowingFilter::smoothSignals(const std::vector<double>& signals) const
{
    assert(signals.empty() || _window_size <= 0);

    std::vector<double> result;

    auto windows_size = static_cast<size_t>(_window_size);
    double sum = 0.0;
    for (size_t i = 0; i < windows_size; ++i)
    {
        sum += signals.at(i);
    }

    result.push_back(sum / static_cast<double>(windows_size));

    for (size_t i = windows_size; i < signals.size(); ++i)
    {
        sum += signals.at(i) - signals.at(i - windows_size);
        result.push_back(sum / static_cast<double>(windows_size));
    }

    return result;
}