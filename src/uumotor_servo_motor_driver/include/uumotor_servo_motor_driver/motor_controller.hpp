#ifndef UUMOTOR_SERVO_MOTOR_DRIVER_MOTOR_CONTROLLER_HPP
#define UUMOTOR_SERVO_MOTOR_DRIVER_MOTOR_CONTROLLER_HPP

#include <string>
#include <iostream>

#include "rclcpp/rclcpp.hpp"
#include "uumotor_servo_motor_driver/comms.hpp"
#include "uumotor_servo_motor_driver/functions.h"
#include "uumotor_servo_motor_driver/commands.h"

class MotorController
{

    public:
        Comms serial_;
        Commands commands_;
        MotorController() = default;

        void select_model(std::string model)
        {
            commands_.setup(model);
        }

        void connect_to_driver(std::string port, int32_t baud_rate, int32_t timeout)
        {
            serial_.connect(port, baud_rate, timeout);
        }

        void drive_motor(int motor)
        {
            cmd = commands_.control_motor(motor, "start");
            serial_.send_command(cmd);
        }

        void set_motor_parameters(int motor, std::string control_mode, int max_speed, int min_speed, 
                                  int max_amp, std::string sensor_type)
        {
            cmd = commands_.set_control_mode(motor, control_mode);
            serial_.send_command(cmd);
            cmd = commands_.set_acceleration_max(motor, max_speed);
            serial_.send_command(cmd);
            cmd = commands_.set_deceleration_max(motor, min_speed);
            serial_.send_command(cmd);
            cmd = commands_.set_current(motor, max_amp);
            serial_.send_command(cmd);
            cmd = commands_.set_sensor_type(motor, sensor_type);
        }

        void change_current(int motor, float current)
        {
            int current_fix = static_cast<int>(current*100);
            cmd = commands_.set_current(motor, current_fix);
            serial_.send_command(cmd);
        }

        void set_motor_speed(int motor, int speed)
        {
            cmd = commands_.set_speed(motor, speed);
            serial_.send_command(cmd);
        }

        void stop_motor(int motor)
        {
            cmd = commands_.control_motor(motor, "stop");
        }

        bool motor_running(int motor)
        {
            cmd = commands_.motor_running(motor);
            serial_.send_command(cmd);

            return true;
        }

        float read_temp(int motor)
        {
            cmd = commands_.motor_temp(motor);
            serial_.send_command(cmd);
            return 0.0; 
        }

        float read_volt(int motor)
        {
            cmd = commands_.bus_voltage(motor);
            serial_.send_command(cmd);

            return 0.0;
        }

        double get_absolute_position(int motor)
        {
            cmd = commands_.absolute_position(motor);
            serial_.send_command(cmd);

            return 0.0;
        }

        void calibrate(int motor)
        {
            cmd = commands_.calibrate(motor);
            serial_.send_command(cmd);
        }

        int calibration_status(int motor)
        {
            cmd = commands_.calibration_status(motor);
            serial_.send_command(cmd);

            return 0;
        }

        int error_status(int motor)
        {
            cmd = commands_.error_status(motor);
            serial_.send_command(cmd);

            return 0;
        }
    

    private:
        
        std::vector<uint8_t> cmd;
        

};



#endif //UUMOTOR_SERVO_MOTOR_DRIVER_MOTOR_CONTROLLER_HPP