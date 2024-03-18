#ifndef PCA9685_H
#define PCA9685_H

#include "i2cdevice.h" 

class PCA9685 {
public:
    PCA9685(uint8_t bus, uint8_t deviceAddress);
    
private:
    I2CDevice i2c; 
};

#endif 

