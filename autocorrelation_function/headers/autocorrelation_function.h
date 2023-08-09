#ifndef DIGITAL_SIGNAL_PROCESSING_AUTOCORRELATION_FUNCTION_H
#define DIGITAL_SIGNAL_PROCESSING_AUTOCORRELATION_FUNCTION_H

#include <vector>

class AbstractAutocorrelationFunction
{
public:
    explicit AbstractAutocorrelationFunction(const std::vector<double>& signals) : _signals(signals) {}
    virtual std::vector<double> estimateSignals() = 0;
    virtual ~AbstractAutocorrelationFunction() = default;
protected:
    std::vector<double> _signals;
};

#endif //DIGITAL_SIGNAL_PROCESSING_AUTOCORRELATION_FUNCTION_H
