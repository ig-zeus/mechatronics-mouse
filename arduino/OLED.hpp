#pragma once

#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

namespace mtrn3100 {

class OLED {
public:
    U8G2_SSD1306_128X64_NONAME_1_HW_I2C display;

    OLED() : display(U8G2_R0, U8X8_PIN_NONE) {}

    bool begin(uint8_t address = 0x3C) {
        display.setI2CAddress(address * 2);
        display.begin();
        return true;
    }

    void showMessage(const char* firstLine, const char* secondLine = nullptr) {
        // TODO: display one or two lines of text
    }

    void clear() {
        // TODO
    }

    void setTextSize(uint8_t size) {
        // TODO: select an appropriate display font
    }

    void drawMazeState(
        uint8_t maze[9][9],
        uint8_t robotRow,
        uint8_t robotCol,
        int visitedCount,
        uint8_t phase
    ) {
        // TODO: visualise the current maze and robot state
    }
};

} // namespace mtrn3100