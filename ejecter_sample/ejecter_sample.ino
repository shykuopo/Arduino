#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
/*-----( Declare Constants and Pin Numbers )-----*/
#define CE_PIN  9
#define CSN_PIN  10
#define JOYSTICK_X A0
#define JOYSTICK_Y A1

// NOTE: the "LL" at the end of the constant is "LongLong" type
const uint64_t pipe = 0xE8E8F0F0E1LL; // Define the transmit pipe


/*-----( Declare objects )-----*/
RF24 radio(CE_PIN, CSN_PIN); // Create a Radio
/*-----( Declare Variables )-----*/
int joystick[8];  // 2 element array holding Joystick readings
int val1 = 1;
int val2 = 2;
int val3 = 3;
int val4 = 4;
int val5 = 5;
int val6 = 6;

void setup()   /****** SETUP: RUNS ONCE ******/
{
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(pipe);
}//--(end setup )---


void loop()   /****** LOOP: RUNS CONSTANTLY ******/
{
  joystick[0] = analogRead(JOYSTICK_X);
  joystick[1] = analogRead(JOYSTICK_Y);
  joystick[2] = val1 ;
  joystick[3] = val2;
  joystick[4] = val3 ;
  joystick[5] = val4;
  joystick[6] = val5;
  joystick[7] = val6;
  
  Serial.println(joystick[0]);
  Serial.println(joystick[1]);
  Serial.print(joystick[2]);
  Serial.print(joystick[3]);
  Serial.print(joystick[4]);
  Serial.print(joystick[5]);
  Serial.print(joystick[6]);
  Serial.println(joystick[7]);
  radio.write( joystick, sizeof(joystick) );

}//--(end main loop )---
