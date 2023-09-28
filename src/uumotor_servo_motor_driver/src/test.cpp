#include "uumotor_servo_motor_driver/test.h"
#include <iostream>

using namespace std;

int main()
{
    Functions fun;

    unsigned char cmd[6] = {0xEE, 0x06, 0x51, 0x00, 0x00, 0x00};
    uint8_t val[6];
    
    int arraySize = sizeof(cmd)/sizeof(cmd[0]);
    uint16_t crc = fun.Calc_Crc(cmd, arraySize);

    cout << crc << " ";
    return 0;
}