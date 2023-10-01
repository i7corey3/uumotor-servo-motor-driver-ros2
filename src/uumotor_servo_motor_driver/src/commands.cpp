#include "uumotor_servo_motor_driver/commands.h"
#include "rclcpp/rclcpp.hpp"

Commands::Commands(const std::string &model_name)
{
    setup(model_name);
}

void Commands::setup(const std::string &model_name)
{
    if (model_name == "svd6h2")
    {
        model_ = model_name;
        max_speed_ = 500;
        max_amp_ = 20;
        max_torque_ = 20;
    }
    // default driver
    else
    {
        model_ = "svd6h2";
        max_speed_ = 500;
        max_amp_ = 20;
        max_torque_ = 20;
    }
    
}

//
//
// SET MOTOR PARAMETERS //
//
// 

std::vector<uint8_t> Commands::set_control_mode(int motor, std::string mode)
{
    std::vector<uint8_t> command = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    if (mode == "speed")
    {
        switch (motor)
        {
            case 1:
                command = {0xEE, 0x06, 0x51, 0x00, 0x00, 0x00, 0xFF, 0xFF};
                fun.get_hex_msg(command.data());   
                return command;

            case 2:
                command = {0xEE, 0x06, 0x51, 0x01, 0x00, 0x00, 0xFF, 0xFF};
                fun.get_hex_msg(command.data());
               
                return command;

            default:
                RCLCPP_INFO(rclcpp::get_logger("set_control_mode"), "Error: Invaild Motor");
                return command;
        }
    }
    else if (mode == "position")
    {
        switch (motor)
        {
            case 1:
                command = {0xEE, 0x06, 0x51, 0x00, 0x00, 0x01, 0xFF, 0xFF};
                fun.get_hex_msg(command.data());
              
                return command;

            case 2:
                command = {0xEE, 0x06, 0x51, 0x01, 0x00, 0x01, 0xFF, 0xFF};
                fun.get_hex_msg(command.data());
             
                return command;

            default:
                RCLCPP_INFO(rclcpp::get_logger("set_control_mode"), "Error: Invaild Motor");
                return command;
        }
    }
    else if (mode == "torque")
    {
        switch (motor)
        {
            case 1:
                command = {0xEE, 0x06, 0x51, 0x00, 0x00, 0x02, 0xFF, 0xFF};
                fun.get_hex_msg(command.data());
                    
                return command;

            case 2:
                command = {0xEE, 0x06, 0x51, 0x01, 0x00, 0x02, 0xFF, 0xFF};
                fun.get_hex_msg(command.data());
           
                return command;

            default:
                RCLCPP_INFO(rclcpp::get_logger("set_control_mode"), "Error: Invaild Motor");
                return command;
        }
    }

    else if (mode == "voltage")
    {
        switch (motor)
        {
            case 1:
                command = {0xEE, 0x06, 0x51, 0x00, 0x00, 0x03, 0xFF, 0xFF};
                fun.get_hex_msg(command.data());
                  
                return command;

            case 2:
                command = {0xEE, 0x06, 0x51, 0x01, 0x00, 0x03, 0xFF, 0xFF};
                fun.get_hex_msg(command.data());
           
                return command;

            default:
                RCLCPP_INFO(rclcpp::get_logger("set_control_mode"), "Error: Invaild Motor");
                return command;
        }
    }

    else if (mode == "skateboard")
    {
        switch (motor)
        {
            case 1:
                command = {0xEE, 0x06, 0x51, 0x00, 0x00, 0x04, 0xFF, 0xFF};
                fun.get_hex_msg(command.data());
            
                return command;

            case 2:
                command = {0xEE, 0x06, 0x51, 0x01, 0x00, 0x04, 0xFF, 0xFF};
                fun.get_hex_msg(command.data());
          
                return command;

            default:
                RCLCPP_INFO(rclcpp::get_logger("set_control_mode"), "Error: Invaild Motor");
                return command;
        }
    }
    else if (mode == "karting")
    {
        switch (motor)
        {
            case 1:
                command = {0xEE, 0x06, 0x51, 0x00, 0x00, 0x05, 0xFF, 0xFF};
                fun.get_hex_msg(command.data());
               
                return command;

            case 2:
                command = {0xEE, 0x06, 0x51, 0x01, 0x00, 0x05, 0xFF, 0xFF};
                fun.get_hex_msg(command.data());
           
                return command;

            default:
                RCLCPP_INFO(rclcpp::get_logger("set_control_mode"), "Error: Invaild Motor");
                return command;
        }
    }
    else
    {
        RCLCPP_INFO(rclcpp::get_logger("set_control_mode"), "Error: Invaild Mode");
        return command;
    }
    
}

