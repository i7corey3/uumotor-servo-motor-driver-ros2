#include "uumotor_servo_motor_driver/commands.h"

Commands::Commands(const std::string &model_name)
{
    setup(model_name);
}

void Commands::setup(const std::string &model_name)
{
    if (model_name == "svd6h2")
    {
        model = model_name;
        max_speed = 500;
        max_amp = 20;
        max_torque = 20;
    }
    // default driver
    else
    {
        model = "svd6h2";
        max_speed = 500;
        max_amp = 20;
        max_torque = 20;
    }
    
}

void Commands::set_control_mode(std::vector<unsigned char> &command, int motor, std::string mode)
{
    if (mode == "speed")
    {
        switch (motor)
        {
            case 1:
                const unsigned char cmd[6] = {0xEE, 0x06, 0x51, 0x00, 0x00, 0x00};
                
        }
    }
}