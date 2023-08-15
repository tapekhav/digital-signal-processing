#include <cli.h>

#include <iostream>
#include <memory>

void Option::start()
{
    selectGenerator();
    selectFilter();
    selectAutocorrelation();
    setDistFunc();

    printAll();
}

void Option::selectGenerator()
{
    int choice;
    std::cout << "Choose signal generator(formula Asin(wt + p)):\n";
    std::cout << "1) Standard generator\n";
    std::cout << "2) With noise\n";

    std::cin >> choice;

    int A;
    std::cout << "Set amplitude: ";
    std::cin >> A;

    int freq;
    std::cout << "Set frequency: ";
    std::cin >> freq;

    int offset;
    std::cout << "Set phase offset: ";
    std::cin >> offset;

    SignalFunction* func = choice == 1 ? new SignalFunction(freq, A, offset) : new NoiseSignalFunction(freq, A, offset);

    _signal = std::make_unique<SignalGenerate>(func);
    _signal->setPlotter(new Plotter(p_signal));

    int begin, end, step;
    std::cout << "Set begin: ";
    std::cin >> begin;

    std::cout << "Set end: ";
    std::cin >> end;

    std::cout << "Set step: ";
    std::cin >> step;

    _signal_vector = _signal->getSignals(begin, end, step);
}

void Option::selectFilter()
{
    std::cout << "Choose sliding window filter size of window:\n";
    size_t size;
    std::cin >> size;

    _filter = std::make_unique<WindowingFilter>(size);
    _filter->setPlotter(new Plotter(p_filter));

    _filter_vector = _filter->smoothSignals(_signal_vector);
}

void Option::selectAutocorrelation()
{
    int choice;
    std::cout << "Choose autocorrelation function:\n";
    std::cout << "1) Standard method(ring offset)\n";
    std::cout << "2) FFT\n";

    std::cin >> choice;
    if (choice == 1)
    {
        _autocorr_func = std::make_unique<RingShiftFunction>(_signal_vector);
    }
    else
    {
        _autocorr_func = std::make_unique<FFTAutoCorrelation>(_signal_vector);
    }

    _autocorr_func->setPlotter(new Plotter(p_autocorr));
    _autocorr_vector = _autocorr_func->estimateSignals();
}

void Option::setDistFunc()
{
    std::cout << "Distribution function cannot be selected\n";

    _dist_func = std::make_unique<DistributionFunction>(_signal_vector, _filter_vector);
    _dist_func->setPlotter(new Plotter(p_dist));

    _dist_map = _dist_func->getDistributionFunction();
}

void Option::printAll()
{
    std::cout << "\n\nRESULT\n\n";

    std::cout << "Result of generated signal: \n";
    for (auto i : _signal_vector)
    {
        std::cout << i << '\n';
    }

    std::cout << "Result of filtered signal: \n";
    for (auto i : _filter_vector)
    {
        std::cout << i << '\n';
    }

    std::cout << "Result of distribution function: \n";
    for (auto i : _dist_map)
    {
        std::cout << i.first << '\n';
    }

    std::cout << "Deviations: \n";
    for (auto i : _dist_map)
    {
        std::cout << i.first << " " << i.second << '\n';
    }

    std::cout << "Autocorrelation function: \n";
    for (auto i : _autocorr_vector)
    {
        std::cout << i << '\n';
    }
}
