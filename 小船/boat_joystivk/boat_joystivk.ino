/*-----( Import needed libraries )-----*/
#include <SPI.h>
//#include <Servo.h>
#include <nRF24L01.h>
#include <RF24.h>
/*-----( Declare Constants and Pin Numbers )-----*/
#define CE_PIN   5
#define CSN_PIN  6
//Servo myservo;
// NOTE: the "LL" at the end of the constant is "LongLong" type
const uint64_t pipe = 0xE8E8F0F0E1LL; // Define the transmit pipe


/*-----( Declare objects )-----*/
RF24 radio(CE_PIN, CSN_PIN); // Create a Radio
/*-----( Declare Variables )-----*/
int joystick[2];  // 2 element array holding Joystick readings

void setup()   /****** SETUP: RUNS ONCE ******/
{
  Serial.begin(9600);
  // ********************************  PIN SETUP  ********************************************
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
//  myservo.attach(2);
// ********************************  TIMER PWM  ********************************************  
  TCCR1A = B10100010;// set all output compare mode and clear OCnA/OCnB/OCnC on compare match
  TCCR1B = B00011010;      // Fast pwm 10 bit mode, frequency: 16M/8 =  2M Hs = 0.5us
  ICR1 = 40000;               // Highest resolution: frequency: 16M/8/40000 = 50 Hz
  OCR1A = 1000;    // Set up with 50us to stop  100us pulse to Start
  OCR1B = 3500;
  delay(1000);
  Serial.println("Nrf24L01 Receiver Starting");
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();
  ////////////////
//  myservo.write(90);
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
      if(joystick[0] >= 516)
      {
         OCR1A = map(joystick[0],1023,516,3000,2000);
      }
      else if(joystick[0] < 516)
      {
         OCR1A = map(joystick[0],516,0,2000,1000);
      }
      
      
      if(joystick[1] > 511)
      {
        OCR1B = 2000;
      }
      else if(joystick[1] < 511)
      {
        OCR1B = 5000;
      }
      else
       {
         OCR1B = 3500;
       }
      /*switch(char(Serial.read()))
      {
        case 'q':  OCR5A = 2000; break;
//      case 'w':  OCR5A = 4000; break;   // 200us pulse dangerous 100% power for the fan
        case 'b':  OCR5A = 1000; break;
        case 'a':  OCR5A += 10; break;      // register plus 1 plus 0.5us up to OCR5A = 40000
        case 's':  OCR5A -= 10; break;
        case 'z':  OCR5A += 100; break;
        case 'x':  OCR5A -= 100; break;
        default: break;
       }
       */
        Serial.print("OCR1A = ");
        Serial.println(OCR1A);
        Serial.print("OCR1B = ");
        Serial.println(OCR1B);
     //Serial.print("X = ");
      //Serial.print(joystick[0]);
      //Serial.print(" Y = ");      
      //Serial.println(joystick[1]);
    }
  }
  else
  {    
      Serial.println("No radio available");
      OCR1A = 2000;
      OCR1B = 3500;
  }

}//--(end main loop )---

/*-----( Declare User-written Functions )-----*/

//NONE
//*********( THE END )***********

