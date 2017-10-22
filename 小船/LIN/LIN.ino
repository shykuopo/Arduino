#include <SoftwareSerial.h>
#include "BT_control.h"
//#include <Servo.h>

int output1;
int output2;
//int output3;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
 pinMode(6,OUTPUT);//馬達控制3PIN
 pinMode(7,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(9,OUTPUT);
 pinMode(10,OUTPUT);
  TCCR1A = B10100010;// set all output compare mode and clear OCnA/OCnB/OCnC on compare match
  TCCR1B = B00011010;      // Fast pwm 10 bit mode, frequency: 16M/8 =  2M Hs = 0.5us
  ICR1 = 40000;               // Highest resolution: frequency: 16M/8/40000 = 50 Hz
  OCR1A = 3500;    // Set up with 50us to stop  100us pulse to Start
  OCR1B = 3500;
  delay(1000);///控制SERVO的TIMER
  
  BT_initialize();
}

void loop() 
{
  // put your main code here, to run repeatedly:
  BT_receive_data();
  BT_print();
  if(joystick_left >127)
  {
    analogWrite(7,255);
    analogWrite(6,0); 
  }
  else if(joystick_left <127)
  {
    analogWrite(7,0);
    analogWrite(6,255);
  }
  else if(joystick_left  = 127)
  {
    analogWrite(7,0);
    analogWrite(6,0);
  }
  
  if (joystick_right >88)
  {
    OCR1A = 5000;
  }
  else if (joystick_right <88)
  {
    OCR1A = 2500;
  }
  else
  {
    OCR1A = 3500;
    }
  if(cellphone_button_A ==1)
  {
  OCR1B = 5000;
  }
 else if(cellphone_button_A ==0)
  {
  OCR1B = 2000;
  }
  
}

void BT_print()
{
Serial.print(joystick_left);
  Serial.print("  ");
  Serial.print(joystick_right);
  Serial.print("  ");
  Serial.print(cellphone_button_front_light);
  Serial.print(cellphone_button_back_light);
  Serial.print(cellphone_button_speaker);
  Serial.print(cellphone_button_A);
  Serial.print(cellphone_button_B);
  Serial.print(cellphone_button_C);
  Serial.print("\n");
}
