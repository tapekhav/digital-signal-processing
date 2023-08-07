#ifndef DIGITAL_SIGNAL_PROCESSING_SIGNAL_GENERATE_H
#define DIGITAL_SIGNAL_PROCESSING_SIGNAL_GENERATE_H

#include <vector>
#include <noise_signal_function.h>

class SignalGenerate
{
public:
    explicit SignalGenerate(SignalFunction* signal);

    std::vector<double> getSignals(double start, double end, double step);

    ~SignalGenerate() { delete _signal; }
private:
    SignalFunction* _signal;
};

#endif //DIGITAL_SIGNAL_PROCESSING_SIGNAL_GENERATE_H
