#ifndef DIGITAL_SIGNAL_PROCESSING_NOISE_SIGNAL_FUNCTION_H
#define DIGITAL_SIGNAL_PROCESSING_NOISE_SIGNAL_FUNCTION_H

#include <noise_generator.h>
#include <signal_function.h>

class NoiseSignalFunction final : public SignalFunction
{
public:
    double formula(double time) final { return _amplitude * cos(2 * pi * time * _frequency + _phase_offset) + gen.generate(); }

    ~NoiseSignalFunction() final = default;
private:
    NoiseGenerator gen;
};

#endif //DIGITAL_SIGNAL_PROCESSING_NOISE_SIGNAL_FUNCTION_H
