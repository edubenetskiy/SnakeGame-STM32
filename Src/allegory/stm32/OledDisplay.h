#ifndef SNAKESTM32_OLEDDISPLAY_H
#define SNAKESTM32_OLEDDISPLAY_H


#include "../display/AbstractDisplayDevice.h"

namespace allegory::stm32 {
    class OledDisplay : public display::AbstractDisplayDevice {
    public:
        void init() override;

        uint8_t height() override;

        uint8_t width() override;

        void drawPixel(uint8_t x, uint8_t y, display::Color color) override;

        void flush() override;

        void writeCommand(uint8_t command);
    };

    static const uint16_t OLED_I2C_ADDR = 0x78;

    // SSD1306 width in pixels
    static const size_t OLED_WIDTH = 128;

    // SSD1306 LCD height in pixels
    static const size_t OLED_HEIGHT = 64;
}

#endif //SNAKESTM32_OLEDDISPLAY_H
