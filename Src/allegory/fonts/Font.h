#ifndef SNAKEGAMELOCALPLAYGROUND_FONT_H
#define SNAKEGAMELOCALPLAYGROUND_FONT_H

#include <cstdint>
#include <vector>

#include "../display/AbstractDisplayDevice.h"

namespace allegory::fonts {

    class Font {
    public:
        Font(size_t width, size_t height, std::vector<uint16_t> data);

        char renderCharacter(char character, display::AbstractDisplayDevice &displayDevice, size_t left, size_t top,
                             display::Color color) const;

        const size_t width;
        const size_t height;

    private:
        std::vector<uint16_t> data;
    };

    extern const Font FONT_7x10;
    extern const Font FONT_11x18;
    extern const Font FONT_16x26;
}

#endif //SNAKEGAMELOCALPLAYGROUND_FONT_H
