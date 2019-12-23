#include "Point.h"

namespace allegory::snake {
    Point::Point(uint8_t x, uint8_t y) : x_(x), y_(y) {}

    bool Point::operator==(const Point &rhs) const {
        return x_ == rhs.x_ &&
               y_ == rhs.y_;
    }

    bool Point::operator!=(const Point &rhs) const {
        return !(rhs == *this);
    }

    uint8_t Point::getX() const {
        return x_;
    }

    uint8_t Point::getY() const {
        return y_;
    }

    Point Point::computeNeighbor(Direction direction) const {
        uint8_t x = this->x_;
        uint8_t y = this->y_;

        switch (direction) {
            case Direction::NORTH:
                y -= 1;
                break;
            case Direction::WEST:
                x -= 1;
                break;
            case Direction::SOUTH:
                y += 1;
                break;
            case Direction::EAST:
                x += 1;
                break;
        }

        return Point(x, y);
    }
}

size_t std::hash<allegory::snake::Point>::operator()(const allegory::snake::Point &point) const {
    return std::hash<uint8_t>()(point.getX()) ^
           std::hash<uint8_t>()(point.getY()) << 1u;
}