std::vector<uint8_t> Commands::set_location_mode(int motor, std::string mode)
{
    std::vector<uint8_t> command = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    if (mode == "absolute")
    {
        switch(motor)
        {
            case 1:
                command = {0xEE, 0x06, 0x51, 0x04, 0x00, 0x00, 0xFF, 0xFF};
                fun.get_hex_msg(command.data());

                return command;
            case 2:
                command = {0xEE, 0x06, 0x51, 0x05, 0x00, 0x00, 0xFF, 0xFF};
                fun.get_hex_msg(command.data());

                return command;
            default:
                RCLCPP_INFO(rclcpp::get_logger("set_location_mode"), "Error: Invaild Motor");
                return command;
            
        }
    }
    else if (mode == "relative")
    {
        switch(motor)
        {
            case 1:
                command = {0xEE, 0x06, 0x51, 0x04, 0x00, 0x01, 0xFF, 0xFF};
                fun.get_hex_msg(command.data());

                return command;
            case 2:
                command = {0xEE, 0x06, 0x51, 0x05, 0x00, 0x01, 0xFF, 0xFF};
                fun.get_hex_msg(command.data());

                return command;
            default:
                RCLCPP_INFO(rclcpp::get_logger("set_location_mode"), "Error: Invaild Motor");
                return command;
        }
    }
    else
    {
        RCLCPP_INFO(rclcpp::get_logger("set_location_mode"), "Error: Invaild Mode");
        return command;
    }

}

std::vector<uint8_t> Commands::set_acceleration_max(int motor, int value)
{
    std::vector<uint8_t> command = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    std::vector<uint8_t> v = fun.int2hex(value, max_speed_, true);
    switch (motor)
    {
        case 1:
            command = {0xEE, 0x06, 0x51, 0x08, v[0], v[1], 0xFF, 0xFF};
            fun.get_hex_msg(command.data());

            return command;

        case 2:
            command = {0xEE, 0x06, 0x51, 0x0C, v[0], v[1], 0xFF, 0xFF};
            fun.get_hex_msg(command.data());

            return command;

        default:
            RCLCPP_INFO(rclcpp::get_logger("set_acceleration_max"), "Error: Invaild Motor");
            return command;
    }
}

std::vector<uint8_t> Commands::set_deceleration_max(int motor, int value)
{
    std::vector<uint8_t> command = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    std::vector<uint8_t> v = fun.int2hex(value, max_speed_, true);
    switch (motor)
    {
        case 1:
            command = {0xEE, 0x06, 0x51, 0x09, v[0], v[1], 0xFF, 0xFF};
            fun.get_hex_msg(command.data());

            return command;

        case 2:
            command = {0xEE, 0x06, 0x51, 0x0D, v[0], v[1], 0xFF, 0xFF};
            fun.get_hex_msg(command.data());

            return command;

        default:
            RCLCPP_INFO(rclcpp::get_logger("set_deceleration_max"), "Error: Invaild Motor");
            return command;
    }
}

