#include <windowing_filter.h>

#include <cassert>
#include <numeric>


WindowingFilter::WindowingFilter(int window_size) : _window_size(window_size), _plt(nullptr)
{
    _window_size = _window_size % 2 == 0 ? ++window_size : window_size;
}

std::vector<double> WindowingFilter::smoothSignals(const std::vector<double>& signals) const
{
    assert(!signals.empty() || _window_size <= 0);

    std::vector<double> result(signals.size());
    result.at(0) = signals.at(0);
    result.at(signals.size() - 1) = signals.at(signals.size() - 1);

    auto window_size = static_cast<size_t>(_window_size);
    auto half_size = window_size / 2;

    auto countSum = [&](size_t begin, size_t end, size_t denominator, size_t i)
    {
        double sum = std::accumulate(signals.begin() + static_cast<long>(begin),
                signals.begin() + static_cast<long>(end), 0.0);
        result.at(i) = sum / static_cast<double>(denominator);
        _plt->addPoint(result.at(i));
    };

    for (size_t i = 1; i < half_size; ++i)
    {
        countSum(0, 2 * i + 1, 2 * i + 1, i);
    }

    for (size_t i = half_size; i < signals.size() - 1; ++i)
    {
        if (i + half_size >= signals.size())
        {
            countSum(i - (signals.size() - i), signals.size(), 2 * signals.size() - 2 * i, i);
        }
        else
        {
            countSum(i - half_size, i + half_size + 1, window_size, i);
        }
    }

    return result;
}
