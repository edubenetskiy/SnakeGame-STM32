#include "SplashScreen.h"
#include "../fonts/Font.h"
#include "../fonts/Text.h"

allegory::snake::SplashScreen::SplashScreen(
        allegory::display::AbstractDisplayDevice &displayDevice,
        allegory::keyboard::AbstractKeyboard &keyboardDevice) :
        keyboardDevice(keyboardDevice), displayDevice(displayDevice) {

}

void allegory::snake::SplashScreen::run() {
    displayDevice.clear();
    allegory::fonts::Text("SnanS!", allegory::fonts::FONT_16x26).renderCentered(displayDevice, 5);
    allegory::fonts::Text("THE GAME", allegory::fonts::FONT_11x18).renderCentered(displayDevice, 30);
    allegory::fonts::Text("Press to play", allegory::fonts::FONT_7x10).renderCentered(displayDevice, 50);
    displayDevice.flush();

    while (keyboardDevice.pollKey() == keyboard::Key::NONE) {
        // Wait
    }

    displayDevice.clear();
}
