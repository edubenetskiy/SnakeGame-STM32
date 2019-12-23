#ifndef SNAKEGAMELOCALPLAYGROUND_SNAKERENDERER_H
#define SNAKEGAMELOCALPLAYGROUND_SNAKERENDERER_H

#include "../display/AbstractDisplayDevice.h"
#include "../display/Color.h"
#include "Snake.h"

namespace allegory::snake {
    class SnakeRenderer {
        friend class Snake;

    public:
        static void render(display::AbstractDisplayDevice &displayDevice, const Snake &snake) {
            for (auto p: snake.getBody()) {
                displayDevice.drawPixel(p.getX(), p.getY(), display::Color::WHITE);
            }
        }
    };
}

#endif //SNAKEGAMELOCALPLAYGROUND_SNAKERENDERER_H