std::vector<uint8_t> Commands::set_speed(int motor, int speed)
{
    std::vector<uint8_t> command = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    std::vector<uint8_t> v = fun.int2hex(speed, max_speed_, true);
    switch (motor)
    {
        case 1:
            command = {0xEE, 0x06, 0x53, 0x04, v[0], v[1], 0xFF, 0xFF};
            fun.get_hex_msg(command.data());

            return command;

        case 2:
            command = {0xEE, 0x06, 0x53, 0x05, v[0], v[1], 0xFF, 0xFF};
            fun.get_hex_msg(command.data());

            return command;

        default:
            RCLCPP_INFO(rclcpp::get_logger("set_speed"), "Error: Invaild Motor");
            return command;
    }
}

std::vector<uint8_t> Commands::set_current(int motor, int current)
{
    std::vector<uint8_t> command = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    std::vector<uint8_t> v = fun.int2hex(current, max_amp_, true);
    switch (motor)
    {
        case 1:
            command = {0xEE, 0x06, 0x53, 0x08, v[0], v[1], 0xFF, 0xFF};
            fun.get_hex_msg(command.data());

            return command;

        case 2:
            command = {0xEE, 0x06, 0x53, 0x09, v[0], v[1], 0xFF, 0xFF};
            fun.get_hex_msg(command.data());

            return command;

        default:
            RCLCPP_INFO(rclcpp::get_logger("set_current"), "Error: Invaild Motor");
            return command;
    }
}

std::vector<uint8_t> Commands::set_sensor_type(int motor, std::string type)
{
    std::vector<uint8_t> command = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    if (type == "encoder")
    {
        switch (motor)
        {
            case 1:
                command = {0xEE, 0x06, 0x50, 0x2C, 0x00, 0x00, 0xFF, 0xFF};
                fun.get_hex_msg(command.data());

                return command;
            
            case 2:
                command = {0xEE, 0x06, 0x50, 0x2D, 0x00, 0x00, 0xFF, 0xFF};
                fun.get_hex_msg(command.data());

                return command;

            default:
                RCLCPP_INFO(rclcpp::get_logger("set_sensor_type"), "Error: Invaild Motor");
                return command;
        }
    }
    else if (type == "hall")
    {
        switch (motor)
        {
            case 1:
                command = {0xEE, 0x06, 0x50, 0x2C, 0x00, 0x01, 0xFF, 0xFF};
                fun.get_hex_msg(command.data());

                return command;
            
            case 2:
                command = {0xEE, 0x06, 0x50, 0x2D, 0x00, 0x01, 0xFF, 0xFF};
                fun.get_hex_msg(command.data());

                return command;

            default:
                RCLCPP_INFO(rclcpp::get_logger("set_sensor_type"), "Error: Invaild Motor");
                return command;
        }
    }
    else if (type == "string")
    {
        switch (motor)
        {
            case 1:
                command = {0xEE, 0x06, 0x50, 0x2C, 0x00, 0x02, 0xFF, 0xFF};
                fun.get_hex_msg(command.data());

                return command;
            
            case 2:
                command = {0xEE, 0x06, 0x50, 0x2D, 0x00, 0x02, 0xFF, 0xFF};
                fun.get_hex_msg(command.data());

                return command;

            default:
                RCLCPP_INFO(rclcpp::get_logger("set_sensor_type"), "Error: Invaild Motor");
                return command;
        }
    }
    else
    {
        RCLCPP_INFO(rclcpp::get_logger("set_sensor_type"), "Error: Invaild Type");
        return command;
    }
}

