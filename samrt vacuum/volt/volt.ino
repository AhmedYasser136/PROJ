
#include <LiquidCrystal.h>
LiquidCrystal lcd(23, 25, 27, 29, 31, 33, 35, 37, 39, 41);
//***************  RS  E   D4  D5 D6 D7
float Amp,Pw,Voltres,Voltin;

void setup() {
  lcd.begin(16, 2);


}
void loop() {
  
  int ADC0 = analogRead(A15);
  int ADC1 = analogRead(A15);

  
 
  //**************حساب التوتر *****************//
  Voltin   = ADC1 * 4.88*0.00601;
  
  Pw       = Voltin * Amp *0.001 ;
  
  
  lcd.setCursor(4,0);
  lcd.print("V:");
  lcd.print(Voltin);
  lcd.print("V");
  

 
}
