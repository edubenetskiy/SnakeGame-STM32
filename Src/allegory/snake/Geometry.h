#ifndef SNAKESTM32_GEOMETRY_H
#define SNAKESTM32_GEOMETRY_H

#include <cstdint>

namespace allegory::snake {

    class Geometry {
    public:
        Geometry(uint8_t width, uint8_t height);

        uint8_t const width;
        uint8_t const height;
    };
}

#endif //SNAKESTM32_GEOMETRY_H
