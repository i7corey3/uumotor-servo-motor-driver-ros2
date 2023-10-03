#include <iostream>
#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <ament_index_cpp/get_package_share_directory.hpp>


#include "rclcpp/rclcpp.hpp"
#include "uumotor_servo_motor_driver/motor_controller.hpp"

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
    
    // Functions fun;
    MotorController MC;
    
    std::vector<uint8_t> cmd;

    MC.select_model("svd6h2");
    MC.connect_to_driver("/dev/ttyUSB0", 115200, 1000);
    
    // cmd = MC.commands_.set_control_mode(1, "speed");
    // MC.serial_.send_command(cmd);
    MC.set_motor_parameters(1, "speed", 200, -200, 2, "hall");
    
    MC.set_motor_speed(1, 2);

    MC.drive_motor(1);

    long encoder = MC.get_absolute_position(1);

    std::cout << static_cast<float>(encoder) << std::endl;
  
    
    rclcpp::spin(std::make_shared<TestNode>());
    
    
    rclcpp::shutdown();
    
    return 0;
}