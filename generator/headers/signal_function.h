#ifndef DIGITAL_SIGNAL_PROCESSING_SIGNAL_FUNCTION_H
#define DIGITAL_SIGNAL_PROCESSING_SIGNAL_FUNCTION_H

#include <cmath>

/*! \class SignalFunction
*   \brief
*
*/
class SignalFunction
{
public:
    //!
    inline SignalFunction(double frequency, double amplitude, double phase_offset) : _frequency(frequency),
                                                                                     _amplitude(amplitude),
                                                                                     _phase_offset(phase_offset) {}
    //!
    virtual double formula(double time) { return _amplitude * sin(2 * M_PI * time * _frequency + _phase_offset); }
    //!
    virtual ~SignalFunction() = default;
protected:
    double _frequency;
    double _amplitude;
    double _phase_offset;
};
#endif //DIGITAL_SIGNAL_PROCESSING_SIGNAL_FUNCTION_H
