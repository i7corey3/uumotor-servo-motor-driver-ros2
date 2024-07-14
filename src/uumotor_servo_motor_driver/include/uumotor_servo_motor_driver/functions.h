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

    bool check_message(uint8_t *msg, int size);

    std::vector<uint8_t> int2hex(double value, double range, bool unsign);

    long map_range(double x, double in_min, double in_max, double out_min, double out_max);

    int message_decoder(uint8_t *msg, int bit, bool unsign, int msg_length);
 

};




#endif