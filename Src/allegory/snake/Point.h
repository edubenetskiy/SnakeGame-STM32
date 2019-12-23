#ifndef SNAKE_STM32_POINT_H
#define SNAKE_STM32_POINT_H

#include <cstdint>
#include <functional>
#include "Direction.h"

namespace allegory::snake {

    class Point {
    public:
        Point(uint8_t x, uint8_t y);

        uint8_t getX() const;

        uint8_t getY() const;

        Point computeNeighbor(Direction direction) const;

        bool operator==(const Point &rhs) const;

        bool operator!=(const Point &rhs) const;

    private:
        uint8_t x_;
        uint8_t y_;
    };
}

template<>
struct std::hash<allegory::snake::Point> {
    size_t operator()(const allegory::snake::Point &point) const;
};

#endif //SNAKE_STM32_POINT_H
