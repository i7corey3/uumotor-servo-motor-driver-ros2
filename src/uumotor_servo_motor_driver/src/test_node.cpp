#include <iostream>
#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <ament_index_cpp/get_package_share_directory.hpp>


#include "rclcpp/rclcpp.hpp"
#include "uumotor_servo_motor_driver/functions.h"
#include "uumotor_servo_motor_driver/commands.h"

using namespace std::chrono_literals;

class TestNode : public rclcpp::Node
{

    public:
        TestNode()
        : Node("driver")
        {

           
        }
  
    

};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    
    Functions fun;
    Commands command;
    command.setup("svd6h2");

    // std::vector<uint8_t> cmd = {0xEE, 0x06, 0x51, 0x00, 0x00, 0x00, 0xFF, 0xFF};
    // fun.get_hex_msg(cmd.data());

    // uint8_t cmd[8];
    // std::vector<uint8_t> cmd = command.set_control_mode(2, "speed");
    
    std::vector<uint8_t> cmd = fun.int2hex(20, 500, true);

    for (int i = 0; i < 2; i++)
    {
        std::cout << "message " << std::hex << static_cast<int>(cmd[i]) << std::endl;
    }
    
    
    rclcpp::spin(std::make_shared<TestNode>());
    
    
    rclcpp::shutdown();
    
    return 0;
}