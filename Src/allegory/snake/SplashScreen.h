#ifndef SNAKESTM32_SPLASHSCREEN_H
#define SNAKESTM32_SPLASHSCREEN_H

#include <unordered_set>
#include "../display/AbstractDisplayDevice.h"
#include "Snake.h"
#include "../keyboard/AbstractKeyboard.h"
#include "../timer/AbstractTimer.h"

namespace allegory::snake {

    class SplashScreen {
    public:
        SplashScreen(allegory::display::AbstractDisplayDevice &displayDevice,
                     keyboard::AbstractKeyboard &keyboardDevice);

        void run();

    private:
        display::AbstractDisplayDevice &displayDevice;
        keyboard::AbstractKeyboard &keyboardDevice;
    };
}


#endif //SNAKESTM32_SPLASHSCREEN_H
