#ifndef SNAKEGAMELOCALPLAYGROUND_GAMELEVEL_H
#define SNAKEGAMELOCALPLAYGROUND_GAMELEVEL_H

#include <ostream>
#include <chrono>

namespace allegory::snake {
    class GameLevel {
    public:
        enum Value : int8_t {
            EASY = 0,
            MEDIUM = 1,
            HARD = 2,
        };

        GameLevel() = delete;

        constexpr GameLevel(Value aLevel) : value(aLevel) {}

        // Allow switch and comparisons.
        operator Value() const { return value; }

        // Prevent usage in 'if' conditions.
        explicit operator bool() = delete;

        constexpr bool operator==(GameLevel a) const { return value == a.value; }

        constexpr bool operator!=(GameLevel a) const { return value != a.value; }

        constexpr bool operator==(Value a) const { return value == a; }

        constexpr bool operator!=(Value a) const { return value != a; }

        friend std::ostream &operator<<(std::ostream &os, const GameLevel &dt);

        std::chrono::milliseconds stepInterval() const;

    private:
        Value value;
    };

    std::ostream &operator<<(std::ostream &os, const GameLevel &gameLevel);
}

#endif //SNAKEGAMELOCALPLAYGROUND_GAMELEVEL_H
