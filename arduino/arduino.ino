#include <SPI.h>
#include <Wire.h>
#include <MPU6050_light.h>

#include "config.hpp"
#include "IMU.hpp"
#include "Lidar.hpp"
#include "OLED.hpp"
#include "PIDController.hpp"
#include "Motor.hpp"
#include "DualEncoder.hpp"
#include "MovingAverageFilter.hpp"

#define TASK_MAZE        1
#define TASK_CUSTOM      2
#define TASK_MAPPING     3

// Select the task to run
#define SELECTED_TASK TASK_CUSTOM 

// Shared Hardware Global Objects
mtrn3100::Lidar sensor1(SENSOR1_PIN);
mtrn3100::Lidar sensor2(SENSOR2_PIN);
mtrn3100::Lidar sensor3(SENSOR3_PIN);
mtrn3100::OLED oled;
mtrn3100::Motor motor1(MOT1_PWM, MOT1_DIR);
mtrn3100::Motor motor2(MOT2_PWM, MOT2_DIR);
mtrn3100::IMU imu(Wire);
mtrn3100::PIDController turnPID(TURN_KP, TURN_KI, TURN_KD);
mtrn3100::PIDController distPID(DIST_KP, DIST_KI, DIST_KD);
mtrn3100::DualEncoder encoder(LEFT_ENC_A, LEFT_ENC_B, RIGHT_ENC_A, RIGHT_ENC_B);


#if SELECTED_TASK == TASK_MAZE
    #include "task4_1.hpp"
    MovingAverageFilter angleFilter(ANGLE_FILTER_SIZE);
    MovingAverageFilter lidarDistanceFilter(LIDAR_DIST_FILTER_SIZE);
    mtrn3100::Task4_1 activeTask(motor1, motor2, imu, encoder, oled, angleFilter, turnPID, distPID, sensor1, sensor2, sensor3, lidarDistanceFilter);

#elif SELECTED_TASK == TASK_CUSTOM
    #include "task4_2.hpp"
    MovingAverageFilter angleFilter2(ANGLE_FILTER_SIZE_4_2);
    MovingAverageFilter lidarDistanceFilter(LIDAR_DIST_FILTER_SIZE);
    mtrn3100::Task4_2 activeTask(motor1, motor2, imu, encoder, oled, angleFilter2, turnPID, distPID, sensor1, sensor2, sensor3, lidarDistanceFilter);
    
    // TODO: define the required motion-command sequence.
    constexpr mtrn3100::MotionCommand MOTION_COMMANDS[] = {
        // take as an example
        // {angle_degrees, distance_mm},
    };

#elif SELECTED_TASK == TASK_MAPPING
    #include "task4_3.hpp"
    MovingAverageFilter angleFilter(ANGLE_FILTER_SIZE);
    MovingAverageFilter lidarDistanceFilter(LIDAR_DIST_FILTER_SIZE);
    mtrn3100::Task4_3 activeTask(motor1, motor2, imu, encoder, oled, angleFilter, turnPID, distPID, sensor1, sensor2, sensor3, lidarDistanceFilter);

#endif

void setup() {
    Serial.begin(115200);
    Wire.begin();
    Wire.setWireTimeout(3000, true); 

    delay(2000);
    
    // Initialise the three distance sensors.
    //
    // Since the sensors initially share an I2C address, consider how they
    // should be enabled and assigned individual addresses.
    //
    // TODO: initialise the LiDAR sensors.

    if (!oled.begin()) { // Simplified to use OLED default args
        for(;;);
    }

    imu.init(oled);

    #if SELECTED_TASK == TASK_MAZE
        activeTask.begin("rflf");

    #elif SELECTED_TASK == TASK_CUSTOM
        activeTask.begin(MOTION_COMMANDS, sizeof(MOTION_COMMANDS) / sizeof(MOTION_COMMANDS[0]));
    
    #elif SELECTED_TASK == TASK_MAPPING
        activeTask.begin(
            // TODO: configure the required start position, orientation and goal.
        );

    #endif
}

void loop() {
    activeTask.update();
}