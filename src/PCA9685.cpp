#include "PCA9685.h"

PCA9685::PCA9685(uint8_t bus, uint8_t deviceAddress, uint8_t freq) {
    i2c = new I2CDevice(bus, deviceAddress); 
    reset();
    setFreq(freq);
}

void PCA9685::reset() {
    i2c->writeRegister(MODE1, 0x20);
}

void PCA9685::setFreq(uint8_t freq) {
    uint8_t prescale_val = static_cast<uint8_t>((CLOCK_FREQ / (4096 * freq)) - 1 + 0.5);
    i2c->writeRegister(MODE1, 0x10);
    i2c->writeRegister(PRE_SCALE, prescale_val);
    i2c->writeRegister(MODE1, 0xA0);
}

void PCA9685::setPWM(uint8_t servo, uint16_t value) {
	setPWM(servo, 0, value);
}

void PCA9685::setPWM(uint8_t servo, uint16_t on_value, uint16_t off_value) {

    uint8_t data[4] = {
        static_cast<uint8_t>(on_value & 0xFF), 
        static_cast<uint8_t>(on_value >> 8), 
        static_cast<uint8_t>(off_value & 0xFF), 
        static_cast<uint8_t>(off_value >> 8)
    };
    
    i2c->writeRegister(SERVO0 + MULTIPLIER * servo, data, 4);
}