#pragma once

#include <Arduino.h>
#include <math.h>

namespace mtrn3100 {

class Motor {
public:
    Motor(uint8_t pwmPin, uint8_t directionPin)
        : pwmPin(pwmPin), directionPin(directionPin) {

        pinMode(pwmPin, OUTPUT);
        pinMode(directionPin, OUTPUT);
    }

    // Set the motor direction and PWM output from a signed input value.
    void setPWM(int16_t command) {
        // TODO: implement motor control
    }

private:
    const uint8_t pwmPin;
    const uint8_t directionPin;
};

}  // namespace mtrn3100