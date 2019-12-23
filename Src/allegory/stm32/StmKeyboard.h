//
// Created by edubenet on 23.12.2019.
//

#ifndef SNAKESTM32_STMKEYBOARD_H
#define SNAKESTM32_STMKEYBOARD_H

#include <cstdint>
#include "../keyboard/AbstractKeyboard.h"
#include "i2c.h"
#include "stm32f4xx_hal.h"

namespace allegory::stm32 {
    class StmKeyboard : public keyboard::AbstractKeyboard {
    public:
        keyboard::Key pollKey() override;

    private:
        uint8_t readRow(uint8_t row) {
            uint8_t configuration_comman = 0x70;
            uint8_t command_c = 0;
            uint8_t r_symbol = 0;

            HAL_I2C_Mem_Write(&hi2c1, 0xE2, 0x03, 1, &configuration_comman, 1, 100);
            HAL_I2C_Mem_Write(&hi2c1, 0xE2, 0x01, 1, &command_c, 1, 100);
            HAL_I2C_Mem_Read(&hi2c1, 0xE3, 0x00, 1, &r_symbol, 1, 100);

            uint8_t configuration_command = 0x70;
            uint8_t command = 0xF7u >> (3u - row);
            uint8_t read_symbol = 0;

            HAL_I2C_Mem_Write(&hi2c1, 0xE2, 0x03, 1, &configuration_command, 1, 100);
            HAL_I2C_Mem_Write(&hi2c1, 0xE2, 0x01, 1, &command, 1, 100);
            HAL_I2C_Mem_Read(&hi2c1, 0xE3, 0x00, 1, &read_symbol, 1, 100);

            return read_symbol;
        }
    };
}

#endif //SNAKESTM32_STMKEYBOARD_H
