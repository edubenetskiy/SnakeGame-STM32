#include <sstream>
#include "MainMenu.h"
#include "../fonts/Text.h"

allegory::snake::MainMenu::MainMenu(allegory::display::AbstractDisplayDevice &displayDevice,
                                    allegory::keyboard::AbstractKeyboard &keyboardDevice,
                                    allegory::timer::AbstractTimer &timerDevice) :
        displayDevice(displayDevice), keyboardDevice(keyboardDevice), timer(timerDevice) {

}

allegory::snake::GameLevel allegory::snake::MainMenu::run() {

    GameLevel currentLevel = GameLevel::MEDIUM;

    while (keyboardDevice.pollKey() != keyboard::Key::FIVE) {
        displayDevice.clear();
        allegory::fonts::Text("Level", allegory::fonts::FONT_11x18).renderCentered(displayDevice, 15);

        switch (keyboardDevice.pollKey()) {
            case keyboard::Key::FOUR:
                currentLevel = GameLevel(static_cast<GameLevel::Value>((currentLevel + 2) % 3));
                break;
            case keyboard::Key::SIX:
                currentLevel = GameLevel(static_cast<GameLevel::Value>((currentLevel + 1) % 3));
                break;
            default:
                break;
        }

        std::ostringstream stringStream;
        stringStream << "< ";
        stringStream << currentLevel;
        stringStream << " >";
        std::string levelString = stringStream.str();

        allegory::fonts::Text(levelString, allegory::fonts::FONT_7x10).renderCentered(displayDevice, 35);
        allegory::fonts::Text("Press 5 to play", allegory::fonts::FONT_7x10).renderCentered(displayDevice, 50);
        displayDevice.flush();

        timer.sleepFor(std::chrono::milliseconds(75));
    }

    displayDevice.clear();

    return currentLevel;
}

