/* CONNECT PINS ACCORDINGLY */
//**** PINS *************
#define RAIN A3
#define ULTRAECHO 3
#define ULTRATRIGGER 2
#define LDRPIN A0
//#define GASPIN A2
//#define FIREPIN A3
#define LED 9
#define BUZZER 13
#define VIBRATOR 12
//***********************


//*** SENSOR SENSITIVITY NEED TO CALIBRATE ELSE CAN CAUSE FALSE POSITIVE***
#define LIGHTSENSITIVITY 600
#define FLAMESENSITIVITY 1000
#define GASSENSITIVITY 600
#define RAINSENSITIVITY 300
#define DISTANCESENSITIVITY 50 //in CM
//**************************************


int rainValue=0;//Store rain  Sensor Value
int distance,duration;//store Distance and Duration
int flamevalue=0;//Read FlameSensor value
long time = 0;//To Get FlameSensor Value for 15 second can be brought down
int counter = 0;// TO COUNT NUMBER OF FLAMES TIME this is for Reliable Flame Confermaiton
int gasvalue=0;//TO GAS VALUE
int ldrvalue=0;//TO STORE LDR VALUE
int i=0;


void setup()
{
//pinMode (FIREPIN, INPUT);
  pinMode(RAIN,INPUT);
  pinMode(ULTRATRIGGER,OUTPUT);
  pinMode(BUZZER,OUTPUT);
  pinMode(VIBRATOR,OUTPUT);
  pinMode(LED,OUTPUT);
  pinMode(ULTRAECHO,INPUT);

  Serial.begin(9600);
}





void loop()
{

//******* ULTRA_SONIC SENSOR  READING ************************************
    digitalWrite(ULTRATRIGGER,LOW);//                                    *
    delayMicroseconds(2);//Initalize the Triger                          *
    digitalWrite(ULTRATRIGGER,HIGH);//SEND HIGH VALUE OF TRIGGER         *
    delayMicroseconds(10);//DELAY                                        *
    digitalWrite(ULTRATRIGGER,LOW);//LOWER VALUE OF TRIGGER              *
    duration=pulseIn(ULTRAECHO,HIGH);//GET THE ECHO  TO COMPUTE DURATION *
    distance=duration/58;//TO STORE IN CM                                *
//************************************************************************




//************** READ RAIN LDR AND GAS SENSOR VALUE***********************
    rainValue=analogRead(RAIN);//Read RAINSENSOR VALUE                   *
    ldrvalue=analogRead(LDRPIN);//Read LDR VALUE FOR LIGHT SENSOR        *
    //gasvalue=analogRead(GASPIN);//Read Gas SENSOR VALUE                  *
//************************************************************************



//*****************FLAME SENSOR READING***********************************
  flamevalue=analogRead(FIREPIN);//Read Fire SENSOR Value              *
//************************************************************************


//******* LED LIGHT ON IF ANY VALUE GET TRUE *****************************
digitalWrite(LED, LOW);   // turn the LED off
  Serial.print("Flame=");
  Serial.print(flamevalue);
  Serial.print('\t');
  Serial.print("Gas=");
  Serial.print(gasvalue);
  Serial.print("\t\t");
  Serial.print("LDR=");
  Serial.print(ldrvalue);
  Serial.print("\t\t");
  Serial.print("Rain=");
  Serial.print(rainValue);
  Serial.print('\t');
  Serial.print("Distance=");
  Serial.print(distance);
  Serial.print('\n');

digitalWrite(VIBRATOR, LOW);   // turn the LED
digitalWrite(BUZZER, LOW);   // turn the LED
if(distance<=DISTANCESENSITIVITY)
{
  digitalWrite(VIBRATOR, HIGH);   // turn the LED
}
if(rainValue < RAINSENSITIVITY)
{
  digitalWrite(BUZZER, HIGH);// turn the LED
}
if(ldrvalue> LIGHTSENSITIVITY)
{
  digitalWrite(LED, HIGH);   // turn the LED
}
delay(20);
}
