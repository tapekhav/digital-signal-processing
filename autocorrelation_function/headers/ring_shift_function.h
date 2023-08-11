#ifndef DIGITAL_SIGNAL_PROCESSING_RING_SHIFT_FUNCTION_H
#define DIGITAL_SIGNAL_PROCESSING_RING_SHIFT_FUNCTION_H

#include <autocorrelation_function.h>

#include <cstddef>

class RingShiftFunction final : public AbstractAutocorrelationFunction
{
public:
    explicit RingShiftFunction(const std::vector<double>& values) : AbstractAutocorrelationFunction(values) {}

    std::vector<double> estimateSignals() final;
    ~RingShiftFunction() final = default;
};

#endif //DIGITAL_SIGNAL_PROCESSING_RING_SHIFT_FUNCTION_H
