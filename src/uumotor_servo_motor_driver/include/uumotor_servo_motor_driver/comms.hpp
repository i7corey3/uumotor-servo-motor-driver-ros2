#ifndef UUMOTOR_SERVO_MOTOR_DRIVER_COMMS_HPP
#define UUMOTOR_SERVO_MOTOR_DRIVER_COMMS_HPP

#include <libserial/SerialPort.h>
#include <sstream>
#include <iostream>
#include "uumotor_servo_motor_driver/commands.h"
#include "uumotor_servo_motor_driver/functions.h"
#include "rclcpp/rclcpp.hpp"

LibSerial::BaudRate convert_baud_rate(int baud_rate)
{
  // Just handle some common baud rates
  switch (baud_rate)
  {
    case 1200: return LibSerial::BaudRate::BAUD_1200;
    case 1800: return LibSerial::BaudRate::BAUD_1800;
    case 2400: return LibSerial::BaudRate::BAUD_2400;
    case 4800: return LibSerial::BaudRate::BAUD_4800;
    case 9600: return LibSerial::BaudRate::BAUD_9600;
    case 19200: return LibSerial::BaudRate::BAUD_19200;
    case 38400: return LibSerial::BaudRate::BAUD_38400;
    case 57600: return LibSerial::BaudRate::BAUD_57600;
    case 115200: return LibSerial::BaudRate::BAUD_115200;
    case 230400: return LibSerial::BaudRate::BAUD_230400;
    default:
      RCLCPP_INFO(rclcpp::get_logger("convert_baud_rate"), "Error: Invaild BaudRate... Setting to default - 115200");
      return LibSerial::BaudRate::BAUD_115200;
  }
}

class Comms
{

    public:
        Comms() = default;

        void connect(const std::string &serial_device, int32_t baud_rate, int32_t timeout_ms)
        {
            timeout_ms_ = timeout_ms;
            serial_.Open(serial_device);
            serial_.SetBaudRate(convert_baud_rate(baud_rate));
            
        }

        void disconnect()
        {
            serial_.Close();
        }

        bool connected() const
        {
            return serial_.IsOpen();
        }

        std::vector<uint8_t> send_command(const std::vector<uint8_t> &cmd, int msg_length=8, bool print_output=true)
        {
            serial_.FlushIOBuffers();
            serial_.Write(cmd);
            // serial_ << cmd[0] << cmd[1] << cmd[2] << cmd[3] << cmd[4] << cmd[5] << cmd[6] << cmd[7] << std::endl;  
            
            std::vector<int> output;
            uint8_t hex_value;
            std::vector<uint8_t> hex_num;
            
            try
            {   
                for (int i = 0; i < msg_length; i++)
                {
                    serial_.ReadByte(hex_value, timeout_ms_);
                    output.push_back(static_cast<int>(hex_value));
                    // std::cout << " Hex: " << std::hex << std::setw(2) << static_cast<int>(hex_value) << std::endl;                     
                }
               
            }
            catch(const LibSerial::ReadTimeout&)
            {
                RCLCPP_INFO(rclcpp::get_logger("Serial"), "Error: Serial Timeout");
            }

            for (auto d : output)
            {
                hex_num.push_back(static_cast<uint8_t>(d));
            }

            if (print_output)
            {
                
                for (int &i: output) {
                    std::cout << std::hex << std::setw(2) << std::setfill('0') << i << ' ';
                }
                std::cout << std::endl;

            }

            return hex_num;
            
        }

    private:
        LibSerial::SerialPort serial_;
        Commands commands_;
        Functions fun_;
        int timeout_ms_;


};






#endif