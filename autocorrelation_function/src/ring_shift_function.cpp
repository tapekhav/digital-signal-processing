#include <ring_shift_function.h>


std::vector<double> RingShiftFunction::estimateSignals()
{
    size_t size = _signals.size();
    std::vector<double> result;

    for (size_t shift = 0; shift < size; ++shift)
    {
        std::vector<double> original(_signals.begin(), _signals.end() - static_cast<long>(shift));
        std::vector<double> shifted(_signals.begin() + static_cast<long>(shift), _signals.end());

        double rms_original = MathTools::rootMeanSquare(original);
        double rms_shifted = MathTools::rootMeanSquare(shifted);

        double mean_original = MathTools::meanValue(original, original.size());
        double mean_shifted = MathTools::meanValue(shifted, shifted.size());

        double product = 0.0;
        for (size_t i = 0; i < original.size(); ++i) { product += original.at(i) * shifted.at(i); }
        product /= static_cast<double>(original.size());

        result.push_back((product - mean_original * mean_shifted) / rms_original * rms_shifted);
        _plt->addPoint(result.back());
    }



    return result;
}
