#ifndef DIGITAL_SIGNAL_PROCESSING_SIGNAL_GENERATE_H
#define DIGITAL_SIGNAL_PROCESSING_SIGNAL_GENERATE_H

#include <vector>
#include <noise_signal_function.h>


/*! \class SignalGenerate
*   \brief Generate full signal
*/
class SignalGenerate
{
public:
    //! Constructor
    explicit SignalGenerate(SignalFunction* signal);
    //! Generates full signal in interval with step
    std::vector<double> getSignals(double start, double end, double step);
    //! Destructor
    ~SignalGenerate() { delete _signal; }
private:
    //! Signal function(with noise or not)
    SignalFunction* _signal;
};

#endif //DIGITAL_SIGNAL_PROCESSING_SIGNAL_GENERATE_H