std::vector<uint8_t> Commands::control_motor(int motor, std::string cmd)
{
    std::vector<uint8_t> command = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
     if (cmd == "clear")
    {
        switch (motor)
        {
            case 1:
                command = {0xEE, 0x06, 0x53, 0x00, 0x00, 0x02, 0xFF, 0xFF};
                fun.get_hex_msg(command.data());

                return command;
            
            case 2:
                command = {0xEE, 0x06, 0x53, 0x01, 0x00, 0x02, 0xFF, 0xFF};
                fun.get_hex_msg(command.data());

                return command;

            default:
                RCLCPP_INFO(rclcpp::get_logger("control_motor"), "Error: Invaild Motor");
                return command;
        }
    }
    else if (cmd == "stop")
    {
        switch (motor)
        {
            case 1:
                command = {0xEE, 0x06, 0x53, 0x00, 0x00, 0x00, 0xFF, 0xFF};
                fun.get_hex_msg(command.data());

                return command;
            
            case 2:
                command = {0xEE, 0x06, 0x53, 0x01, 0x00, 0x00, 0xFF, 0xFF};
                fun.get_hex_msg(command.data());

                return command;

            default:
                RCLCPP_INFO(rclcpp::get_logger("control_motor"), "Error: Invaild Motor");
                return command;
        }
    }
    else if (cmd == "start")
    {
        switch (motor)
        {
            case 1:
                command = {0xEE, 0x06, 0x53, 0x00, 0x00, 0x01, 0xFF, 0xFF};
                fun.get_hex_msg(command.data());

                return command;
            
            case 2:
                command = {0xEE, 0x06, 0x53, 0x01, 0x00, 0x01, 0xFF, 0xFF};
                fun.get_hex_msg(command.data());

                return command;

            default:
                RCLCPP_INFO(rclcpp::get_logger("control_motor"), "Error: Invaild Motor");
                return command;
        }
    }
    else
    {
        RCLCPP_INFO(rclcpp::get_logger("control_motor"), "Error: Invaild Command");
        return command;
    }
}

std::vector<uint8_t> Commands::calibrate(int motor)
{
    std::vector<uint8_t> command = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    switch (motor)
    {
        case 1:
            command = {0xEE, 0x06, 0x56, 0x00, 0x00, 0x01, 0xFF, 0xFF};
            fun.get_hex_msg(command.data());

            return command;
        case 2:
            command = {0xEE, 0x06, 0x55, 0x01, 0x00, 0x01, 0xFF, 0xFF};
            fun.get_hex_msg(command.data());

            return command;
        default:
            RCLCPP_INFO(rclcpp::get_logger("calibrate"), "Error: Invaild Motor");
            return command;
    }
}

//
//
// READ MOTOR STATUS //
//
// 

std::vector<uint8_t> Commands::calibration_status(int motor)
{
    std::vector<uint8_t> command = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    switch (motor)
    {
        case 1:
            command = {0xEE, 0x03, 0x56, 0x84, 0x00, 0x01, 0xFF, 0xFF};
            fun.get_hex_msg(command.data());

            return command;
    
        case 2:
            command = {0xEE, 0x03, 0x56, 0x85, 0x00, 0x01, 0xFF, 0xFF};
            fun.get_hex_msg(command.data());

            return command;

        default:
            RCLCPP_INFO(rclcpp::get_logger("calibration_status"), "Error: Invaild Motor");
            return command;
    }
}

std::vector<uint8_t> Commands::motor_running(int motor)
{
    std::vector<uint8_t> command = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    switch (motor)
    {
        case 1:
            command = {0xEE, 0x03, 0x54, 0x00, 0x00, 0x01, 0xFF, 0xFF};
            fun.get_hex_msg(command.data());

            return command;
    
        case 2:
            command = {0xEE, 0x03, 0x54, 0x01, 0x00, 0x01, 0xFF, 0xFF};
            fun.get_hex_msg(command.data());

            return command;

        default:
            RCLCPP_INFO(rclcpp::get_logger("motor_running"), "Error: Invaild Motor");
            return command;
    }
}

std::vector<uint8_t> Commands::motor_temp(int motor)
{
    std::vector<uint8_t> command = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    switch (motor)
    {
        case 1:
            command = {0xEE, 0x03, 0x54, 0x04, 0x00, 0x01, 0xFF, 0xFF};
            fun.get_hex_msg(command.data());

            return command;
    
        case 2:
            command = {0xEE, 0x03, 0x54, 0x05, 0x00, 0x01, 0xFF, 0xFF};
            fun.get_hex_msg(command.data());

            return command;

        default:
            RCLCPP_INFO(rclcpp::get_logger("motor_temp"), "Error: Invaild Motor");
            return command;
    }
}

