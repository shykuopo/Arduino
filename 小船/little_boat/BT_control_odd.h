
SoftwareSerial BTSerial(2,3);
unsigned char bluetooth_receive_commands[4] = {0};
int  joystick_left, joystick_right;
bool cellphone_button_A, cellphone_button_B, cellphone_button_C;
bool  cellphone_button_speaker, cellphone_button_front_light, cellphone_button_back_light;
void BT_initialize();
void BT_receive_data();

void BT_initialize() 
{
BTSerial.begin(9600);
//Serial.begin(115200);

}

void BT_receive_data() 
{


if (BTSerial.available() == 4)
  {
   // Serial.println("get bluetooth");

    bluetooth_receive_commands[0] = BTSerial.read();  //Direction
    bluetooth_receive_commands[1] = BTSerial.read();  //Speed
    bluetooth_receive_commands[2] = BTSerial.read();  //Angle
    bluetooth_receive_commands[3] = BTSerial.read();  //Lights and buttons states
  }
  bool temp_boolean_input[8];
  unsigned char temp_for_byte_to_bits = bluetooth_receive_commands[3];
  for(int i=7 ; i>=0 ; i--)
  {
      temp_boolean_input[i]=(temp_for_byte_to_bits>>i) & 0x01;
  }
  
  joystick_left = bluetooth_receive_commands[1];
  joystick_right = bluetooth_receive_commands[2];
  cellphone_button_A = temp_boolean_input[4];
  cellphone_button_B = temp_boolean_input[3];
  cellphone_button_C = temp_boolean_input[2];
  cellphone_button_speaker = temp_boolean_input[5];
  cellphone_button_back_light = temp_boolean_input[6];
  cellphone_button_front_light = temp_boolean_input[7];
}

