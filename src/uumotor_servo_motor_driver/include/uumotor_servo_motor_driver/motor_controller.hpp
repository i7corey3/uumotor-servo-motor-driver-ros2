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
        bool run_motor = false;
        bool is_calibrate = false;
        std::string command;

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
            msg = serial_.send_command(cmd, 7);
            
            bool check = fun_.check_message(msg.data(), msg.size());
            if (check)
            {
                int running = fun_.message_decoder(msg.data(), 16, true, msg.size());

                if (running) return true;
                else return false;
                
            }
            else RCLCPP_INFO(rclcpp::get_logger("motor_running"), "Error: Invalid Message"); return false;
            
        }

        float read_temp(int motor)
        {
            cmd = commands_.motor_temp(motor);
            msg = serial_.send_command(cmd, 7);
            
            bool check = fun_.check_message(msg.data(), msg.size());
            if (check)
            {
                int temp = fun_.message_decoder(msg.data(), 16, false, msg.size());
                // float temp_fix = static_cast<float>(temp);
                
                return temp / -10.0;
                
            }
            else RCLCPP_INFO(rclcpp::get_logger("read_temp"), "Error: Invalid Message"); return 0.0;
            
        }

        float read_volt(int motor)
        {
            cmd = commands_.bus_voltage(motor);
            msg = serial_.send_command(cmd, 7);

            bool check = fun_.check_message(msg.data(), msg.size());
            if (check)
            {
                int volt = fun_.message_decoder(msg.data(), 16, false, msg.size());
                // float temp_fix = static_cast<float>(temp);
                
                return volt / 10.0;
                
            }
            else RCLCPP_INFO(rclcpp::get_logger("read_volt"), "Error: Invalid Message"); return 0.0;
            
        }

        long get_absolute_position(int motor)
        {
            cmd = commands_.absolute_position(motor);
            msg = serial_.send_command(cmd, 9);

            bool check = fun_.check_message(msg.data(), msg.size());
            if (check)
            {
                int encoder = fun_.message_decoder(msg.data(), 32, false, msg.size());
                // float temp_fix = static_cast<float>(temp);
                
                return encoder;
                
            }
            else RCLCPP_INFO(rclcpp::get_logger("get_absolute_position"), "Error: Invalid Message"); return 0.0;
            
        }

        void calibrate(int motor)
        {
            cmd = commands_.calibrate(motor);
            serial_.send_command(cmd);
        }

        int calibration_status(int motor)
        {
            cmd = commands_.calibration_status(motor);
            msg = serial_.send_command(cmd);

            bool check = fun_.check_message(msg.data(), msg.size());
            if (check)
            {
                int status = fun_.message_decoder(msg.data(), 16, true, msg.size());
                
                return status;
                
            }
            else RCLCPP_INFO(rclcpp::get_logger("calibration_status"), "Error: Invalid Message"); return 0.0;
            
        }

        int error_status(int motor)
        {
            cmd = commands_.error_status(motor);
            serial_.send_command(cmd);

            bool check = fun_.check_message(msg.data(), msg.size());
            if (check)
            {
                int error = fun_.message_decoder(msg.data(), 32, true, msg.size());
                
                return error;
                
            }
            else RCLCPP_INFO(rclcpp::get_logger("error_status"), "Error: Invalid Message"); return 0.0;
            
        }
    

    private:
        Comms serial_;
        Commands commands_;
        Functions fun_;
        std::vector<uint8_t> cmd;
        std::vector<uint8_t> msg;

        

};



#endif //UUMOTOR_SERVO_MOTOR_DRIVER_MOTOR_CONTROLLER_HPP