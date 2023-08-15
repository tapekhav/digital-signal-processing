#ifndef DIGITAL_SIGNAL_PROCESSING_RING_SHIFT_FUNCTION_H
#define DIGITAL_SIGNAL_PROCESSING_RING_SHIFT_FUNCTION_H

#include <autocorrelation_function.h>

#include <cstddef>

/*! \class RingShiftFunction
*   \brief Class for FFT autocorrelation function
*/
class RingShiftFunction final : public AbstractAutocorrelationFunction
{
public:
    //! Constructor
    explicit RingShiftFunction(const std::vector<double>& values) : AbstractAutocorrelationFunction(values) {}
    //! Standard autocorrelation
    std::vector<double> estimateSignals() final;
    //! Destructor
    inline ~RingShiftFunction() final { delete _plt; }
};

#endif //DIGITAL_SIGNAL_PROCESSING_RING_SHIFT_FUNCTION_H
