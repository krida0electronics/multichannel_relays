//
// 8 Channel Electromagnetic relay module board 5.0V 3.3V / 1500mA
//
// MULTICHANNEL WIRING AND CONTROLLING
//
// EXPAMPLE FOR 4 BOARDS
//
// Before programming, please check your slave addesses with Arduino I2C scanner!
//
// I2C expander on PCF8574(A) chip
//
// Logic level "0" ON relay, logic level "1" OFF relay
//


#include <Wire.h>


// I2C slave addresses can changeable by user via dip switch on board

#define BOARD_1 0x27    // i2c slave address of BOARD #1
#define BOARD_2 0x26    // i2c slave address of BOARD #2
#define BOARD_3 0x25    // i2c slave address of BOARD #3
#define BOARD_4 0x24    // i2c slave address of BOARD #4

#define  ON 1
#define OFF 0

int FAST = 500;              // delay value in ms

unsigned char i2c_buffer;

unsigned char i2c_buffer_1;   // i2c relay variable buffer for #1 relay board
unsigned char i2c_buffer_2;   // i2c relay variable buffer for #2 relay board
unsigned char i2c_buffer_3;   // i2c relay variable buffer for #3 relay board
unsigned char i2c_buffer_4;   // i2c relay variable buffer for #4 relay board



void setup() {
  
  Wire.begin(); 

}


void channel_mode(unsigned char addr, unsigned char channel, unsigned char value)
{
 switch (addr) {   case BOARD_1: i2c_buffer = i2c_buffer_1; break;
                   case BOARD_2: i2c_buffer = i2c_buffer_2; break;
                   case BOARD_3: i2c_buffer = i2c_buffer_3; break;
                   case BOARD_4: i2c_buffer = i2c_buffer_4; break;  }
                  

 channel = 8-channel;

 i2c_buffer &= ~(1<<(channel));
 i2c_buffer |= value<<channel;

 
 switch (addr) {   case BOARD_1: i2c_buffer_1 = i2c_buffer; break;
                   case BOARD_2: i2c_buffer_2 = i2c_buffer; break;
                   case BOARD_3: i2c_buffer_3 = i2c_buffer; break;
                   case BOARD_4: i2c_buffer_4 = i2c_buffer; break;  }
 

 Wire.beginTransmission(addr);             
 Wire.write(~i2c_buffer);               
 Wire.endTransmission();  
}

