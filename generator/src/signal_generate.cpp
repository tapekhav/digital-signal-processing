#include <signal_generate.h>

SignalGenerate::SignalGenerate(SignalFunction *signal) : _signal(nullptr)
{
    _signal = dynamic_cast<SignalFunction*>(signal);
    if (!_signal)
    {
        _signal = dynamic_cast<NoiseSignalFunction*>(signal);
    }
}

std::vector<double> SignalGenerate::getSignals(double start, double end, double step)
{
    std::vector<double> res;
    for (double i = start; i < end; i += step)
    {
        res.push_back(_signal->formula(i));
    }

    return res;
}
