#include <iostream>
#include <chrono>
#include <thread>
#include <random>

#include "Game.h"
#include "SnakeRenderer.h"

namespace allegory::snake {

    using display::Color;
    using keyboard::Key;

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

            Key pressedKey = keyboard.pollKey();
            if (pressedKey != Key::NONE) {
                std::optional<Direction> newDirection = convertKeyToDirection(pressedKey);
                if (newDirection.has_value() && newDirection != currentDirection.opposite()) {
                    currentDirection = newDirection.value();
                }
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

    constexpr std::optional<Direction> Game::convertKeyToDirection(keyboard::Key key) {
        using keyboard::Key;
        switch (key) {
            case Key::FOUR:
                return Direction::WEST;
            case Key::SIX:
                return Direction::EAST;
            case Key::TWO:
                return Direction::NORTH;
            case Key::EIGHT:
                return Direction::SOUTH;
            default:
                return std::nullopt;
        }
    }
}
