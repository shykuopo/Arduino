char chr;
char data[4];
int i ;
void setup() {
  // put your setup code here, to run once:

}

void loop()
{
  // put your main code here, to run repeatedly:

if (Serial.available())
{
    // 讀取傳入的字元值
  while ((chr = Serial.read()) != '\n') 
  {
       // 確認索引i小於3（確保僅讀取前三個字）
     if (chr >= '0' && chr <= '9' &&i < 4 )
     {
       data[i] = chr;
       i++;
     }
  }
}
  char number[3];
  char type;
  type = data[0];
  for (int i=1;i<sizeof(data);i++){
    number[i-1]+=data[i];
  }
  Serial.print(number);
  Serial.print(data[0]);
  int pin = atoi(number);
}
