#include <chrono>
#include "GameLevel.h"

namespace allegory::snake {

    std::ostream &operator<<(std::ostream &os, const GameLevel &gameLevel) {
        switch (gameLevel) {
            case GameLevel::EASY:
                os << "Easy";
                break;
            case GameLevel::MEDIUM:
                os << "Medium";
                break;
            case GameLevel::HARD:
                os << "Hard";
                break;
        }
        return os;
    }

    std::chrono::milliseconds GameLevel::stepInterval() const {
        switch (value) {
            case GameLevel::HARD:
                return std::chrono::milliseconds(33);
            case GameLevel::MEDIUM:
                return std::chrono::milliseconds(66);
            default:
                return std::chrono::milliseconds(100);
        };
    }

}
