#pragma once

#include <Arduino.h>
#include <VL6180X.h>

namespace mtrn3100 {

class Lidar {
public:
    Lidar(uint8_t pin) : pin(pin) {}

    void initLidar(int16_t timeout, int16_t address) {
        // TODO: initialise and configure the sensor
    }

    uint16_t readRangeSingleMillimeters() {
        // TODO: return the measured distance
        return 0;
    }

    bool timeoutOccurred() {
        // TODO: report whether a timeout occurred
        return false;
    }

private:
    VL6180X sensor;
    const uint8_t pin;
};

}  // namespace mtrn3100