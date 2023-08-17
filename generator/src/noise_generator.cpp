#include <noise_generator.h>

void NoiseGenerator::setDispersion(double dispersion)
{
    std::normal_distribution<double> dist(0, dispersion);
    _distribution = dist;
}