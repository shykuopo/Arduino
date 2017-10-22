
#include <SoftwareSerial.h>
#include "BT_control_odd.h"
//#include <Servo.h>

int output1;
int output2;
int output3;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
 pinMode(6,OUTPUT);//馬達控制3PIN
 pinMode(7,OUTPUT);
 pinMode(5,OUTPUT);
 int output1;
 int output2;
 int output3;
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
  //BT_print();

  if (joystick_left ==0 && joystick_right ==0)
  {
    OCR1A = 3500;
    stay();
  }
  else if (joystick_left !=0 && joystick_right ==0)
  {
    OCR1A = 3500;
    if (joystick_left>0)
    {
      forward();
    }
    else if (joystick_left<0)
    {
      backward();
    }
    
  }
  else if (joystick_left !=0 && joystick_right !=0)
  {
    if (joystick_left>0 && joystick_right>0)
    {
      forward();
      right();
    }
    else if (joystick_left>0 && joystick_right<0)
    {
      forward();
      left();
    }
    else if (joystick_left<0 && joystick_right>0)
    {
      backward();
      right();
    }
    else if (joystick_left<0 && joystick_right<0)
    {
      backward();
      left();
    }
  
  }
  else if (joystick_left ==0 && joystick_right !=0)
  {
    if ( joystick_right>0)
    {
      stay();
      right();
    }
    else if (joystick_right<0)
    {
      stay();
      left();
    }
  }
  weapon();
  BT_print();  
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


void forward()
{
  output1 = HIGH;
  output2 = LOW;
  output3 = HIGH;
  analogWrite(5,output3);
  analogWrite(6,output1);
  analogWrite(7,output2);
}
void backward()
{
  output1 = LOW;
  output2 = HIGH;
  output3 = HIGH;
  analogWrite(5,output3);
  analogWrite(6,output1);
  analogWrite(7,output2);
}
void stay()
{
  output1 = LOW;
  output2 = LOW;
  output3 = HIGH;
  analogWrite(5,output3);
  analogWrite(6,output1);
  analogWrite(7,output2);
}
void right()
{
  OCR1A = 2000;
}
void left()
{
  OCR1A = 5000;
}
void weapon()
{
  if (cellphone_button_A == 1)////bool的控制
  {
    OCR1B = 5000;
  }
  else if (cellphone_button_A == 0)
  {
    OCR1B = 2000;
  }
}



