#ifndef DIGITAL_SIGNAL_PROCESSING_RING_SHIFT_FUNCTION_H
#define DIGITAL_SIGNAL_PROCESSING_RING_SHIFT_FUNCTION_H

#include <autocorrelation_function.h>

class RingShiftFunction final : public AbstractAutocorrelationFunction
{
public:
    double estimateSignal(double signal);
    std::vector<double> estimateSignals() final;
    ~RingShiftFunction() final = default;
};

#endif //DIGITAL_SIGNAL_PROCESSING_RING_SHIFT_FUNCTION_H