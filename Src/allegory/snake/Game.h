#ifndef SNAKE_STM32_GAMEMENU_H
#define SNAKE_STM32_GAMEMENU_H

#include <unordered_set>
#include "../display/AbstractDisplayDevice.h"
#include "Snake.h"
#include "../keyboard/AbstractKeyboard.h"

namespace allegory::snake {

    class Game {

    public:
        Game(display::AbstractDisplayDevice &display, keyboard::AbstractKeyboard &keyboard);

        void invokeMainLoop();

    private:
        display::AbstractDisplayDevice &displayDevice;
        keyboard::AbstractKeyboard &keyboard;
        Snake snake;
        Direction currentDirection = Direction::EAST;
        std::unordered_set<Point> food;
    };
}
#endif //SNAKE_STM32_GAMEMENU_H
