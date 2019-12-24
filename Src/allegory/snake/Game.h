#ifndef SNAKE_STM32_GAMEMENU_H
#define SNAKE_STM32_GAMEMENU_H

#include <unordered_set>
#include "../display/AbstractDisplayDevice.h"
#include "Snake.h"
#include "../keyboard/AbstractKeyboard.h"
#include "../timer/AbstractTimer.h"

namespace allegory::snake {

    class Game {

    public:
        Game(display::AbstractDisplayDevice &display,
             keyboard::AbstractKeyboard &keyboard,
             timer::AbstractTimer &timer);

        void invokeMainLoop();

    private:
        display::AbstractDisplayDevice &displayDevice;
        keyboard::AbstractKeyboard &keyboard;
        timer::AbstractTimer &timer;
        Snake snake;
        Direction currentDirection = Direction::EAST;
        std::unordered_set<Point> food;

        void renderAndFlush() const;
    };
}
#endif //SNAKE_STM32_GAMEMENU_H
