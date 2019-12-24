#ifndef SNAKE_STM32_SNAKE_H
#define SNAKE_STM32_SNAKE_H

#include <cstdint>
#include <deque>
#include <unordered_set>
#include "Direction.h"
#include "Point.h"

namespace allegory::snake {

    class Snake {
    public:
        Snake();

        explicit Snake(std::deque<Point> body);

        void walk(Direction direction, std::unordered_set<Point> &food);

    public:
        size_t length();

        Point head();

        Point tail();

        const std::deque<Point> &getBody() const;

    private:
        std::deque<Point> body;
    };
}
#endif //SNAKE_STM32_SNAKE_H
