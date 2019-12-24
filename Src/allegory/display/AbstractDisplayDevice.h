#ifndef SNAKE_STM32_ABSTRACTDISPLAYDEVICE_H
#define SNAKE_STM32_ABSTRACTDISPLAYDEVICE_H

#include <cstdint>
#include "Color.h"
#include "../snake/Geometry.h"

namespace allegory::display {

    using snake::Geometry;

    class AbstractDisplayDevice {
    public:
        virtual void init() = 0;

        virtual uint8_t height() = 0;

        virtual uint8_t width() = 0;

        virtual Geometry geometry();

        virtual void drawPixel(uint8_t x, uint8_t y, Color color) = 0;

        virtual void flush() = 0;

        virtual void fill(Color color);

        virtual void clear();

    };
}

#endif //SNAKE_STM32_ABSTRACTDISPLAYDEVICE_H
