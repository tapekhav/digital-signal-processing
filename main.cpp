#include <iostream>

#include <signal_generate.h>
#include <windowing_filter.h>

int main()
{
    SignalGenerate gen_signals(new SignalFunction(1, 1, 0));

    auto vec = gen_signals.getSignals(0, 1, 0.01);

    for (auto i : vec)
    {
        std::cout << i << " ";
    }

    std::cout << "\n\n";

    WindowingFilter zxc(5);

    auto res = zxc.smoothSignals(vec);

    for (auto i : res)
    {
        std::cout << i << " ";
    }

    return 0;
}