#ifndef UUMOTOR_SERVO_MOTOR_DRIVER_COMMS_H
#define UUMOTOR_SERVO_MOTOR_DRIVER_COMMS_H

#include <libserial/SerialPort.h>
#include <sstream>
#include <iostream>
#include "uumotor_servo_motor_driver/commands.h"
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

        std::string send_command(const std::string &cmd, bool print_output=false)
        {
            serial_.FlushIOBuffers();
            serial_.Write(cmd, 0, cmd->Length);

            std::string output;
            try
            {
                serial_.Write(cmd)
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            



        }

    private:
        LibSerial::SerialPort serial_;
        Commands commands_;
        int timeout_ms_;


}






#endif