std::vector<uint8_t> Commands::bus_voltage(int motor)
{
    std::vector<uint8_t> command = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    switch (motor)
    {
        case 1:
            command = {0xEE, 0x03, 0x54, 0x08, 0x00, 0x01, 0xFF, 0xFF};
            fun.get_hex_msg(command.data());

            return command;
    
        case 2:
            command = {0xEE, 0x03, 0x54, 0x09, 0x00, 0x01, 0xFF, 0xFF};
            fun.get_hex_msg(command.data());

            return command;

        default:
            RCLCPP_INFO(rclcpp::get_logger("bus_voltage"), "Error: Invaild Motor");
            return command;
    }
}

std::vector<uint8_t> Commands::mos_tube_temp(int motor)
{
    std::vector<uint8_t> command = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    switch (motor)
    {
        case 1:
            command = {0xEE, 0x03, 0x54, 0x0C, 0x00, 0x01, 0xFF, 0xFF};
            fun.get_hex_msg(command.data());

            return command;
    
        case 2:
            command = {0xEE, 0x03, 0x54, 0x0D, 0x00, 0x01, 0xFF, 0xFF};
            fun.get_hex_msg(command.data());

            return command;

        default:
            RCLCPP_INFO(rclcpp::get_logger("mos_tube_temp"), "Error: Invaild Motor");
            return command;
    }
}

std::vector<uint8_t> Commands::motor_speed(int motor)
{
    std::vector<uint8_t> command = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    switch (motor)
    {
        case 1:
            command = {0xEE, 0x03, 0x54, 0x10, 0x00, 0x01, 0xFF, 0xFF};
            fun.get_hex_msg(command.data());

            return command;
    
        case 2:
            command = {0xEE, 0x03, 0x54, 0x11, 0x00, 0x01, 0xFF, 0xFF};
            fun.get_hex_msg(command.data());

            return command;

        default:
            RCLCPP_INFO(rclcpp::get_logger("motor_speed"), "Error: Invaild Motor");
            return command;
    }
}

std::vector<uint8_t> Commands::motor_current(int motor)
{
    std::vector<uint8_t> command = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    switch (motor)
    {
        case 1:
            command = {0xEE, 0x03, 0x54, 0x14, 0x00, 0x01, 0xFF, 0xFF};
            fun.get_hex_msg(command.data());

            return command;
    
        case 2:
            command = {0xEE, 0x03, 0x54, 0x15, 0x00, 0x01, 0xFF, 0xFF};
            fun.get_hex_msg(command.data());

            return command;

        default:
            RCLCPP_INFO(rclcpp::get_logger("motor_current"), "Error: Invaild Motor");
            return command;
    }
}

std::vector<uint8_t> Commands::absolute_position(int motor)
{
    std::vector<uint8_t> command = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    switch (motor)
    {
        case 1:
            command = {0xEE, 0x03, 0x54, 0x18, 0x00, 0x01, 0xFF, 0xFF};
            fun.get_hex_msg(command.data());

            return command;
    
        case 2:
            command = {0xEE, 0x03, 0x54, 0x1A, 0x00, 0x01, 0xFF, 0xFF};
            fun.get_hex_msg(command.data());

            return command;

        default:
            RCLCPP_INFO(rclcpp::get_logger("absolute_position"), "Error: Invaild Motor");
            return command;
    }
}

std::vector<uint8_t> Commands::error_status(int motor)
{
    std::vector<uint8_t> command = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    switch (motor)
    {
        case 1:
            command = {0xEE, 0x03, 0x54, 0x20, 0x00, 0x01, 0xFF, 0xFF};
            fun.get_hex_msg(command.data());

            return command;
    
        case 2:
            command = {0xEE, 0x03, 0x54, 0x22, 0x00, 0x01, 0xFF, 0xFF};
            fun.get_hex_msg(command.data());

            return command;

        default:
            RCLCPP_INFO(rclcpp::get_logger("error_status"), "Error: Invaild Motor");
            return command;
    }
}