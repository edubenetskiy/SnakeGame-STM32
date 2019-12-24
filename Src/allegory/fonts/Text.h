#ifndef SNAKEGAMELOCALPLAYGROUND_TEXT_H
#define SNAKEGAMELOCALPLAYGROUND_TEXT_H

#include <string>
#include "../display/AbstractDisplayDevice.h"
#include "Font.h"

namespace allegory::fonts {

    class Text {
    public:
        Text(std::string string, Font font);

        void render(display::AbstractDisplayDevice &displayDevice, size_t left, size_t top) const;

        void renderCentered(display::AbstractDisplayDevice &displayDevice, size_t top);

        size_t width() const;

        size_t height() const;

    private:
        std::string string;
        Font font;

    };
}

#endif //SNAKEGAMELOCALPLAYGROUND_TEXT_H
