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

bool Functions::check_message(uint8_t *msg)
{

    uint16_t crc = Calc_Crc(msg, 6);
    
    uint8_t partA = static_cast<uint8_t>((crc & 0xFF00) >> 8);
    uint8_t partB = static_cast<uint8_t>((crc & 0x00FF));

    // std::cout << std::hex << static_cast<int>(partA) << " ";
    // std::cout << std::hex << static_cast<int>(partB) << " ";
    // std::cout << std::hex << static_cast<int>(msg[6]) << " ";
    // std::cout << std::hex << static_cast<int>(msg[7]) << std::endl;

    if (msg[6] != partA or msg[7] != partB)
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

int Functions::map_range(int x, int in_min, int in_max, int out_min, int out_max)
{
    if (x > in_max)
    {
        return out_max;
    }
    else if (x  < in_min)
    {
        return out_min;
    }
    else
    {
        int val = (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
        return val;
    }
}

std::vector<uint8_t> Functions::int2hex(int value, int range, bool unsign)
{
    long actual;

    if (!unsign)
    {
        actual = (map_range(value, -range, range, -32768, 32767) & 0xFFFF);
        
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


int Functions::message_decoder(uint8_t *msg, int bit, bool unsign)
{
    
    if (bit == 16)
    {
        // msg[4] msg[5]
        int value;
        value = (msg[4] << 8) | msg[5];
        
        if (!unsign)
        {
            value = (value & 0xFFFF);
            // printf("%u\n", value);
            // std::cout << value << "    " << std::endl;
            return value;
        }
        else 
        {
            // printf("%u\n", value);
            // std::cout << value << "    " << std::endl;
            return value;
        }

    
        // std::cout << std::hex << static_cast<int>(msg[4]) << " ";
        // std::cout << std::hex << static_cast<int>(msg[5]) << std::endl;

    }
    else
    {
        return 0;
    }
}

