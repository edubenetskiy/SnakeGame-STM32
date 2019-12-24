#ifndef SNAKEGAMELOCALPLAYGROUND_MAINMENU_H
#define SNAKEGAMELOCALPLAYGROUND_MAINMENU_H

#include <unordered_set>
#include "../display/AbstractDisplayDevice.h"
#include "../keyboard/AbstractKeyboard.h"
#include "../timer/AbstractTimer.h"
#include "Snake.h"
#include "GameLevel.h"

namespace allegory::snake {

    class MainMenu {
    public:
        MainMenu(allegory::display::AbstractDisplayDevice &displayDevice,
                 keyboard::AbstractKeyboard &keyboardDevice,
                 timer::AbstractTimer &timer);

        GameLevel run();

    private:
        display::AbstractDisplayDevice &displayDevice;
        keyboard::AbstractKeyboard &keyboardDevice;
        timer::AbstractTimer &timer;
    };
}

#endif //SNAKEGAMELOCALPLAYGROUND_MAINMENU_H
