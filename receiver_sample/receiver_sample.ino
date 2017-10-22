#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
/*-----( Declare Constants and Pin Numbers )-----*/
#define CE_PIN   27
#define CSN_PIN  26

// NOTE: the "LL" at the end of the constant is "LongLong" type
const uint64_t pipe = 0xE8E8F0F0E1LL; // Define the transmit pipe


/*-----( Declare objects )-----*/
RF24 radio(CE_PIN, CSN_PIN); // Create a Radio
/*-----( Declare Variables )-----*/
int joystick[8];  // 2 element array holding Joystick readings

void setup()   /****** SETUP: RUNS ONCE ******/
{
  Serial.begin(9600);
  delay(1000);
  Serial.println("Nrf24L01 Receiver Starting");
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();;
}//--(end setup )---


void loop()   /****** LOOP: RUNS CONSTANTLY ******/
{
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
      Serial.print(" A = "); 
      Serial.println(joystick[2]);
      Serial.print(" B = "); 
      Serial.println(joystick[3]);
      Serial.print(" C = "); 
      Serial.println(joystick[4]);
      Serial.print(" D = "); 
      Serial.println(joystick[5]);
      Serial.print(" E = "); 
      Serial.println(joystick[6]);
      Serial.print(" F = "); 
      Serial.println(joystick[7]);
      
    }
  }
  else
  {    
      Serial.println("No radio available");
  }

}//--(end main loop )---

/*-----( Declare User-written Functions )-----*/

//NONE
//*********( THE END )***********


