#include <iostream>
#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <ament_index_cpp/get_package_share_directory.hpp>


#include "rclcpp/rclcpp.hpp"
#include "uumotor_servo_motor_driver/functions.h"

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

    // uint8_t cmd[6] = {0xEE, 0x06, 0x51, 0x00, 0x00, 0x00};
    // uint16_t crc = fun.Calc_Crc(cmd, 6); // Calculates the CRC16 of all 8 bytes

    std::string str = fun.test("TEST");
   
    std::cout << str;
    
    
    rclcpp::spin(std::make_shared<TestNode>());
    
    
    rclcpp::shutdown();
    
    return 0;
}