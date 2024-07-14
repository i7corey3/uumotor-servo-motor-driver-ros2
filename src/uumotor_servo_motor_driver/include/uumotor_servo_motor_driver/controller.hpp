#ifndef UUMOTOR_SERVO_MOTOR_DRIVER_CONTROLLER_HPP
#define UUMOTOR_SERVO_MOTOR_DRIVER_CONTROLLER_HPP

#include <thread>
#include <string>
#include <iostream>
#include "rclcpp/rclcpp.hpp"
#include "uumotor_servo_motor_driver/motor_controller.hpp"

class Controller
{

    public:
        
        Controller() = default;

        void change_speed(int motor, double speed)
        {
            
            if (motor == 1)
            {
                MC.command = "change_speed";
                motor_speed = speed;
                
            }
            else std::cout << "Invalid Motor" << '\n';
        }

        void change_current(int motor, double current)
        {
            if (motor == 1) MC.change_current(motor, current);
            else std::cout << "Invalid Motor" << '\n';
        }

        void stop_motor(int motor)
        {
            if (motor == 1) MC.run_motor = false;
            else std::cout << "Invalid Motor" << '\n';
        }

        void start_motor(int motor)
        {
            if (motor == 1) MC.run_motor = true;
            else std::cout << "Invalid Motor" << '\n';
        }

        bool motor_running(int motor)
        {
            if (motor == 1) return MC.motor_running(motor);
            else 
            {
                std::cout << "Invalid Motor" << '\n'; 
                return false;
            } 
        }

        float read_temp(int motor)
        {
            if (motor == 1) return MC.read_temp(motor);
            else 
            {
                std::cout << "Invalid Motor" << '\n'; 
                return 0.0;
            }
        }

        float read_volt(int motor)
        {
            if (motor == 1) return MC.read_volt(motor);
            else 
            {
                std::cout << "Invalid Motor" << '\n';
                return 0.0;
            }
        }

        long get_absolute_position(int motor)
        {
            if (motor == 1) return MC.get_absolute_position(motor);
            else 
            {
                std::cout << "Invalid Motor" << '\n'; 
                return 0;
            }
        }

        void calibrate_motor(int motor)
        {
            if (motor == 1)
            {
                MC.run_motor = false;
                MC.calibrate(motor);
                MC.is_calibrate = true;
            }
        }

        void start_demo()
        {
            std::thread monitor_thread (&Controller::monitor, this);
            std::string cm;
            std::string val;
            std::size_t del_pos;
            std::string cmd;

            const char *text = 
                " Motor Controller Test\n "
                "Type ca to calibrate,\n "
                "Type s to run motor,\n "
                "Type x to stop motor,\n "
                "Type cs (value) to change speed,\n "
                "Type cc (value) to change the current,\n "
                "Type mr to check if motor is running,\n "
                "Type rt to read motor temp,\n "
                "Type rv to read bus voltage,\n "
                "Type ap to read absolute position,\n "
                "Type q to quit";


            while (true){
                try {
                    std::cout << text << std::endl;
                    getline( cin, cmd);

                    del_pos = cmd.find(" ");
                    cm = cmd.substr(0, del_pos);
                    val = cmd.substr(del_pos);
                    
                    if (cm == "ca") calibrate_motor(1);
                    else if (cm == "s") start_motor(1);
                    else if (cm == "x") stop_motor(1);
                    else if (cm == "cs") change_speed(1, std::atof(val.c_str()));
                    else if (cm == "cc") change_current(1, std::atof(val.c_str()));
                    else if (cm == "mr") std::cout << motor_running(1) << std::endl;
                    else if (cm == "rt") std::cout << read_temp(1)<< std::endl;
                    else if (cm == "rv") std::cout << read_volt(1) << std::endl;
                    else if (cm == "ap") std::cout << get_absolute_position(1) << std::endl;
                    else if (cm == "q") break; 
                }
                catch (int e)
                {

                }
            }

        }


    private:
        MotorController MC;
        double motor_speed = 0;
        void monitor()
        {
            
            long encoder_val;
            MC.select_model("svh4d");
            MC.connect_to_driver("/dev/ttyUSB0", 115200, 1000);
            MC.set_motor_parameters(1, "speed", 200, -200, 2,"hall");
            while (true)
            {
                if (MC.command == "change_speed")
                {
                    
                    MC.set_motor_speed(1, motor_speed);
                    MC.command = "";
                }
                if (MC.run_motor)
                {
                    MC.drive_motor(1);
                    encoder_val = MC.get_absolute_position(1);
                    std::cout << encoder_val << "\n";
                }
                if (MC.is_calibrate)
                {
                    if (MC.calibration_status(1) == 1)
                    {
                        std::cout << "Calibration Complete" << std::endl;
                        MC.is_calibrate = false;
                    }
                    else if (MC.calibration_status(1) == 2)
                    {
                        std::cout << "Calibration Failed" << std::endl;
                        MC.is_calibrate = false;
                    }
                    else
                    {
                        std::cout << "Calibrating" << std::endl;
                    }
                }
                
            }
        }

        

};





#endif //UUMOTOR_SERVO_MOTOR_DRIVER_CONTROLLER_HPP
