#ifndef DIGITAL_SIGNAL_PROCESSING_WINDOWING_FILTER_H
#define DIGITAL_SIGNAL_PROCESSING_WINDOWING_FILTER_H

#include <vector>

class WindowingFilter
{
public:
    explicit WindowingFilter(int window_size = 3) : _window_size(window_size) {}
    std::vector<double> smoothSignals(const std::vector<double>& signals) const;
private:
    int _window_size;
};

#endif //DIGITAL_SIGNAL_PROCESSING_WINDOWING_FILTER_H
