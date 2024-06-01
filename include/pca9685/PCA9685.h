#ifndef PCA9685_H
#define PCA9685_H

#include "i2cdevice.h" 

#define MODE1 0x00			
#define SERVO0 0x6			
#define MULTIPLIER 4	
#define PRE_SCALE 0xFE		
#define CLOCK_FREQ 27000000.0 

class PCA9685 {
public:
    PCA9685(uint8_t bus, uint8_t deviceAddress, uint8_t freq); 
	  void setFreq(uint8_t freq);
     
	  void setPWM(uint8_t, uint16_t, uint16_t);
  	void setPWM(uint8_t, uint16_t);
    uint16_t getPWM(uint8_t servo);
private:
    I2CDevice *i2c; 
	  void reset(void);
};

#endif 

