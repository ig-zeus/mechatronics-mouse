#pragma once

#include <math.h>

namespace mtrn3100 {

class PIDController {
public:
    PIDController(float p, float i, float d)
        : pGain(p), iGain(i), dGain(d) {}

    // Compute the controller output from the current measured value.
    float compute(float input) {
        // TODO: implement PID control
        return 0.0f;
    }

    void tune(float p, float i, float d) {
        pGain = p;
        iGain = i;
        dGain = d;
    }

    float getError() {
        return error;
    }

    // Reset the controller and configure a new reference and target.
    void zeroAndSetTarget(float zero, float target) {
        // TODO: reset controller state and update target
    }

private:
    float pGain, iGain, dGain;
    float error = 0;
};

}  // namespace mtrn3100