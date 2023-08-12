#ifndef DIGITAL_SIGNAL_PROCESSING_AUTOCORRELATION_FUNCTION_H
#define DIGITAL_SIGNAL_PROCESSING_AUTOCORRELATION_FUNCTION_H

#include <vector>

/*! \class AbstractAutocorrelationFunction
*   \brief Abstract class for autocorrelation functions
*/
class AbstractAutocorrelationFunction
{
public:
    //! Constructor
    explicit AbstractAutocorrelationFunction(const std::vector<double>& signals) : _signals(signals) {}
    //! Autocorrelation
    virtual std::vector<double> estimateSignals() = 0;
    //! Destructor
    virtual ~AbstractAutocorrelationFunction() = default;
protected:
    //! Array of signals
    std::vector<double> _signals;
};

#endif //DIGITAL_SIGNAL_PROCESSING_AUTOCORRELATION_FUNCTION_H
