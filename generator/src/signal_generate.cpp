#include <signal_generate.h>
#include <noise_signal_function.h>

SignalGenerate::SignalGenerate(SignalFunction *signal) : _signal(nullptr)
{
    _signal = dynamic_cast<SignalFunction*>(signal);
    if (!_signal)
    {
        _signal = dynamic_cast<NoiseSignalFunction*>(signal);
    }
}

std::vector<double> SignalGenerate::getSignals(double start, double step)
{
    std::vector<double> res;
    for (double i = start;; i += step)
    {
        res.push_back(_signal->formula(i));
    }
}
