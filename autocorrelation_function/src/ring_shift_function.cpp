#include <ring_shift_function.h>


std::vector<double> RingShiftFunction::estimateSignals()
{
    size_t size = _signals.size();
    std::vector<double> result(size);

    for (size_t shift = 0; shift < size; ++shift)
    {
        for (size_t i = 0; i < size; ++i)
        {
            size_t j = (i + shift) % size;
            result.at(shift) += _signals.at(i) * _signals.at(j);
        }
    }

    return result;
}
