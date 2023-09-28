#ifndef UUMOTOR_SERVO_MOTOR_DRIVER_H
#define UUMOTOR_SERVO_MOTOR_DRIVER_H

#include <string>
#include <vector>

using namespace std;

class Commands
{

    public:

    std::string model = "";
    int max_speed = 0;
    int max_amp = 0;
    int max_torque = 0;
    std::vector<unsigned char> command[8];

    Commands() = default;

    Commands(const std::string &model_name);

    void setup(const std::string &model_name);

    // Set Motor Parameters

    void set_control_mode(std::vector<unsigned char> &command, int motor, std::string mode);
    
    void set_location_mode(std::vector<unsigned char> &command, int motor, std::string mode);

    void set_acceleration_max(std::vector<unsigned char> &command, int motor, long value);

    void set_deceleration_max(std::vector<unsigned char> &command, int motor, long value);

    void set_speed(std::vector<unsigned char> &command, int motor, long speed);

    void set_current(std::vector<unsigned char> &command, int motor, long current);

    void set_sensor_type(std::vector<unsigned char> &command, int motor, std::string type);

    void control_motor(std::vector<unsigned char> &command, int motor, std::string cmd);

    void calibrate(std::vector<unsigned char> &command, int motor);

    // Read Motor Status

    void calibration_status(std::vector<unsigned char> &command, int motor);

    void motor_running(std::vector<unsigned char> &command, int motor);

    void motor_temp(std::vector<unsigned char> &command, int motor);

    void bus_voltage(std::vector<unsigned char> &command, int motor);

    void mos_tube_temp(std::vector<unsigned char> &command, int motor);

    void motor_speed(std::vector<unsigned char> &command, int motor);

    void motor_current(std::vector<unsigned char> &command, int motor);

    void absolute_position(std::vector<unsigned char> &command, int motor);

    void error_status(std::vector<unsigned char> &command, int motor);


};

#endif