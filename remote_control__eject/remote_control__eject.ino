/*#include <nRF24L01.h>
#include <RF24.h>*/
/*-----( Import needed libraries )-----*/
#include <SPI.h>
/*-----( Declare Constants and Pin Numbers )-----*/
/*#define CE_PIN   9
#define CSN_PIN  10*/
#define JOYSTICK_X A0
#define JOYSTICK_Y A1

int on1 = 7; // raise up               ***joystick[1] ** bottom up
int on2 = 6; // down                   ***joystick[2] ** bottom down
int on3 = 5; // turnarounda            ***joystick[3] ** bottom left
int on4 = 4; // unlock payload door    ***joystick[4] ** bottom middle
int on5 = 3; // motor for payload car  ***joystick[5] ** bottom 右上
int on6 = 2; // turnaround             ***joystick[6] ** bottom right
int on7 = A3;// unlock payload car     ***joystick[7] ** bottom 左下
int val1 = 0;
int val2 = 0;

int joystick[8];


// NOTE: the "LL" at the end of the constant is "LongLong" type
//const uint64_t pipe = 0xE8E8F0F0E1LL;  // Define the transmit pipe


/*-----( Declare objects )-----*/
//RF24 radio(CE_PIN, CSN_PIN); // Create a Radio
/*-----( Declare Variables )-----*/
//int  joystick[13];  // 2 element array holding Joystick readings
 
void setup()   /****** SETUP: RUNS ONCE ******/
{
  Serial.begin(9600);
  /*radio.begin();
  radio.openWritingPipe(pipe);*/
  pinMode (on1 , INPUT);
  pinMode (on2 , INPUT);
  pinMode (on3 , INPUT);
  pinMode (on4 , INPUT);
  pinMode (on5 , INPUT);
  pinMode (on6 , INPUT);
  pinMode (on7 , INPUT);
 // val1 = analogRead(JOYSTICK_X);
  val2 = analogRead(JOYSTICK_Y);
  Serial.print("** = ");
  Serial.println(val1);

  

}//--(end setup )---


void loop()   /****** LOOP: RUNS CONSTANTLY ******/
{
  /*char a = 65;
  Serial.print(digitalRead(on1));
  Serial.print((analogRead(JOYSTICK_Y) - val2));*/

 // joystick[0] = analogRead(JOYSTICK_X) - val1 ;
 // joystick[0] = 'g';  
  joystick[0] = (analogRead(JOYSTICK_Y) - val2) ;
  joystick[1] = digitalRead(on1);
  joystick[2] = digitalRead(on2);
  joystick[3] = digitalRead(on3);
  joystick[4] = digitalRead(on4);
  joystick[5] = digitalRead(on5);
  joystick[6] = digitalRead(on6);
  joystick[7] = digitalRead(on7);
  
  Serial.print(joystick[0]);
  Serial.print(joystick[1]);
  Serial.print(joystick[2]);
  Serial.print(joystick[3]);
  Serial.print(joystick[4]);
  Serial.print(joystick[5]);
  Serial.print(joystick[6]);
  Serial.print(joystick[7]);
  
}//--(end main loop )---

/*-----( Declare User-written Functions )-----*/

//NONE
//*********( THE END )***********

