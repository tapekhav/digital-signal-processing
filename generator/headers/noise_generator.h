#ifndef DIGITAL_SIGNAL_PROCESSING_NOISE_GENERATOR_H
#define DIGITAL_SIGNAL_PROCESSING_NOISE_GENERATOR_H

#include <random>

static const double k_noise_dispersion = 1e-6;

/*! \class NoiseGenerator
*   \brief Generate noise with normal distribution
*/
class NoiseGenerator
{
public:
    //! Constructor
    inline NoiseGenerator(): _rd(), _gen(_rd()), _distribution(0, k_noise_dispersion) {}
    //! Generates random noise with a given dispersion
    inline double generate() { return _distribution(_gen); }

private:
    std::random_device _rd;
    std::mt19937 _gen;
    std::normal_distribution<double> _distribution;
};

#endif //DIGITAL_SIGNAL_PROCESSING_NOISE_GENERATOR_H
