#pragma once

#include <Arduino.h>

namespace mtrn3100 {
namespace config {

/*
 * ROBOT CONFIGURATION
 *
 * The values below were tuned for our particular robot and hardware setup.
 * They should be treated as reference/starting values only. Differences in
 * motors, batteries, sensors, friction and construction mean that the same
 * values may not work well on another robot.
 *
 * Expect to experimentally calibrate and fine-tune these parameters.
 */

// Hardware
namespace hardware {

constexpr uint8_t SENSOR_LEFT_ENABLE_PIN  = A0;
constexpr uint8_t SENSOR_RIGHT_ENABLE_PIN = A1;
constexpr uint8_t SENSOR_FRONT_ENABLE_PIN = A2;

constexpr uint8_t OLED_ADDRESS = 0x3C;

constexpr uint8_t MOTOR_A_PWM_PIN = 11;
constexpr uint8_t MOTOR_A_DIR_PIN = 12;
constexpr uint8_t MOTOR_B_PWM_PIN = 9;
constexpr uint8_t MOTOR_B_DIR_PIN = 10;

constexpr uint8_t ENCODER_LEFT_A_PIN  = 2;
constexpr uint8_t ENCODER_LEFT_B_PIN  = 7;
constexpr uint8_t ENCODER_RIGHT_A_PIN = 3;
constexpr uint8_t ENCODER_RIGHT_B_PIN = 8;

} // namespace hardware


// Controller starting values
namespace controller {

constexpr float TURN_KP = 4.5f;
constexpr float TURN_KI = 0.05f;
constexpr float TURN_KD = 0.2f;

constexpr float DISTANCE_KP = 0.8f;
constexpr float DISTANCE_KI = 0.001f;
constexpr float DISTANCE_KD = 0.02f;

} // namespace controller



// Filters
namespace filter {

constexpr size_t ANGLE_WINDOW = 3;
constexpr size_t ANGLE_WINDOW_TASK_4_2 = 1;

constexpr size_t DISTANCE_WINDOW = 8;
constexpr size_t LIDAR_WINDOW = 2;

} // namespace filter


// Task 4.1 tuning
namespace task_4_1 {

constexpr long COUNTS_PER_METRE = 6975;
constexpr float CELL_DISTANCE_MM = 180.0f;

constexpr int BASE_PWM = 140;

constexpr float MOTOR_A_MIN_PWM = 16.0f;
constexpr float MOTOR_B_MIN_PWM = 17.0f;
constexpr float MOTOR_BIAS = 1.05f;

constexpr float HEADING_KP = 5.0f;
constexpr float HEADING_KD = 0.2f;

constexpr float MAX_STEERING_CORRECTION = 55.0f;
constexpr float GYRO_FILTER_ALPHA = 0.2f;

constexpr float MAX_TURN_PWM = 140.0f;
constexpr float MIN_TURN_PWM = 17.0f;
constexpr float TURN_TOLERANCE_DEG = 1.2f;

constexpr int LEFT_ENCODER_SIGN = 1;
constexpr int RIGHT_ENCODER_SIGN = -1;
constexpr int STEERING_SIGN = 1;

constexpr int MIN_VALID_DISTANCE_MM = 15;
constexpr int MAX_WALL_DISTANCE_MM = 75;
constexpr float NOMINAL_WALL_DISTANCE_MM = 50.0f;

constexpr float WALL_KP = 1.2f;
constexpr float MAX_WALL_CORRECTION_PWM = 18.0f;

constexpr int FRONT_STOP_DISTANCE_MM = 25;

} // namespace task_4_1


// Task 4.2 tuning
namespace task_4_2 {

constexpr long COUNTS_PER_METRE = 7000;

constexpr int BASE_PWM = 105;

constexpr float MOTOR_A_MIN_PWM = 16.0f;
constexpr float MOTOR_B_MIN_PWM = 17.0f;
constexpr float MOTOR_BIAS = 1.01f;

constexpr float HEADING_KP = 5.0f;
constexpr float HEADING_KD = 0.2f;

constexpr float MAX_STEERING_CORRECTION = 55.0f;
constexpr float GYRO_FILTER_ALPHA = 0.2f;

constexpr float MAX_TURN_PWM = 55.0f;
constexpr float MIN_TURN_PWM = 19.0f;
constexpr float TURN_TOLERANCE_DEG = 0.5f;

constexpr int LEFT_ENCODER_SIGN = 1;
constexpr int RIGHT_ENCODER_SIGN = -1;
constexpr int STEERING_SIGN = 1;

constexpr int MIN_VALID_DISTANCE_MM = 15;
constexpr int MAX_WALL_DISTANCE_MM = 80;
constexpr float NOMINAL_WALL_DISTANCE_MM = 50.0f;

constexpr float WALL_KP = 1.5f;
constexpr float MAX_WALL_CORRECTION_PWM = 22.0f;

constexpr int FRONT_STOP_DISTANCE_MM = 25;

} // namespace task_4_2


// Task 4.3 tuning
namespace task_4_3 {

constexpr long COUNTS_PER_METRE = 6985;

constexpr int BASE_PWM = 140;

constexpr float MOTOR_A_MIN_PWM = 16.0f;
constexpr float MOTOR_B_MIN_PWM = 17.0f;
constexpr float MOTOR_BIAS = 1.05f;

constexpr float HEADING_KP = 5.0f;
constexpr float HEADING_KD = 0.2f;

constexpr float MAX_STEERING_CORRECTION = 55.0f;
constexpr float GYRO_FILTER_ALPHA = 0.2f;

constexpr float MAX_TURN_PWM = 115.0f;
constexpr float MIN_TURN_PWM = 17.0f;
constexpr float TURN_TOLERANCE_DEG = 0.5f;

constexpr int LEFT_ENCODER_SIGN = 1;
constexpr int RIGHT_ENCODER_SIGN = -1;
constexpr int STEERING_SIGN = 1;

constexpr int MIN_VALID_DISTANCE_MM = 15;
constexpr int MAX_WALL_DISTANCE_MM = 80;
constexpr float NOMINAL_WALL_DISTANCE_MM = 50.0f;

constexpr float WALL_KP = 1.5f;
constexpr float MAX_WALL_CORRECTION_PWM = 22.0f;

constexpr int FRONT_STOP_DISTANCE_MM = 25;

} // namespace task_4_3

} // namespace config
} // namespace mtrn3100