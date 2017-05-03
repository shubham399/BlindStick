
char r=13;
char d=34;
char z=26;
int t=0;
int a,b,i,s;
int buzz=A3;
int sensor[]={0,2,3,4,5,6,7,8};
void setup()
{
Serial.begin(9600);
pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(4,INPUT);
pinMode(5,INPUT);
pinMode(6,INPUT);
pinMode(7,INPUT);
pinMode(8,INPUT);
pinMode(A0,OUTPUT);
pinMode(A3,OUTPUT);
delay(5000);
}

void loop()
{
  if(Serial.available())
  {
    a=Serial.read();
    if(a==1)
    {
      buzzer(3);
      wait(5);
      check();
      
    }
  }

}


void buzzer(int b)
{
  for(i=0;i<b;i++)
  {
    digitalWrite(A0,LOW);
    digitalWrite(buzz,HIGH);
    delay(1000);
    digitalWrite(buzz,LOW);
    delay(1000);
    
  }
  return;
}


void wait(int w)
{
  for(i=0;i<w;i++)
  {
    delay(60000);
    
  }
  return;
}


void check()
{
 t=t++;
 //digitalWrite(12,HIGH);
 delay(2000);
 s=digitalRead(sensor[t]);
 if(s==HIGH)
 {
   buzzer(2);
 }
 
}

/*void sms()
{
  delay(3000);
  Serial.print("AT");
  Serial.print(r);
  delay(3000);
  Serial.print("AT+CMGF=1");
  Serial.print(r);
  delay(1000);
  Serial.print("AT+CMGS=");
  Serial.print(d);
  Serial.print("+919036729021");
  Serial.print(d);
  Serial.print(r);
  delay(1000);
  Serial.print("E-Pill Reminder : Patient has not taken medication");
  Serial.print(z);
  delay(10000);
}*/

