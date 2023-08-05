#ifndef DIGITAL_SIGNAL_PROCESSING_SIGNAL_GENERATE_H
#define DIGITAL_SIGNAL_PROCESSING_SIGNAL_GENERATE_H

#include <vector>

class SignalFunction;

class SignalGenerate
{
public:
    explicit SignalGenerate(SignalFunction* signal);

    std::vector<double> getSignals(double start, double step);
private:
    SignalFunction* _signal;
};

#endif //DIGITAL_SIGNAL_PROCESSING_SIGNAL_GENERATE_H
