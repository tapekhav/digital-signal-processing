#ifndef DIGITAL_SIGNAL_PROCESSING_WINDOWING_FILTER_H
#define DIGITAL_SIGNAL_PROCESSING_WINDOWING_FILTER_H

#include <vector>

#include <plotter.h>

/*! \class WindowingFilter
*   \brief Module for filtering the incoming signal based on a sliding window
*/
class WindowingFilter
{
public:
    //! Constructor
    explicit WindowingFilter(int window_size = 3);
    //! Filtering method
    [[nodiscard]] std::vector<double> smoothSignals(const std::vector<double>& signals) const;
    //! Sets plotter
    inline void setPlotter(Plotter* plt) { _plt = plt; }
    //! Destructor
    inline ~WindowingFilter() { delete _plt; }
private:
    int _window_size;
    Plotter* _plt;
};

#endif //DIGITAL_SIGNAL_PROCESSING_WINDOWING_FILTER_H
