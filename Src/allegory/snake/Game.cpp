#include <iostream>
#include <chrono>
#include <thread>
#include <random>

#include "Game.h"
#include "SnakeRenderer.h"
#include "../fonts/Text.h"

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

            bool walked = snake.walk(currentDirection, food, displayDevice.geometry());
            bool gameOver = !walked;

            this->displayDevice.clear();

            if (gameOver) {
                allegory::fonts::Text("Game Over", allegory::fonts::FONT_11x18).renderCentered(displayDevice, 10);
                allegory::fonts::Text("Press 0 to replay", allegory::fonts::FONT_7x10).renderCentered(displayDevice, 50);
            };

            renderAndFlush();

            if (gameOver) {
                while (keyboard.pollKey() != Key::ELEVEN) {
                    // Wait
                    renderAndFlush();
                }
                break;
            }

            if (pressedKey == Key::ELEVEN) {
                std::cout << "Returning to menu" << std::endl;
                break;
            }

            timer.sleepFor(level.stepInterval());
        }

#pragma clang diagnostic pop
    }

    void Game::renderAndFlush() const {
        SnakeRenderer::render(this->displayDevice, this->snake);

        for (auto meal: this->food) {
            std::cout << "Food: x=" << int(meal.getX()) << ", y=" << int(meal.getY()) << std::endl;
            this->displayDevice.drawPixel(meal.getX(), meal.getY(), Color::WHITE);
        }

        displayDevice.flush();
    }

    Game::Game(display::AbstractDisplayDevice &display, keyboard::AbstractKeyboard &keyboard,
               timer::AbstractTimer &timer, GameLevel level)
            : displayDevice(display), food(), keyboard(keyboard), timer(timer), level(level) {
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
