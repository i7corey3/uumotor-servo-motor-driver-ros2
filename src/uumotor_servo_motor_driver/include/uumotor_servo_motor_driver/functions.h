#ifndef UUMOTOR_SERVO_MOTOR_DRIVER_FUNCTIONS_H
#define UUMOTOR_SERVO_MOTOR_DRIVER_FUNCTIONS_H

#include <string>
#include <vector>

using namespace std;

class Functions
{

    public:

    Functions() {

    }

    uint16_t Calc_Crc(uint8_t*pack_buff, uint8_t pack_len);

 

};




#endif