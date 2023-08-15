#ifndef DIGITAL_SIGNAL_PROCESSING_CLI_H
#define DIGITAL_SIGNAL_PROCESSING_CLI_H

#include <vector>

#include <signal_generate.h>
#include <windowing_filter.h>
#include <distribution_function.h>
#include <ring_shift_function.h>
#include <fft_autocorrelation_function.h>


/*! \class Option
*   \brief Creates CLI interface
*/
class Option
{
public:
    //! Start program
    void start();
    //! Sets parameters of generator
    void selectGenerator();
    //! Sets parameters of filter
    void selectFilter();
    //! Sets parameters of autocorrelation function
    void selectAutocorrelation();
    //! Sets distribution function
    void setDistFunc();
    //! Print all data
    void printAll();
private:
    //! Generates signal
    std::unique_ptr<SignalGenerate> _signal;
    std::vector<double> _signal_vector;
    //! Filter
    std::unique_ptr<WindowingFilter> _filter;
    std::vector<double> _filter_vector;
    //! Autocorrelation function
    std::unique_ptr<AbstractAutocorrelationFunction> _autocorr_func;
    std::vector<double> _autocorr_vector;
    //! Distribution function
    std::unique_ptr<DistributionFunction> _dist_func;
    std::map<double, int> _dist_map;
};

#endif //DIGITAL_SIGNAL_PROCESSING_CLI_H
