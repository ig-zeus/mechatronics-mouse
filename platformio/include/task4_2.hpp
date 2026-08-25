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

struct MotionCommand {
    float angle;
    float distance_mm;
};

class Task4_2 {
public:
    Task4_2(
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

    void begin(const MotionCommand* commands, size_t count) {
        commandSequence = commands;
        commandCount = count;
        currentCommand = 0;
        sequenceComplete = false;

        stopMotors();
        imu.update();
    }

    void update() {
        // TODO: execute the supplied sequence of motion commands
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

    const MotionCommand* commandSequence = nullptr;
    size_t commandCount = 0;
    size_t currentCommand = 0;

    bool sequenceComplete = false;
};

} // namespace mtrn3100