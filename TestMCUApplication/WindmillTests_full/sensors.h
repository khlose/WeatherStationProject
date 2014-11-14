#include "mbed.h"

#include "max4070.h"
#include "rtos.h"
#include "USBHostMSD.h"
#include "LCD40x2.h"
#include "BMP180.h"
#include "max9611.h"
#include "si7020.h"

#define USB_DEBUG


#define SI7020_ENABLED

#define MAX9611_ENABLEDx

#define BMP180_ENABLEDx

#ifdef BMP180_ENABLEDx 
#define MAX4070_ENABLEDx
#else 
#define MAX4070_ENABLEDx
#endif


#define BMP180_PIN_SDA PTB1    // I2C0
#define BMP180_PIN_SCL PTB0

#define MAX4070_PIN_ANALOG_IN PTB0 //AIN 0 charging current sensor
#define MAX4070_PIN_ANALOG_IN_VOLTAGE PTB1 //AIN 1 charging  sensor

#define MAX9611_PIN_SDA PTB1    // I2C0
#define MAX9611_PIN_SCL PTB0

#define SI7020_PIN_SDA PTB1    // I2C0
#define SI7020_PIN_SCL PTB0


class SENSORS {

public: 

SENSORS();
    
~SENSORS();
    
//public methods to handle in other threads    
void measurement (void const* args);  
void getResults (void const* args);  // get or print all results from the sensors 
int saveDataToUSB(void const* args);

void showError(void);
    
private:     
 USBHostMSD* msd;
 MAX4070* max4070;
 MAX4070* max4070Voltage;
 BMP180*  bmp180;
 SI7020*  si7020;
 MAX9611* max9611;

 FILE* fileCurrent;
 FILE* fileVoltage;
 Mutex measPrintMutex;


 struct Results{
      Results():MAX4070chargerCurrent(0),
                MAX4070chargerVoltage(0),BMP180pressure(0),BMP180temperature(0),MAX9611voltage(0),MAX9611current(0){}
    
      float MAX4070chargerCurrent;
      float MAX4070chargerVoltage;
      
      float BMP180pressure; 
      float BMP180temperature;
       
      float MAX9611voltage; 
      float MAX9611current;
};
Results results;



Serial usbDebug;
TextLCD lcd;
//charLcd lcd;

    
};