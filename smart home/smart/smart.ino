/*
   -- New project --

   This source code of graphical user interface
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 2.4.3 or later version
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/
     - for ANDROID 4.5.1 or later version;
     - for iOS 1.4.1 or later version;

   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library
#define REMOTEXY_MODE__HARDSERIAL

#include <RemoteXY.h>

// RemoteXY connection settings
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 9600


// RemoteXY configurate
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
{ 255, 5, 0, 33, 0, 71, 1, 10, 31, 6,
  2, 0, 71, 5, 14, 10, 43, 15, 17, 10,
  1, 2, 26, 31, 31, 79, 78, 0, 79, 70,
  70, 0, 129, 0, 45, 5, 18, 6, 23, 17,
  18, 6, 1, 17, 108, 101, 100, 32, 49, 0,
  131, 1, 5, 7, 20, 7, 2, 12, 20, 7,
  1, 80, 24, 80, 97, 103, 101, 49, 0, 2,
  0, 71, 19, 14, 10, 43, 28, 17, 10, 1,
  2, 26, 31, 31, 79, 78, 0, 79, 70, 70,
  0, 129, 0, 45, 20, 18, 6, 23, 31, 18,
  6, 1, 17, 108, 101, 100, 32, 50, 0, 2,
  0, 71, 33, 14, 10, 43, 43, 17, 11, 1,
  2, 26, 31, 31, 79, 78, 0, 79, 70, 70,
  0, 129, 0, 45, 34, 18, 6, 23, 44, 18,
  6, 1, 17, 108, 101, 100, 32, 51, 0, 2,
  0, 71, 48, 14, 10, 43, 58, 17, 10, 1,
  2, 26, 31, 31, 79, 78, 0, 79, 70, 70,
  0, 129, 0, 46, 49, 18, 6, 26, 60, 18,
  6, 1, 17, 102, 97, 110, 32, 0, 131, 0,
  5, 26, 20, 7, 2, 37, 20, 7, 2, 2,
  31, 80, 97, 103, 101, 50, 0, 131, 0, 5,
  44, 20, 7, 3, 67, 20, 7, 3, 2, 190,
  80, 97, 103, 101, 32, 51, 0, 129, 0, 40,
  8, 18, 6, 17, 22, 18, 6, 2, 2, 84,
  101, 109, 112, 0, 4, 0, 82, 17, 7, 25,
  38, 36, 12, 37, 3, 2, 8, 129, 0, 41,
  39, 14, 6, 16, 51, 18, 6, 2, 2, 108,
  105, 103, 104, 116, 32, 0, 129, 0, 44, 20,
  14, 6, 36, 11, 18, 6, 3, 2, 112, 119,
  109, 0, 67, 4, 39, 22, 20, 5, 39, 22,
  20, 5, 2, 2, 26, 11, 67, 4, 39, 52,
  20, 5, 38, 52, 20, 5, 2, 2, 26, 11,
  67, 4, 42, 37, 20, 5, 35, 30, 20, 5,
  3, 2, 26, 11
};

// this structure defines all the variables and events of your control interface
struct {

  // input variables
  uint8_t leda; // =1 if switch ON and =0 if OFF
  uint8_t ledb; // =1 if switch ON and =0 if OFF
  uint8_t ledc; // =1 if switch ON and =0 if OFF
  uint8_t fan; // =1 if switch ON and =0 if OFF
  int8_t slider_1; // =0..100 slider position

  // output variables
  char text_1[11];  // string UTF8 end zero
  char text_2[11];  // string UTF8 end zero
  char text_3[11];  // string UTF8 end zero
  // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define PIN_LEDA 5
#define PIN_LEDB 6
#define PIN_LEDC 7
#define PIN_FAN 8
int value = 0;          //initializing variables
float volts = 0.0;
float temp = 0.0;
unsigned long perviosTime = 0  ;
unsigned long gerviosTime = 10000  ;
void setup()
{
  RemoteXY_Init ();
  Serial.begin(9600); // Start Serial.

  pinMode (PIN_LEDA, OUTPUT);
  pinMode (PIN_LEDB, OUTPUT);
  pinMode (PIN_LEDC, OUTPUT);
  pinMode (PIN_FAN, OUTPUT);
  // pinMode   ( A5 , OUTPUT );
  // TODO you setup code

}




void loop()
{
  RemoteXY_Handler ();
  unsigned long currentTime ;




  currentTime = millis ();
  if ((currentTime - perviosTime  ) >= gerviosTime)
  {

    value = analogRead(A5);        //read from A0
    volts = (value / 1024.0) * 5.0; //conversion to volts
    temp = volts * 100.0;          //conversion to temp Celsius

    dtostrf(temp, 0, 1, RemoteXY.text_1);


    perviosTime = currentTime;
  }






  digitalWrite(PIN_LEDA, (RemoteXY.leda == 0) ? LOW : HIGH);
  digitalWrite(PIN_LEDB, (RemoteXY.ledb == 0) ? LOW : HIGH);
  digitalWrite(PIN_LEDC, (RemoteXY.ledc == 0) ? LOW : HIGH);
  digitalWrite(PIN_FAN, (RemoteXY.fan == 0) ? LOW : HIGH);







  analogWrite(9, RemoteXY.slider_1 * 2.55);
  Serial.println(            RemoteXY.slider_1   );
  dtostrf(RemoteXY.slider_1, 0, 1, RemoteXY.text_3);







  int analogValue = analogRead(A4);
  dtostrf(analogValue, 0, 1, RemoteXY.text_2);







  //||
  /* if( temp >= 10 )
     {
          digitalWrite(8, HIGH) ;

     }*/
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay()

  /* { Serial.println(analogRead(A4));

    if(analogRead(A4) <= 200     ||    RemoteXY.leda   == 1       )
    {
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH) ;
    //  delay(100);
      }

    else {
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      }
         // delay(100);

      }*/


}
