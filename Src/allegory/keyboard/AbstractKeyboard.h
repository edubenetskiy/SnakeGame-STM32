//
// Created by edubenet on 23.12.2019.
//

#ifndef SNAKEGAMELOCALPLAYGROUND_KEYBOARD_H
#define SNAKEGAMELOCALPLAYGROUND_KEYBOARD_H

namespace allegory::keyboard {
    enum class Key {
        ONE = 110,
        TWO = 94,
        THREE = 62,
        FOUR = 109,
        FIVE = 93,
        SIX = 61,
        SEVEN = 107,
        EIGHT = 91,
        NINE = 59,
        TEN = 103,
        ELEVEN = 87,
        TWELVE = 55,
        NONE = 0,
    };

    class AbstractKeyboard {
    public:
        virtual Key pollKey() = 0;
    };
}


#endif //SNAKEGAMELOCALPLAYGROUND_KEYBOARD_H
