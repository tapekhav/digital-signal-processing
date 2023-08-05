#ifndef DIGITAL_SIGNAL_PROCESSING_SIGNAL_GENERATOR_H
#define DIGITAL_SIGNAL_PROCESSING_SIGNAL_GENERATOR_H

#include <cmath>

static const double pi = 3.14;
/*! \class SignalGenerator
*   \brief
*
*/
class SignalGenerator
{
public:
    //!
    inline SignalGenerator(double frequency, double amplitude, double phase_offset) : _frequency(frequency),
                                                                                      _amplitude(amplitude),
                                                                                      _phase_offset(phase_offset) {}
    //!
    inline double formula(float time) const { return _amplitude * cos(2 * pi * time * _frequency + _phase_offset); }
private:
    double _frequency;
    double _amplitude;
    double _phase_offset;
};
#endif //DIGITAL_SIGNAL_PROCESSING_SIGNAL_GENERATOR_H
