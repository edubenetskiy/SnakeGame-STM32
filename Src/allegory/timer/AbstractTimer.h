#ifndef SNAKESTM32_ABSTRACTTIMER_H
#define SNAKESTM32_ABSTRACTTIMER_H

#include <chrono>

namespace allegory::timer {
    class AbstractTimer {
    public:
        virtual void sleepFor(const std::chrono::milliseconds timeout) = 0;
    };
}


#endif //SNAKESTM32_ABSTRACTTIMER_H
