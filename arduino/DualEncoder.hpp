#pragma once

#include <Arduino.h>

namespace mtrn3100 {

class DualEncoder {
public:
    DualEncoder(uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4) {
        // TODO: initialise encoder inputs
    }

    void readLeftEncoder() {
        // TODO
    }

    void readRightEncoder() {
        // TODO
    }

    float getLeftRotation() {
        // TODO
        return 0.0f;
    }

    float getRightRotation() {
        // TODO
        return 0.0f;
    }

private:
    // TODO: store any required encoder state
};

}  // namespace mtrn3100