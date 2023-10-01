#include "uumotor_servo_motor_driver/functions.h"



uint16_t Calc_Crc(uint8_t *pack_buff, int pack_len)
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

std::string test(std::string str)
{
    return str;
}

