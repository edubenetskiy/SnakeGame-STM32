#include <iostream>
#include <chrono>
#include <thread>
#include "Game.h"
#include "SnakeRenderer.h"
#include "stm32f4xx_hal.h"

namespace allegory::snake {

    using display::Color;

    void Game::invokeMainLoop() {
        std::cout << "Hello world!" << std::endl;

        food.insert(Point(30, 50));
        food.insert(Point(40, 30));
        food.insert(Point(100, 10));

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"

        while (true) {
            displayDevice.clear();
            SnakeRenderer::render(displayDevice, snake);

            switch (keyboard.pollKey()) {
                case keyboard::Key::FOUR:
                    currentDirection = Direction::WEST;
                    break;
                case keyboard::Key::SIX:
                    currentDirection = Direction::EAST;
                    break;
                case keyboard::Key::TWO:
                    currentDirection = Direction::NORTH;
                    break;
                case keyboard::Key::EIGHT:
                    currentDirection = Direction::SOUTH;
                    break;
                default:
                    break;
            }

            snake.walk(currentDirection);

            for (auto meal: food) {
                displayDevice.drawPixel(meal.getX(), meal.getY(), Color::WHITE);
            }
            displayDevice.flush();
            HAL_Delay(100);
        }

#pragma clang diagnostic pop
    }

    Game::Game(display::AbstractDisplayDevice &display, keyboard::AbstractKeyboard &keyboard)
            : displayDevice(display), food(), keyboard(keyboard) {
    }
}
