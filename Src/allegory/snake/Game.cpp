#include <iostream>
#include <chrono>
#include <thread>
#include "Game.h"
#include "SnakeRenderer.h"

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

            snake.walk(currentDirection, food);

            renderAndFlush();
            timer.sleepFor(std::chrono::milliseconds(100));
        }

#pragma clang diagnostic pop
    }

    void Game::renderAndFlush() const {
        this->displayDevice.clear();
        SnakeRenderer::render(this->displayDevice, this->snake);

        for (auto meal: this->food) {
            this->displayDevice.drawPixel(meal.getX(), meal.getY(), Color::WHITE);
        }

        displayDevice.flush();
    }

    Game::Game(display::AbstractDisplayDevice &display,
               keyboard::AbstractKeyboard &keyboard,
               timer::AbstractTimer &timer)
            : displayDevice(display), food(), keyboard(keyboard), timer(timer) {
    }
}
