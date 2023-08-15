#ifndef DIGITAL_SIGNAL_PROCESSING_PLOTTER_H
#define DIGITAL_SIGNAL_PROCESSING_PLOTTER_H

#include <fstream>
#include <string>

/*! \class Plotter
*   \brief Converts data to file.
* 	It translates the data needed to build a graph into some file.
* 	Then the script that launches the chart is manually launched.
*/
class Plotter
{
public:
    //! Constructor
    inline explicit Plotter(const std::string& filepath) : _file(new std::ofstream(filepath)) {}
    //! Destructor
    ~Plotter();
    //! Insert point to the file
    void addPoint(double x);

private:
    //! Result file with points
    std::ofstream* _file;
};

#endif //DIGITAL_SIGNAL_PROCESSING_PLOTTER_H
