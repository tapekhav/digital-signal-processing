#ifndef DIGITAL_SIGNAL_PROCESSING_FFT_AUTOCORRELATION_FUNCTION_H
#define DIGITAL_SIGNAL_PROCESSING_FFT_AUTOCORRELATION_FUNCTION_H

#include <autocorrelation_function.h>

/*! \class FFTAutoCorrelation
*   \brief Class for FFT autocorrelation function
*/
class FFTAutoCorrelation final : public AbstractAutocorrelationFunction
{
public:
    //! Constructor
    explicit FFTAutoCorrelation(const std::vector<double>& values) : AbstractAutocorrelationFunction(values) {}
    //! FFT autocorrelation
    std::vector<double> estimateSignals() final;
    //! Destructor
    inline ~FFTAutoCorrelation() final { delete _plt; }
};

#endif //DIGITAL_SIGNAL_PROCESSING_FFT_AUTOCORRELATION_FUNCTION_H
