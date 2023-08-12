#include <plotter.h>

#include <cassert>

void Plotter::addPoint(double x)
{
    assert(_file->is_open());
    (*_file) << x << ' ' << "\n";
}