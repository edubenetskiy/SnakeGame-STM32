#include "Text.h"

#include <utility>

allegory::fonts::Text::Text(std::string string, Font font) : string(std::move(string)), font(std::move(font)) {}

size_t allegory::fonts::Text::width() const {
    return font.width * string.length();
}

size_t allegory::fonts::Text::height() const {
    return font.height;
}

void allegory::fonts::Text::render(allegory::display::AbstractDisplayDevice &displayDevice,
                                   size_t left, size_t top) const {
    for (char character : string) {
        font.renderCharacter(character, displayDevice, left, top, display::Color::WHITE);
        left += font.width;
    }
}

void allegory::fonts::Text::renderCentered(allegory::display::AbstractDisplayDevice &displayDevice, size_t top) {
    size_t totalHorizontalMargin = displayDevice.width() - width();
    size_t marginLeft = totalHorizontalMargin / 2;
    render(displayDevice, marginLeft, top);
}
