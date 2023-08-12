#include <cassert>
#include <plotter.h>


void Plotter::addPoint(double x)
{
    assert(_file->is_open());
    (*_file) << x << ' ' << "\n";
}