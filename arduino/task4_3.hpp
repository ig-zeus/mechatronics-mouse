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

class Task4_3 {
public:
    Task4_3(
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

    void begin(
        uint8_t startRow,
        uint8_t startCol,
        uint8_t startDirection,
        uint8_t goalRow,
        uint8_t goalCol
    ) {
        currentRow = startRow;
        currentCol = startCol;
        currentDirection = startDirection;

        targetRow = goalRow;
        targetCol = goalCol;

        complete = false;

        // TODO: initialise any mapping/navigation state

        stopMotors();
        imu.update();
    }

    void update() {
        // TODO: update the maze state and navigate toward the goal
    }

private:
    void updateMap() {
        // TODO: incorporate current sensor observations
    }

    void updateDisplay() {
        // TODO: visualise the current navigation state
    }

    bool driveForward(float distanceMm) {
        // TODO: drive the requested distance
        return false;
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

    uint8_t currentRow = 0;
    uint8_t currentCol = 0;
    uint8_t currentDirection = 0;

    uint8_t targetRow = 0;
    uint8_t targetCol = 0;

    bool complete = false;

    // TODO: add an appropriate representation for the maze/navigation state
};

} // namespace mtrn3100