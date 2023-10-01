#ifndef UUMOTOR_SERVO_MOTOR_DRIVER_H
#define UUMOTOR_SERVO_MOTOR_DRIVER_H

#include <string>
#include <vector>
#include "uumotor_servo_motor_driver/functions.h"

using namespace std;

class Commands
{

public:

   

    Commands() = default;

    Commands(const std::string &model_name);

    void setup(const std::string &model_name);

    // Set Motor Parameters

    std::vector<uint8_t> set_control_mode(int motor, std::string mode);
    
    std::vector<uint8_t> set_location_mode(int motor, std::string mode);

    std::vector<uint8_t> set_acceleration_max(int motor, int value);

    std::vector<uint8_t> set_deceleration_max(int motor, int value);

    std::vector<uint8_t> set_speed(int motor, int speed);

    std::vector<uint8_t> set_current(int motor, int current);

    std::vector<uint8_t> set_sensor_type(int motor, std::string type);

    std::vector<uint8_t> control_motor(int motor, std::string cmd);

    std::vector<uint8_t> calibrate(int motor);

    // Read Motor Status

    std::vector<uint8_t> calibration_status(int motor);

    std::vector<uint8_t> motor_running(int motor);

    std::vector<uint8_t> motor_temp(int motor);

    std::vector<uint8_t> bus_voltage(int motor);

    std::vector<uint8_t> mos_tube_temp(int motor);

    std::vector<uint8_t> motor_speed(int motor);

    std::vector<uint8_t> motor_current(int motor);

    std::vector<uint8_t> absolute_position(int motor);

    std::vector<uint8_t> error_status(int motor);

private:
    Functions fun;
    std::string model_ = "";
    int max_speed_ = 0;
    int max_amp_ = 0;
    int max_torque_ = 0;

};

#endif