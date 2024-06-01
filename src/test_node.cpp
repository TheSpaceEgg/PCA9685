#include "PCA9685.h"
#include <unistd.h>
#include <iostream>


int main() {
PCA9685 pwm[2] = {PCA9685(1, 0x40, 60), PCA9685(1, 0x41, 60)};
    while (true) {
       
            pwm[0].setPWM(5, 150);
            usleep(2000000);
      
            pwm[0].setPWM(5, 550);
            usleep(2000000); 
    }

    return 0;
}
