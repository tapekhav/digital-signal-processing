#ifndef DIGITAL_SIGNAL_PROCESSING_NOISE_SIGNAL_FUNCTION_H
#define DIGITAL_SIGNAL_PROCESSING_NOISE_SIGNAL_FUNCTION_H

#include <noise_generator.h>
#include <signal_function.h>


/*! \class NoiseSignalFunction
*   \brief Generate one signal unit with noise
*/
class NoiseSignalFunction final : public SignalFunction
{
public:
    NoiseSignalFunction(double freq, double amplitude, double offset) : SignalFunction(freq, amplitude, offset) {}
    //! Implements formula for generating one signal unit with noise
    double inline formula(double time) final { return _amplitude * sin(2 * M_PI * time * _frequency + _phase_offset)
                                                                                                    + gen.generate(); }
    //! Sets dispersion of noises
    inline void setDispersion(double dispersion) { gen.setDispersion(dispersion); }
    //! Destructor
    ~NoiseSignalFunction() final = default;
private:
    NoiseGenerator gen;
};

#endif //DIGITAL_SIGNAL_PROCESSING_NOISE_SIGNAL_FUNCTION_H
