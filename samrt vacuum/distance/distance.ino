
#include <LiquidCrystal.h>
LiquidCrystal lcd(23, 25, 27, 29, 31, 33, 35, 37, 39, 41);


int trig1  = 28;
int echo1  = 30;
float duration1;
int distance1;


int trig2  = 40;
int echo2  = 42;
float duration2;
int distance2;


int trig3  = 44;
int echo3  = 46;
float duration3;
int distance3;



void setup() {
  lcd.begin(16, 2);

  pinMode(echo1, INPUT);
  pinMode(trig1, OUTPUT);

  pinMode(echo2, INPUT);
  pinMode(trig2, OUTPUT);

  pinMode(echo3, INPUT);
  pinMode(trig3, OUTPUT);

  Serial.begin (9600);
}

void loop() {



  digitalWrite(trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);
  duration1 = pulseIn(echo1, HIGH);
  distance1 = 0.034 * duration1 / 2;
  Serial.print ("distance1 =");
  Serial.println(distance1);

  lcd.setCursor(0, 0);
  lcd.print("d1=");
  lcd.print(distance1);
  //delay(500);
  //lcd.clear();



  
  digitalWrite(trig2, LOW);
  delayMicroseconds(2);
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);
  duration2 = pulseIn(echo2, HIGH);
  distance2 = 0.034 * duration2 / 2;
  Serial.print ("distance2 =");
  Serial.println(distance2);

  lcd.setCursor(8, 0);
  lcd.print("d2=");
  lcd.print(distance2);
  //delay(500);
  //lcd.clear();



  
  digitalWrite(trig3, LOW);
  delayMicroseconds(2);
  digitalWrite(trig3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig3, LOW);
  duration3 = pulseIn(echo3, HIGH);
  distance3 = 0.034 * duration3 / 2;
  Serial.print ("distance3 =");
  Serial.println(distance3);

  lcd.setCursor(0, 1);
  lcd.print("d3=");
  lcd.print(distance3);
  delay(1000);
  lcd.clear();


}
