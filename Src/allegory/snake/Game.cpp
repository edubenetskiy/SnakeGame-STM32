#include <iostream>
#include <chrono>
#include <thread>
#include <random>

#include "Game.h"
#include "SnakeRenderer.h"

namespace allegory::snake {

    using display::Color;

    static const int MAX_NUM_APPLES = 5;

    void Game::invokeMainLoop() {
        std::cout << "Hello world!" << std::endl;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"

        std::random_device randomDevice;
        std::mt19937 rng(randomDevice()); // Mersenne-Twister random-number engine

        std::uniform_int_distribution<int> xDistribution(0, displayDevice.width() - 1); // guaranteed unbiased
        std::uniform_int_distribution<int> yDistribution(0, displayDevice.height() - 1); // guaranteed unbiased

        while (true) {
            while (food.size() < MAX_NUM_APPLES) {
                Point apple(xDistribution(rng), yDistribution(rng));
                food.insert(apple);
            }

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
            std::cout << "Food: x=" << int(meal.getX()) << ", y=" << int(meal.getY()) << std::endl;
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
