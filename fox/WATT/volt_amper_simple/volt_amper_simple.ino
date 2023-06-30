#include <LiquidCrystal.h>
LiquidCrystal lcd(7,8,9,10,11,12); 
//***************  RS  E   D4  D5 D6 D7
float Amp,Pw,Voltres,Voltin;

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Ahmed Yasser");
  delay(1000);
  lcd.clear();

  lcd.print("Volt & Amper");
  delay(1000);
  lcd.clear();

}
void loop() {
  
  int ADC0 = analogRead(A1);
  int ADC1 = analogRead(A0);
  //**************** حساب التيار *****************//
  Voltres  = ADC0   *4.88;
  Amp      = Voltres/0.5 ;  
  //**************حساب التوتر *****************//
  Voltin   = ADC1 * 4.88*0.00601;
  
  Pw       = Voltin * Amp *0.001 ;
  
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
  lcd.print((int)Pw);
  lcd.print("W");
 
//  delay(250);  
}
