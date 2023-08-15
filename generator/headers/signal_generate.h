#ifndef DIGITAL_SIGNAL_PROCESSING_SIGNAL_GENERATE_H
#define DIGITAL_SIGNAL_PROCESSING_SIGNAL_GENERATE_H

#include <noise_signal_function.h>

#include <vector>
#include <memory>

#include <plotter.h>

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
    //! Sets plotter object
    inline void setPlotter(Plotter* plt) { _plotter = plt; }
    //! Destructor
    ~SignalGenerate();
private:
    //! Signal function(with noise or not)
    SignalFunction* _signal;
    //! Plotter for signal
    Plotter* _plotter;
};

#endif //DIGITAL_SIGNAL_PROCESSING_SIGNAL_GENERATE_H
