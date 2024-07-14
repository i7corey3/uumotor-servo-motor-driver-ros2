#include "uumotor_servo_motor_driver/functions.h"
#include <sstream>
#include <iostream>



uint16_t Functions::Calc_Crc(uint8_t *pack_buff, int pack_len)
{
    
    uint16_t crc = 0xFFFF;
    uint16_t poly = 0xA001;

    for (int i = 0; i < pack_len; i++)
    {
        crc ^= pack_buff[i];
        for (int j = 0; j < 8; j++)
        {
            if (crc & 0x0001)
            {
                crc = (crc >> 1) ^ poly;
            }
            else 
            {
                crc >>= 1;
            }
        }

    }
    return crc;

}

bool Functions::check_message(uint8_t *msg, int size)
{

    
    uint16_t crc = Calc_Crc(msg, size-2);
    
    uint8_t partA = static_cast<uint8_t>((crc & 0xFF00) >> 8);
    uint8_t partB = static_cast<uint8_t>((crc & 0x00FF));

    // std::cout << std::hex << static_cast<int>(partA) << " ";
    // std::cout << std::hex << static_cast<int>(partB) << " ";
    // std::cout << std::hex << static_cast<int>(msg[6]) << " ";
    // std::cout << std::hex << static_cast<int>(msg[7]) << std::endl;

    if (msg[size-2] != partA || msg[size-1] != partB)
    {
        return false;
    }
    else
    {
        return true; 
    }
}

void Functions::get_hex_msg(uint8_t *data)
{
    uint16_t crc = Calc_Crc(data, 6);

    uint8_t partA = static_cast<uint8_t>((crc & 0xFF00) >> 8);
    uint8_t partB = static_cast<uint8_t>((crc & 0x00FF));

    data[6] = partA;
    data[7] = partB;
    

    
}

long Functions::map_range(double x, double in_min, double in_max, double out_min, double out_max)
{
    if (x > in_max)
    {
        return out_max;
    }
    else if (x < in_min)
    {
        
        return out_min;
    }
    else
    {
  
        long val = (long)((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
       
        return val;
    }
}

std::vector<uint8_t> Functions::int2hex(double value, double range, bool unsign)
{
    long actual;

    if (!unsign)
    {
        actual = map_range(value, -range, range, -32768, 32767) & 0xFFFF;
        
    }
    else
    {
        actual = map_range(value, 0, range, 0, 65535);
        
    }
    
    
    uint8_t partA = static_cast<uint8_t>((actual & 0xFF00) >> 8);
    uint8_t partB = static_cast<uint8_t>((actual & 0x00FF));

    std::vector<uint8_t> val = {partA, partB};

    return val;
}


int Functions::message_decoder(uint8_t *msg, int bit, bool unsign, int msg_length)
{
    int value;
    if (bit == 16)
    {
        // msg[4] msg[5]
        
        value = (msg[msg_length - 4] << 8) | msg[msg_length - 3];
        
        if (!unsign) return (value ^ 0x8000) - 0x8000;

        else return value;

    }
    else if (bit == 32)
    {
        value = (msg[msg_length - 6] << 24) | (msg[msg_length - 5] << 16) | (msg[msg_length - 4] << 8) | msg[msg_length - 3];
        
        if (!unsign) return (value ^ 0x80000000) - 0x80000000;

        else return value;
    }
    else
    {
        std::cout << "Error: Invalid Bit Count (16 or 32)" << std::endl;
        return 0;
    }
}

