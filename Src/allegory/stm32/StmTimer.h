#include "../timer/AbstractTimer.h"

namespace allegory::stm32 {
    class StmTimer : public timer::AbstractTimer {
    public:
        void sleepFor(std::chrono::milliseconds timeout) override;
    };
}
