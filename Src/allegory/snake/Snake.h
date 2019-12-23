#ifndef SNAKE_STM32_SNAKE_H
#define SNAKE_STM32_SNAKE_H

#include <cstdint>
#include <deque>
#include "Direction.h"
#include "Point.h"

namespace allegory::snake {

    class Snake {
    public:
        Snake();

        explicit Snake(std::deque<Point> body);

    public:
        size_t length();

        Point head();

        Point tail();

        const std::deque<Point> &getBody() const;

        void walk(Direction direction);

    private:
        std::deque<Point> body;
    };
}
#endif //SNAKE_STM32_SNAKE_H
