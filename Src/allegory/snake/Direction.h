#ifndef SNAKE_STM32_DIRECTION_H
#define SNAKE_STM32_DIRECTION_H

namespace allegory::snake {

    class Direction {
    public:
        enum Value : uint8_t {
            NORTH = 0,
            WEST = 1,
            SOUTH = 2,
            EAST = 3,
        };

        Direction() = delete;

        constexpr Direction(Value aDirection) : value(aDirection) {}

        // Allow switch and comparisons.
        operator Value() const { return value; }

        // Prevent usage in 'if' conditions.
        explicit operator bool() = delete;

        constexpr bool operator==(Direction a) const { return value == a.value; }

        constexpr bool operator!=(Direction a) const { return value != a.value; }

        constexpr bool operator==(Value a) const { return value == a; }

        constexpr bool operator!=(Value a) const { return value != a; }

        Direction opposite() {
            return Direction(static_cast<Value>((value + 2u) % 4));
        }

    private:
        Value value;
    };
}

#endif //SNAKE_STM32_DIRECTION_H
