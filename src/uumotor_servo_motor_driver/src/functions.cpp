#include "uumotor_servo_motor_driver/functions.h"

uint16_t Calc_Crc(uint8_t*pack_buff,uint8_t pack_len)
{
    uint8_t len = pack_len;
    uint16_t crc_result = 0xffff;
    int crc_num = 0;
    int xor_flag = 0;
    for (int i = 0; i < len; i++)
    {
        crc_result ^= pack_buff[i];
        crc_num = (crc_result & 0x0001);
        for (int m = 0; m < 8; m++)
        {
            if (crc_num == 1)
                xor_flag = 1;
            else
                xor_flag = 0;
            crc_result >>= 1;
            if (xor_flag)
                crc_result ^= 0xa001;
            crc_num = (crc_result & 0x0001);
            
        }
    }
}