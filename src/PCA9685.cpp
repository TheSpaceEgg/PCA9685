#include "PCA9685.h"

SpecificDevice::PCA9685(uint8_t bus, uint8_t deviceAddress) 
    : i2c(bus, deviceAddress) { // Initialize the I2CDevice member with the bus and device address
}



