#include <SoftwareSerial.h>
#include<Wire.h>
#define btcMax 128
SoftwareSerial BTC(10,11);
byte cmd[btcMax];
byte len = 0;
void setup() {
Serial.begin(9600);
BTC.begin(19200);
pinMode(6,OUTPUT);
}

void loop(){
  char str[btcMax];
  int i = 0;
  while( i < btcMax) {
if((BTC.available())>0){
  cmd[(len++) % btcMax] = char(BTC.read());
}
else{
  i++;
}
  }
   if ( len ) { // 用串列埠顯示從Android手機傳過來的訊息
   digitalWrite(6,HIGH);
   delay(500); 

        sprintf(str,"%s",cmd);//sprintf() 將格式化字串傳送到陣列
        Serial.println(str);
        cmd[0] = '\0';
}
 len = 0;
}
