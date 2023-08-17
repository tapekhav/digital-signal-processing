#include <plotter.h>

#include <cassert>
#include <iomanip>

void Plotter::addPoint(double x)
{
    assert(_file->is_open());
    (*_file) << x << std::setprecision(6) << ' ' << "\n";
}

Plotter::~Plotter()
{
    _file->close();
    delete _file;
}

void Plotter::add2DPoint(double x, double y)
{
    assert(_file->is_open());
    (*_file) << x << ' ' << y << "\n";
}
