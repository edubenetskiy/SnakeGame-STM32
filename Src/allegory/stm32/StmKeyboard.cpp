//
// Created by edubenet on 23.12.2019.
//

#include "StmKeyboard.h"

allegory::keyboard::Key allegory::stm32::StmKeyboard::pollKey() {
    using allegory::keyboard::Key;
    uint8_t symbol;

    symbol = readRow(0);
    switch (static_cast<Key>(symbol)) {
        case Key::ONE:
        case Key::TWO:
        case Key::THREE:
            return static_cast<Key>(symbol);
        default:
            break;
    }

    symbol = readRow(1);
    switch (static_cast<Key>(symbol)) {
        case Key::FOUR:
        case Key::FIVE:
        case Key::SIX:
            return static_cast<Key>(symbol);
        default:
            break;
    }

    symbol = readRow(2);
    switch (static_cast<Key>(symbol)) {
        case Key::SEVEN:
        case Key::EIGHT:
        case Key::NINE:
            return static_cast<Key>(symbol);
        default:
            break;
    }

    symbol = readRow(3);
    switch (static_cast<Key>(symbol)) {
        case Key::TEN:
        case Key::ELEVEN:
        case Key::TWELVE:
            return static_cast<Key>(symbol);
        default:
            break;
    }

    return Key::NONE;
}
