#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
/*-----( Declare Constants and Pin Numbers )-----*/
#define CE_PIN  27
#define CSN_PIN 26

/*int ena = 2;xxz
int rpwma = 3;
int lpwma = 4;
//int volt = 0;*/

// NOTE: the "LL" at the end of the constant is "LongLong" type
const uint64_t pipe = 0xE8E8F0F0E1LL;  // Define the transmit pipe


/*-----( Declare objects )-----*/
RF24 radio(CE_PIN, CSN_PIN); // Create a Radio
/*-----( Declare Variables )-----*/
int joystick[2];  // 2 element array holding Joystick readings

void setup()   /****** SETUP: RUNS ONCE ******/
{
 /* pinMode(ena,OUTPUT);
  pinMode(rpwma,OUTPUT);
  pinMode(lpwma,OUTPUT);*/
  Serial.begin(9600);
  delay(1000);
  Serial.println("Nrf24L01 Receiver Starting");
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();;
  /*digitalWrite(ena,HIGH);
  digitalWrite(lpwma,HIGH);*/
  
}//--(end setup )---


void loop()   /****** LOOP: RUNS CONSTANTLY ******/
{
  int val = 0;
  if ( radio.available() )
  {
    // Read the data payload until we've received everything
    bool done = false;
    
    while (!done)
    {
      // Fetch the data payload
      done = radio.read( joystick, sizeof(joystick) );
      
      Serial.print("X = ");
      Serial.print(joystick[0]);
      Serial.print(" Y = ");      
      Serial.println(joystick[1]);
      /*Serial.print("volt = ");
      Serial.print(joystick[2]);
      Serial.print("volt2 = ");
      Serial.print(joystick[3]);
      Serial.print("volt3 = ");
      Serial.print(joystick[4]);
      Serial.print("volt4 = ");
      Serial.print(joystick[5]); */
     /* val = map(joystick[0],0,1023,0,255);
      analogWrite(rpwma,val);
      Serial.println(joystick[6]);*/
      //Serial.print("volt5 = ");
      //Serial.println(joystick[6]);
      
      
    }
  }
  else
  {    
      Serial.println("No radio available");
  }

 /*  val = map(joystick[0],0,1023,0,255);
   analogWrite(rpwma,val);*/
  // Serial.println(val);
}//--(end main loop )---

/*-----( Declare User-written Functions )-----*/



