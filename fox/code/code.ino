/*
   -- FOX1 --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.7 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.10.2 or later version;
     - for iOS 1.8.2 or later version;
    
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
  { 255,0,0,33,0,88,0,15,31,1,
  67,4,31,29,20,5,2,26,11,67,
  4,32,54,20,5,2,26,11,129,0,
  12,10,42,6,24,65,104,109,101,100,
  32,89,97,115,115,101,114,0,129,0,
  4,29,11,6,12,86,111,108,116,0,
  129,0,4,54,19,6,1,65,109,112,
  101,114,0,67,4,32,73,20,5,2,
  26,11,129,0,4,73,18,6,133,112,
  111,119,101,114,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

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
#include <LiquidCrystal.h>
LiquidCrystal lcd(23,25,27,29,31,33,35,37,39,41); 
//***************  RS  E   D4  D5 D6 D7
float Amp,power,Voltres,Voltin;



void setup() 
{
  RemoteXY_Init (); 
  
    lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Ahmed Yasser");
  delay(1000);
  lcd.clear();

  lcd.print("Volt & Amper");
  delay(1000);
  lcd.clear();

  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  int ADC6 = analogRead(A1);
  int ADC6 = analogRead(A0);
  //**************** حساب التيار *****************//
  Voltres  = ADC0   *4.88;
  Amp      = Voltres/0.5 ;  
  //**************حساب التوتر *****************//
  Voltin   = ADC1 * 4.88*0.00601;
  
  power       = Voltin * Amp *0.001 ;
  
  if(Amp<=1)Amp=0;
  lcd.setCursor(0,0);
  lcd.print("A:");
  lcd.print((int)Amp);
  lcd.print("mA ");
  
  lcd.setCursor(9,0);
  lcd.print("V:");
  lcd.print(Voltin);
  lcd.print("V");
  
  lcd.setCursor(0,1);
  lcd.print("PW:");
  lcd.print((float)power);
  lcd.print("W");

     dtostrf(Voltin, 0, 1, RemoteXY.text_1);
     dtostrf(Amp, 0, 1, RemoteXY.text_2);
     dtostrf(power, 0, 1, RemoteXY.text_3);

delay(500);  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay() 


}
