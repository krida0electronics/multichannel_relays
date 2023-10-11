
// 16 Channel Electromagnetic Relay Module, SPDT contacts, current up to 10A per relay
//
// Multidevice wiring and controlling via i2c protocol
//
// I2C slave addresses are 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27
// Addresses are changeable via dip switch on pcb
// Tested with Arduino Uno ATMEGA328 and four 16CH I2C Electromagnetic Relay Module
//


#include "Wire.h"

#define  ON 1
#define OFF 0
#define BOARD_1 0x27            // i2c slave address relay BOARD #1
#define BOARD_2 0x26            // i2c slave address relay BOARD #2
#define BOARD_3 0x25            // i2c slave address relay BOARD #3
#define BOARD_4 0x24            // i2c slave address relay BOARD #4


unsigned char i;
unsigned char variable_LOW;
unsigned char variable_HIGH;
unsigned int  mode_byte;        // 16bit unsigned variable
unsigned int FAST;

unsigned int i2c_buffer, relay_buffer_1, relay_buffer_2, relay_buffer_3, relay_buffer_4;     // 16 bit variable buffers for each i2c relay module

void setup() {
    
    Wire.begin();                        // wake up I2C bus
                                         // set I/O pins to outputs
                                  
    /////////////////////////////////////////////////////////////////////////
    Wire.beginTransmission(BOARD_1);     // setup RELAY board #1
    Wire.write(0x00);                    // A register
    Wire.write(0x00);                    // set all of port A to outputs
    Wire.endTransmission();

    Wire.beginTransmission(BOARD_1);
    Wire.write(0x01);                   // B register
    Wire.write(0x00);                   // set all of port B to outputs
    Wire.endTransmission();   
    ////////////////////////////////////////////////////////////////////////
    Wire.beginTransmission(BOARD_2);     // setup RELAY board #2
    Wire.write(0x00);                    // A register
    Wire.write(0x00);                    // set all of port A to outputs
    Wire.endTransmission();

    Wire.beginTransmission(BOARD_2);
    Wire.write(0x01);                   // B register
    Wire.write(0x00);                   // set all of port B to outputs
    Wire.endTransmission();   
    ///////////////////////////////////////////////////////////////////////
    Wire.beginTransmission(BOARD_3);     // setup RELAY board #3
    Wire.write(0x00);                    // A register
    Wire.write(0x00);                    // set all of port A to outputs
    Wire.endTransmission();

    Wire.beginTransmission(BOARD_3);
    Wire.write(0x01);                   // B register
    Wire.write(0x00);                   // set all of port B to outputs
    Wire.endTransmission();   
    ///////////////////////////////////////////////////////////////////////
    Wire.beginTransmission(BOARD_4);     // setup RELAY board #4
    Wire.write(0x00);                    // A register
    Wire.write(0x00);                    // set all of port A to outputs
    Wire.endTransmission();

    Wire.beginTransmission(BOARD_4);
    Wire.write(0x01);                   // B register
    Wire.write(0x00);                   // set all of port B to outputs
    Wire.endTransmission();       
    ///////////////////////////////////////////////////////////////////////
    
    
    FAST = 50 ;

}


//
// This function control each channel separately ON/OFF
//

void channel_mode(unsigned char addr, unsigned char channel, unsigned char value){   

     switch (channel) { case 16 : channel =  7; break;
                        case 15 : channel =  6; break;
                        case 14 : channel =  5; break;
                        case 13 : channel =  4; break;
                        case 12 : channel =  3; break;
                        case 11 : channel =  2; break;
                        case 10 : channel =  1; break;
                        case  9 : channel =  0; break;
                        case  8 : channel = 15; break;
                        case  7 : channel = 14; break;
                        case  6 : channel = 13; break;
                        case  5 : channel = 12; break;
                        case  4 : channel = 11; break;
                        case  3 : channel = 10; break;
                        case  2 : channel =  9; break;
                        case  1 : channel =  8; break; }

     switch (addr) {   case BOARD_1: i2c_buffer = relay_buffer_1; break;
                       case BOARD_2: i2c_buffer = relay_buffer_2; break;
                       case BOARD_3: i2c_buffer = relay_buffer_3; break;
                       case BOARD_4: i2c_buffer = relay_buffer_4; break;  }                   

     i2c_buffer &= ~(1<<(channel));
     i2c_buffer |= value<<channel;

     switch (addr) {   case BOARD_1: relay_buffer_1 = i2c_buffer; break;
                       case BOARD_2: relay_buffer_2 = i2c_buffer; break;
                       case BOARD_3: relay_buffer_3 = i2c_buffer; break;
                       case BOARD_4: relay_buffer_4 = i2c_buffer; break;  }

     variable_LOW = lowByte(i2c_buffer);
     variable_HIGH = highByte(i2c_buffer);

     Wire.beginTransmission(addr);
     Wire.write(0x12);            // address bank A
     Wire.write(variable_LOW);
     Wire.endTransmission();
     
     Wire.beginTransmission(addr);
     Wire.write(0x13);            // address bank B
     Wire.write(variable_HIGH);
     Wire.endTransmission();
  
}



void loop() {
        
   channel_mode(BOARD_1,1,ON); delay(FAST);      
   channel_mode(BOARD_2,2,ON); delay(FAST);     
   channel_mode(BOARD_3,3,ON); delay(FAST);      
   channel_mode(BOARD_4,4,ON); delay(FAST);      
   channel_mode(BOARD_1,5,ON); delay(FAST);      
   channel_mode(BOARD_2,6,ON); delay(FAST);     
   channel_mode(BOARD_3,7,ON); delay(FAST);      
   channel_mode(BOARD_4,8,ON); delay(FAST);    
   channel_mode(BOARD_1,9,ON); delay(FAST);      
   channel_mode(BOARD_2,10,ON); delay(FAST);     
   channel_mode(BOARD_3,11,ON); delay(FAST);      
   channel_mode(BOARD_4,12,ON); delay(FAST);      
   channel_mode(BOARD_1,13,ON); delay(FAST);      
   channel_mode(BOARD_2,14,ON); delay(FAST);     
   channel_mode(BOARD_3,15,ON); delay(FAST);      
   channel_mode(BOARD_4,16,ON); delay(FAST);  

   channel_mode(BOARD_1,1,OFF); delay(FAST);      
   channel_mode(BOARD_2,2,OFF); delay(FAST);     
   channel_mode(BOARD_3,3,OFF); delay(FAST);      
   channel_mode(BOARD_4,4,OFF); delay(FAST);      
   channel_mode(BOARD_1,5,OFF); delay(FAST);      
   channel_mode(BOARD_2,6,OFF); delay(FAST);     
   channel_mode(BOARD_3,7,OFF); delay(FAST);      
   channel_mode(BOARD_4,8,OFF); delay(FAST);    
   channel_mode(BOARD_1,9,OFF); delay(FAST);      
   channel_mode(BOARD_2,10,OFF); delay(FAST);     
   channel_mode(BOARD_3,11,OFF); delay(FAST);      
   channel_mode(BOARD_4,12,OFF); delay(FAST);      
   channel_mode(BOARD_1,13,OFF); delay(FAST);      
   channel_mode(BOARD_2,14,OFF); delay(FAST);     
   channel_mode(BOARD_3,15,OFF); delay(FAST);      
   channel_mode(BOARD_4,16,OFF); delay(FAST);  
    
    
            
}
