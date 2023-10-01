#ifndef UUMOTOR_SERVO_MOTOR_DRIVER_FUNCTIONS_H
#define UUMOTOR_SERVO_MOTOR_DRIVER_FUNCTIONS_H

#include <string>
#include <vector>

using namespace std;

class Functions
{

    public:

    Functions() = default;

    uint16_t Calc_Crc(uint8_t *pack_buff, int pack_len);

    void get_hex_msg(uint8_t *data);

    std::vector<uint8_t> int2hex(int value, int range, bool unsign);

    int map_range(int x, int in_min, int in_max, int out_min, int out_max);

 

};




#endif