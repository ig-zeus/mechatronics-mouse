#pragma once

#include <Arduino.h>

#include "config.hpp"
#include "Motor.hpp"
#include "IMU.hpp"
#include "OLED.hpp"
#include "DualEncoder.hpp"
#include "MovingAverageFilter.hpp"
#include "PIDController.hpp"
#include "Lidar.hpp"

namespace mtrn3100 {

class Task4_1 {
public:
    Task4_1(
        Motor& motorA,
        Motor& motorB,
        IMU& imu,
        DualEncoder& encoder,
        OLED& oled,
        MovingAverageFilter& angleFilter,
        PIDController& turnController,
        PIDController& distanceController,
        Lidar& lidarLeft,
        Lidar& lidarRight,
        Lidar& lidarFront,
        MovingAverageFilter& distanceFilter
    )
        : motorA(motorA),
          motorB(motorB),
          imu(imu),
          encoder(encoder),
          oled(oled),
          angleFilter(angleFilter),
          turnController(turnController),
          distanceController(distanceController),
          lidarLeft(lidarLeft),
          lidarRight(lidarRight),
          lidarFront(lidarFront),
          distanceFilter(distanceFilter) {}

    void begin(const char* commands) {
        commandSequence = commands;
        sequenceComplete = false;

        stopMotors();
        imu.update();
    }

    void update() {
        // TODO: interpret and execute the supplied maze command sequence
    }

private:
    void driveForward(float distanceMm) {
        // TODO: drive the requested distance
    }

    void turnInPlace(float angleDegrees) {
        // TODO: rotate the robot by the requested angle
    }

    void stopMotors() {
        motorA.setPWM(0);
        motorB.setPWM(0);
    }

    Motor& motorA;
    Motor& motorB;

    IMU& imu;
    DualEncoder& encoder;
    OLED& oled;

    MovingAverageFilter& angleFilter;
    MovingAverageFilter& distanceFilter;

    PIDController& turnController;
    PIDController& distanceController;

    Lidar& lidarLeft;
    Lidar& lidarRight;
    Lidar& lidarFront;

    const char* commandSequence = nullptr;
    bool sequenceComplete = false;
};

} // namespace mtrn3100