void loop() {

// RELAY #1

channel_mode(BOARD_1,1,ON); delay(FAST);      // Turn ON channel 1 on board#1 and then wait delay
channel_mode(BOARD_1,2,ON); delay(FAST);      // Turn ON channel 2 on board#1 and then wait delay
channel_mode(BOARD_1,3,ON); delay(FAST);      // Turn ON channel 3 on board#1 and then wait delay
channel_mode(BOARD_1,4,ON); delay(FAST);      // Turn ON channel 4 on board#1 and then wait delay
channel_mode(BOARD_1,5,ON); delay(FAST);      // Turn ON channel 5 on board#1 and then wait delay
channel_mode(BOARD_1,6,ON); delay(FAST);      // Turn ON channel 6 on board#1 and then wait delay
channel_mode(BOARD_1,7,ON); delay(FAST);      // Turn ON channel 7 on board#1 and then wait delay
channel_mode(BOARD_1,8,ON); delay(FAST);      // Turn ON channel 8 on board#1 and then wait delay

channel_mode(BOARD_1,1,OFF); delay(FAST);     // Turn OFF channel 1 on board#1 and then wait delay
channel_mode(BOARD_1,2,OFF); delay(FAST);     // Turn OFF channel 2 on board#1 and then wait delay
channel_mode(BOARD_1,3,OFF); delay(FAST);     // Turn OFF channel 3 on board#1 and then wait delay
channel_mode(BOARD_1,4,OFF); delay(FAST);     // Turn OFF channel 4 on board#1 and then wait delay
channel_mode(BOARD_1,5,OFF); delay(FAST);     // Turn OFF channel 5 on board#1 and then wait delay
channel_mode(BOARD_1,6,OFF); delay(FAST);     // Turn OFF channel 6 on board#1 and then wait delay
channel_mode(BOARD_1,7,OFF); delay(FAST);     // Turn OFF channel 7 on board#1 and then wait delay
channel_mode(BOARD_1,8,OFF); delay(FAST);     // Turn OFF channel 8 on board#1 and then wait delay

// 
//
//

// RELAY #2

channel_mode(BOARD_2,1,ON); delay(FAST);      // Turn ON channel 1 on board#2 and then wait delay
channel_mode(BOARD_2,2,ON); delay(FAST);      // Turn ON channel 2 on board#2 and then wait delay
channel_mode(BOARD_2,3,ON); delay(FAST);      // Turn ON channel 3 on board#2 and then wait delay
channel_mode(BOARD_2,4,ON); delay(FAST);      // Turn ON channel 4 on board#2 and then wait delay
channel_mode(BOARD_2,5,ON); delay(FAST);      // Turn ON channel 5 on board#2 and then wait delay
channel_mode(BOARD_2,6,ON); delay(FAST);      // Turn ON channel 6 on board#2 and then wait delay
channel_mode(BOARD_2,7,ON); delay(FAST);      // Turn ON channel 7 on board#2 and then wait delay
channel_mode(BOARD_2,8,ON); delay(FAST);      // Turn ON channel 8 on board#2 and then wait delay

channel_mode(BOARD_2,1,OFF); delay(FAST);     // Turn OFF channel 1 on board#2 and then wait delay
channel_mode(BOARD_2,2,OFF); delay(FAST);     // Turn OFF channel 2 on board#2 and then wait delay
channel_mode(BOARD_2,3,OFF); delay(FAST);     // Turn OFF channel 3 on board#2 and then wait delay
channel_mode(BOARD_2,4,OFF); delay(FAST);     // Turn OFF channel 4 on board#2 and then wait delay
channel_mode(BOARD_2,5,OFF); delay(FAST);     // Turn OFF channel 5 on board#2 and then wait delay
channel_mode(BOARD_2,6,OFF); delay(FAST);     // Turn OFF channel 6 on board#2 and then wait delay
channel_mode(BOARD_2,7,OFF); delay(FAST);     // Turn OFF channel 7 on board#2 and then wait delay
channel_mode(BOARD_2,8,OFF); delay(FAST);     // Turn OFF channel 8 on board#2 and then wait delay

// 
//
//

// RELAY #3

channel_mode(BOARD_3,1,ON); delay(FAST);      // Turn ON channel 1 on board#3 and then wait delay
channel_mode(BOARD_3,2,ON); delay(FAST);      // Turn ON channel 2 on board#3 and then wait delay
channel_mode(BOARD_3,3,ON); delay(FAST);      // Turn ON channel 3 on board#3 and then wait delay
channel_mode(BOARD_3,4,ON); delay(FAST);      // Turn ON channel 4 on board#3 and then wait delay
channel_mode(BOARD_3,5,ON); delay(FAST);      // Turn ON channel 5 on board#3 and then wait delay
channel_mode(BOARD_3,6,ON); delay(FAST);      // Turn ON channel 6 on board#3 and then wait delay
channel_mode(BOARD_3,7,ON); delay(FAST);      // Turn ON channel 7 on board#3 and then wait delay
channel_mode(BOARD_3,8,ON); delay(FAST);      // Turn ON channel 8 on board#3 and then wait delay

channel_mode(BOARD_3,1,OFF); delay(FAST);     // Turn OFF channel 1 on board#3 and then wait delay
channel_mode(BOARD_3,2,OFF); delay(FAST);     // Turn OFF channel 2 on board#3 and then wait delay
channel_mode(BOARD_3,3,OFF); delay(FAST);     // Turn OFF channel 3 on board#3 and then wait delay
channel_mode(BOARD_3,4,OFF); delay(FAST);     // Turn OFF channel 4 on board#3 and then wait delay
channel_mode(BOARD_3,5,OFF); delay(FAST);     // Turn OFF channel 5 on board#3 and then wait delay
channel_mode(BOARD_3,6,OFF); delay(FAST);     // Turn OFF channel 6 on board#3 and then wait delay
channel_mode(BOARD_3,7,OFF); delay(FAST);     // Turn OFF channel 7 on board#3 and then wait delay
channel_mode(BOARD_3,8,OFF); delay(FAST);     // Turn OFF channel 8 on board#3 and then wait delay

// 
//
//

// RELAY #4

channel_mode(BOARD_4,1,ON); delay(FAST);      // Turn ON channel 1 on board#4 and then wait delay
channel_mode(BOARD_4,2,ON); delay(FAST);      // Turn ON channel 2 on board#4 and then wait delay
channel_mode(BOARD_4,3,ON); delay(FAST);      // Turn ON channel 3 on board#4 and then wait delay
channel_mode(BOARD_4,4,ON); delay(FAST);      // Turn ON channel 4 on board#4 and then wait delay
channel_mode(BOARD_4,5,ON); delay(FAST);      // Turn ON channel 5 on board#4 and then wait delay
channel_mode(BOARD_4,6,ON); delay(FAST);      // Turn ON channel 6 on board#4 and then wait delay
channel_mode(BOARD_4,7,ON); delay(FAST);      // Turn ON channel 7 on board#4 and then wait delay
channel_mode(BOARD_4,8,ON); delay(FAST);      // Turn ON channel 8 on board#4 and then wait delay

channel_mode(BOARD_4,1,OFF); delay(FAST);     // Turn OFF channel 1 on board#4 and then wait delay
channel_mode(BOARD_4,2,OFF); delay(FAST);     // Turn OFF channel 2 on board#4 and then wait delay
channel_mode(BOARD_4,3,OFF); delay(FAST);     // Turn OFF channel 3 on board#4 and then wait delay
channel_mode(BOARD_4,4,OFF); delay(FAST);     // Turn OFF channel 4 on board#4 and then wait delay
channel_mode(BOARD_4,5,OFF); delay(FAST);     // Turn OFF channel 5 on board#4 and then wait delay
channel_mode(BOARD_4,6,OFF); delay(FAST);     // Turn OFF channel 6 on board#4 and then wait delay
channel_mode(BOARD_4,7,OFF); delay(FAST);     // Turn OFF channel 7 on board#4 and then wait delay
channel_mode(BOARD_4,8,OFF); delay(FAST);     // Turn OFF channel 8 on board#4 and then wait delay

// 
//
//






}
