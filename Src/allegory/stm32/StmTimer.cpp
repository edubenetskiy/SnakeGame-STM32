#include "StmTimer.h"
#include "stm32f4xx_hal.h"

namespace allegory::stm32 {
    void StmTimer::sleepFor(const std::chrono::milliseconds timeout) {
        HAL_Delay(timeout.count());
    }
}
