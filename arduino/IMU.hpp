#pragma once

#include <Arduino.h>
#include <Wire.h>
#include <MPU6050_light.h>
#include "OLED.hpp"

namespace mtrn3100 {

class IMU {
public:
    IMU(TwoWire& wire) : sensor(wire) {}

    void init(OLED& oled) {
        // TODO: initialise and calibrate the IMU
    }

    void update() {
        sensor.update();
    }

    float getAngleZ() {
        return sensor.getAngleZ();
    }

    float getGyroZ() {
        return sensor.getGyroZ();
    }

private:
    MPU6050 sensor;
};

} // namespace mtrn3100