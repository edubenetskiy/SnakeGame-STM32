//
// Created by edubenet on 23.12.2019.
//

#include <i2c.h>
#include "OledDisplay.h"
#include "stm32f4xx_hal.h"

static uint8_t OLED_Buffer[1024];

void allegory::stm32::OledDisplay::init() {
    HAL_Delay(100);

    /* Init screen */
    writeCommand(0xAE); //display off
    writeCommand(0x20); //Set Memory Addressing Mode
    writeCommand(
            0x10); //00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid
    writeCommand(0xB0); //Set Page Start Address for Page Addressing Mode,0-7
    writeCommand(0xC8); //Set COM Output Scan Direction
    writeCommand(0x00); //---set low column address
    writeCommand(0x10); //---set high column address
    writeCommand(0x40); //--set start line address
    writeCommand(0x81); //--set contrast control register
    writeCommand(0xFF);
    writeCommand(0xA1); //--set segment re-map 0 to 127
    writeCommand(0xA6); //--set normal display
    writeCommand(0xA8); //--set multiplex ratio(1 to 64)
    writeCommand(0x3F); //
    writeCommand(0xA4); //0xa4,Output follows RAM content;0xa5,Output ignores RAM content
    writeCommand(0xD3); //-set display offset
    writeCommand(0x00); //-not offset
    writeCommand(0xD5); //--set display clock divide ratio/oscillator frequency
    writeCommand(0xF0); //--set divide ratio
    writeCommand(0xD9); //--set pre-charge period
    writeCommand(0x22); //
    writeCommand(0xDA); //--set com pins hardware configuration
    writeCommand(0x12);
    writeCommand(0xDB); //--set vcomh
    writeCommand(0x20); //0x20,0.77xVcc
    writeCommand(0x8D); //--set DC-DC enable
    writeCommand(0x14); //
    writeCommand(0xAF); //--turn on oled panel

    // Clear screen
    clear();
    flush();
    HAL_Delay(100);

    /* Init screen */
    writeCommand(0xAE); //display off
    writeCommand(0x20); //Set Memory Addressing Mode
    writeCommand(
            0x10); //00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid
    writeCommand(0xB0); //Set Page Start Address for Page Addressing Mode,0-7
    writeCommand(0xC8); //Set COM Output Scan Direction
    writeCommand(0x00); //---set low column address
    writeCommand(0x10); //---set high column address
    writeCommand(0x40); //--set start line address
    writeCommand(0x81); //--set contrast control register
    writeCommand(0xFF);
    writeCommand(0xA1); //--set segment re-map 0 to 127
    writeCommand(0xA6); //--set normal display
    writeCommand(0xA8); //--set multiplex ratio(1 to 64)
    writeCommand(0x3F); //
    writeCommand(0xA4); //0xa4,Output follows RAM content;0xa5,Output ignores RAM content
    writeCommand(0xD3); //-set display offset
    writeCommand(0x00); //-not offset
    writeCommand(0xD5); //--set display clock divide ratio/oscillator frequency
    writeCommand(0xF0); //--set divide ratio
    writeCommand(0xD9); //--set pre-charge period
    writeCommand(0x22); //
    writeCommand(0xDA); //--set com pins hardware configuration
    writeCommand(0x12);
    writeCommand(0xDB); //--set vcomh
    writeCommand(0x20); //0x20,0.77xVcc
    writeCommand(0x8D); //--set DC-DC enable
    writeCommand(0x14); //
    writeCommand(0xAF); //--turn on oled panel

    clear();
    flush();
}

uint8_t allegory::stm32::OledDisplay::height() {
    return 64;
}

uint8_t allegory::stm32::OledDisplay::width() {
    return 128;
}

void allegory::stm32::OledDisplay::drawPixel(uint8_t x, uint8_t y, allegory::display::Color color) {
    if (x >= OLED_WIDTH || y >= OLED_HEIGHT) {
        return;
    }

    //TODO: support inverted color or not)

    if (color == display::Color::WHITE) {
        OLED_Buffer[x + (y / 8) * OLED_WIDTH] |= 1u << (y % 8u);
    } else {
        OLED_Buffer[x + (y / 8) * OLED_WIDTH] &= ~(1u << (y % 8u));
    }
}

void allegory::stm32::OledDisplay::flush() {
    uint8_t i;

    for (i = 0; i < 8; i++) {
        writeCommand(0xB0 + i);
        writeCommand(0x00);
        writeCommand(0x10);

        HAL_I2C_Mem_Write(&hi2c1, OLED_I2C_ADDR, 0x40, 1, &OLED_Buffer[OLED_WIDTH * i], OLED_WIDTH, 100);
    }
}

void allegory::stm32::OledDisplay::writeCommand(uint8_t command) {
    HAL_I2C_Mem_Write(&hi2c1, OLED_I2C_ADDR, 0x00, 1, &command, 1, 10);
}
