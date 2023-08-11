#ifndef DIGITAL_SIGNAL_PROCESSING_FFT_AUTOCORRELATION_FUNCTION_H
#define DIGITAL_SIGNAL_PROCESSING_FFT_AUTOCORRELATION_FUNCTION_H

#include <autocorrelation_function.h>

class FFTAutoCorrelation final : public AbstractAutocorrelationFunction
{
public:
    std::vector<double> estimateSignals() final;
    ~FFTAutoCorrelation() final = default;
};

#endif //DIGITAL_SIGNAL_PROCESSING_FFT_AUTOCORRELATION_FUNCTION_H
