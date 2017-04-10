  /* CONNECT PINS ACCORDINGLY */
  //**** PINS *************
  #define RAIN A0
  #define ULTRAECHO 8
  #define ULTRATRIGGER 9
  #define LDRPIN A1
  #define GASPIN A2
  #define FIREPIN A3
  #define LED 13
  //***********************


  //*** SENSOR SENSITIVITY NEED TO CALIBRATE ELSE CAN CAUSE FALSE POSITIVE***
  #define LIGHTSENSITIVITY 500
  #define GASSENSITIVITY 250
  #define RAINSENSITIVITY 500
  #define DISTANCESENSITIVITY 100 //in CM
  //**************************************
  #define LEDBLINKCOUNT 2


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
    pinMode (FIREPIN, INPUT);
    pinMode(RAIN,INPUT);
    pinMode(ULTRATRIGGER,OUTPUT);
    pinMode(ULTRAECHO,INPUT);
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
      gasvalue=analogRead(GASPIN);//Read Gas SENSOR VALUE                  *
  //************************************************************************



  //*****************FLAME SENSOR READING***********************************
      counter=0;//initalize                                                *
      flamevalue=analogRead(FIREPIN);//Read Fire SENSOR Value              *
      if (flamevalue < 100) {   //                                         *
        time = millis() + 15000; //detecting time + 15 seconds             *
        while(time > millis() && flamevalue < 350)//                       *
        {//                                                                *
            flamevalue = analogRead(FIREPIN);//                            *
            if(flamevalue > 350){//                                        *
              break;//                                                     *
            }//                                                            *
            delay(100);//NEED TO CALIBRATE FOR RELIABILITY               *
            counter ++; //                                                 *
            }//                                                            *
          }//                                                              *
  //************************************************************************


  //******* LED LIGHT ON IF ANY VALUE GET TRUE *****************************
  digitalWrite(LED, LOW);   // turn the LED off
  //if(counter>=14 ||distance<=DISTANCESENSITIVITY ||gasvalue>GASSENSITIVITY|| ldrvalue <LIGHTSENSITIVITY|| rainValue <RAINSENSITIVITY )//flame||ultrasonic||gas||light||rain
  if(gasvalue>GASSENSITIVITY)  {
  i=0;
  while(i<LEDBLINKCOUNT)
  {
    digitalWrite(LED, HIGH);   // turn the LED
    delay(1000);               // wait for a second
    //digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
    //
    delay(500);               // wait for a second
  i++;
  }
  digitalWrite(LED, LOW);   // turn the LED off after blinking
  }
  //***********************************************************************
  delay(1000);
  }
