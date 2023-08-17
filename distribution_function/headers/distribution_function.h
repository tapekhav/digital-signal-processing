#ifndef DIGITAL_SIGNAL_PROCESSING_DISTRIBUTION_FUNCTION_H
#define DIGITAL_SIGNAL_PROCESSING_DISTRIBUTION_FUNCTION_H

#include <vector>
#include <map>

#include <plotter.h>

/*! \class DistributionFunction
*   \brief Creates distribution function
*/
class DistributionFunction
{
public:
    //! Constructor
    DistributionFunction(const std::vector<double>& noise_signals, const std::vector<double>& filtered_signals);
    //! Gets values for distribution function
    std::map<double, double> getDistributionFunction();
    //! Sets plotter
    inline void setPlotter(Plotter* plt) { _plt = plt; }
    //! Destructor
    inline ~DistributionFunction() { delete _plt; }
private:
    std::vector<double> _diff;
    //! Plotter
    Plotter* _plt;
};

#endif //DIGITAL_SIGNAL_PROCESSING_DISTRIBUTION_FUNCTION_H
