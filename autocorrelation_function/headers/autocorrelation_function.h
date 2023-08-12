#ifndef DIGITAL_SIGNAL_PROCESSING_AUTOCORRELATION_FUNCTION_H
#define DIGITAL_SIGNAL_PROCESSING_AUTOCORRELATION_FUNCTION_H

#include <vector>

#include <plotter.h>

/*! \class AbstractAutocorrelationFunction
*   \brief Abstract class for autocorrelation functions
*/
class AbstractAutocorrelationFunction
{
public:
    //! Constructor
    explicit AbstractAutocorrelationFunction(const std::vector<double>& signals) : _signals(signals), _plt(nullptr) {}
    //! Autocorrelation
    virtual std::vector<double> estimateSignals() = 0;
    //! Sets plotter for autocorrelation function
    inline void setPlotter(Plotter* plt) { _plt = plt; }
    //! Destructor
    virtual ~AbstractAutocorrelationFunction() = default;
protected:
    //! Array of signals
    std::vector<double> _signals;
    //! Plotter of autocorrelation function
    Plotter* _plt;
};

#endif //DIGITAL_SIGNAL_PROCESSING_AUTOCORRELATION_FUNCTION_H
