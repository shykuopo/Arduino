int lpwmb = 5;
int enb = 30;
int rpwmb = 4;
int lpwma = 6;
int rpwma = 7;
int ena = 48;
int encodera = 49;
int encoderb = 35;
float different = 0 ;
int val = 0;
int val2 = 0;
int state =1;
float fq = 0; 
float fq2 = 0;
int i1 = 0;
int i2 = 0;

void setup()
{
  pinMode(lpwmb,OUTPUT);
  pinMode(enb,OUTPUT);
  pinMode(rpwmb,OUTPUT);
  pinMode(lpwma,OUTPUT);
  pinMode(rpwma,OUTPUT);
  pinMode(ena,OUTPUT);
  pinMode(encodera,INPUT);
  pinMode(encoderb,INPUT);
  Serial.begin(9600);
}
void loop()
{
  digitalWrite(lpwma,HIGH);
  digitalWrite(ena,HIGH);
  digitalWrite(rpwmb,HIGH);
  digitalWrite(enb,HIGH);
  analogWrite(rpwma,0);
  analogWrite(rpwmb,0);
  int i1 = 200 ;
  int i2 = 200;
  analogWrite(rpwma,i1);
  analogWrite(rpwmb,i2);
  val = digitalRead(49);
  val2 =digitalRead(35);
  float halfcycle = pulseIn(49,LOW);
  float halfcycle2 =pulseIn(35,LOW);
  float fq = 1000/(halfcycle*2);
  float fq2 = 1000/(halfcycle2 *2);
  different = fq - fq2;
  Serial.println("*");
  Serial.println(fq);
      Serial.println("*");
      Serial.println(fq2);
  while(different!=0)
  {
    if(different > 0)
    {
      i2 = i2++;
      i1 = i1--;
      analogWrite(rpwma,i1);
      analogWrite(rpwmb,i2);
      val = digitalRead(49);
      val2 =digitalRead(35);
      float halfcycle = pulseIn(49,LOW);
      float halfcycle2 =pulseIn(35,LOW);
      float fq = 1000/(halfcycle*2);
      float fq2 = 1000/(halfcycle2 *2);
      different = fq - fq2;
      Serial.println("i2++");
      Serial.println(different);
      Serial.println(fq);
      Serial.println(fq2);
      Serial.println(i1);
      Serial.println(i2);
    }  
    else
    {
      i1 = i1++;
      i2 = i2--;
      analogWrite(rpwma,i1);
      analogWrite(rpwmb,i2);
      val = digitalRead(49);
      val2 =digitalRead(35);
      float halfcycle = pulseIn(49,LOW);
      float halfcycle2 =pulseIn(35,LOW);
      float fq = 1000/(halfcycle*2);
      float fq2 = 1000/(halfcycle2 *2);
      different = fq - fq2;
      Serial.println("i1++");
      Serial.println(different);
      Serial.println(fq);
      Serial.println(fq2);
      Serial.println(i1);
      Serial.println(i2);
    } 

  }

}

