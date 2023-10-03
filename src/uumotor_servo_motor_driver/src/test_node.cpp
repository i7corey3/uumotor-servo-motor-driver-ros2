#include <iostream>
#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <thread>
#include <ament_index_cpp/get_package_share_directory.hpp>
#include "uumotor_servo_motor_driver/controller.hpp"


#include "rclcpp/rclcpp.hpp"
#include "uumotor_servo_motor_driver/motor_controller.hpp"

using namespace std::chrono_literals;

class TestNode : public rclcpp::Node
{

    public:
        TestNode()
        : Node("driver")
        { }


  

};


int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    Controller cc;
    cc.start_demo();
  
    
    // rclcpp::spin(std::make_shared<TestNode>());
    
    
    // rclcpp::shutdown();
    
    return 0;
}