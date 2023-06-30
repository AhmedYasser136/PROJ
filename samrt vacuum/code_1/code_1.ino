//LCD
#include <LiquidCrystal.h>
LiquidCrystal lcd(23, 25, 27, 29, 31, 33, 35, 37, 39, 41);

// VOLT
float Amp, Pw, Voltres, Voltin;

//WATER
int level_1   = A9;
int level_2   = A10;
int level_3   = A11;
int level_4   = A12;
int level_5   = A13;
int level_6   = A14;
int a;
int b;
int c;
int d;
int e;
int s;
int z = 100;

// RELAY 1 & 2
int relay1 = 50;
int sw1    = 49;
int relay2 = 52;
int sw2    = 45;

int Y1 ;
int Y2 ;
int A = 0;
int Y;

// MOTOR
int r1 = 7;
int r2 = 8;
int R1 = 5;
int R2 = 4;
int en1 = 6;
int en2 = 3;

// MOTOR 2
int q1 = 13;
int q2 = 48;
int w1 = 11;
int w2 = 10;
int enq1 = 12;
int enw2 = 9;

//IR
int IR = A2 ;
int reading;

// ULTRASONIC
int trig1  = 44;
int echo1  = 46;
float duration1;
int distance1;
float ultrasonic1()
{
  digitalWrite(trig1, LOW);
  digitalWrite(trig1, HIGH);
  digitalWrite(trig1, LOW);
  duration1 = pulseIn(echo1, HIGH);
  distance1 = 0.034 * duration1 / 2;
}
int trig2  = 40;
int echo2  = 42;
float duration2;
int distance2;
float ultrasonic2()
{
  digitalWrite(trig2, LOW);
  digitalWrite(trig2, HIGH);
  digitalWrite(trig2, LOW);
  duration2 = pulseIn(echo2, HIGH);
  distance2 = 0.034 * duration2 / 2;
}

int trig3  = 28; //اليمين
int echo3  = 30;
float duration3;
int distance3;
float ultrasonic3()
{
  digitalWrite(trig3, LOW);
  digitalWrite(trig3, HIGH);
  digitalWrite(trig3, LOW);
  duration3 = pulseIn(echo3, HIGH);
  distance3 = 0.034 * duration3 / 2;
}

// Motion
void straight()
{
  digitalWrite(r1, 0);
  digitalWrite(r2, en1);
  digitalWrite(R1, 0);
  digitalWrite(R2, en2);
}
void right()
{
  digitalWrite(r1, 0);
  digitalWrite(r2, 0);
  digitalWrite(R1, 0);
  digitalWrite(R2, en2 );
}
void left()
{
  digitalWrite(r1, 0);
  digitalWrite(r2, en1);
  digitalWrite(R1, 0);
  digitalWrite(R2, 0 );
}
void Back()
{
  digitalWrite(r1, en1);
  digitalWrite(r2, 0);
  digitalWrite(R1, en2);
  digitalWrite(R2, 0);
}

// delay
unsigned long perviosTime = 0  ;
unsigned long gerviosTime = 2000  ;

void setup() {

  pinMode(echo1, INPUT);
  pinMode(trig1, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo3, INPUT);
  pinMode(trig3, OUTPUT);

  pinMode(r1,   OUTPUT);
  pinMode(r2,   OUTPUT);
  pinMode(R1,   OUTPUT);
  pinMode(R2,   OUTPUT);
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);

  pinMode(q1,   OUTPUT);
  pinMode(q2,   OUTPUT);
  pinMode(w1,   OUTPUT);
  pinMode(w2,   OUTPUT);
  pinMode(enq1, OUTPUT);
  pinMode(enw2, OUTPUT);

  pinMode(level_1, INPUT);
  pinMode(level_2, INPUT);
  pinMode(level_3, INPUT);
  pinMode(level_4, INPUT);
  pinMode(level_5, INPUT);
  pinMode(level_6, INPUT);

  lcd.begin(16, 2);
  Serial.begin (9600);

  pinMode(relay1, OUTPUT);
  pinMode(sw1,    INPUT);
  pinMode(relay2, OUTPUT);
  pinMode(sw2,    INPUT);

}

void loop() {

  a = analogRead(level_1);
  b = analogRead(level_2);
  c = analogRead(level_3);
  d = analogRead(level_4);
  e = analogRead(level_5);
  s = analogRead(level_6);
  if ( s > z && e > z && d > z && c > z && b > z && a > z )
  {
    lcd.setCursor(0, 1);
    lcd.print("tank over full");
  }
  if (s < z && e > z && d > z && c > z && b > z && a > z )
  {
    lcd.setCursor(0, 1);
    lcd.print("Tank is 100% ");
  }
  else if ( s < z &&  e < z && d > z && c > z && b > z && a > z )
  {
    lcd.setCursor(0, 1);
    lcd.print("Tank is 80% ");
  }
  else if ( s < z && e < z && d < z && c > z && b > z && a > z )
  {
    lcd.setCursor(0, 1);
    lcd.print("Tank is 60% ");
  }
  else if (s < z && e < z && d < z && c < z && b > z && a > z )
  {
    lcd.setCursor(0, 1);
    lcd.print("Tank is 40%    ");
  }
  else if (s < z && e < z && d < z && c < z && b < z && a > z )
  {
    lcd.setCursor(0, 1);
    lcd.print("Tank is 20% ");
  }

  else if (s < z && e < z && d < z && c < z && b < z && a < z )
  {
    lcd.setCursor(0, 1);
    lcd.print("Tank is EMPTY   ");
  }



  int ADC1 = analogRead(A15);
  //**************حساب التوتر *****************//
  Voltin   = ADC1 * 4.88 * 0.00601;
  Pw       = Voltin * Amp * 0.001 ;
  lcd.setCursor(1, 0);
  lcd.print("V:");
  lcd.print(Voltin);
  lcd.print("V");
  unsigned long currentTime ;
  currentTime = millis ();
  if ((currentTime - perviosTime  ) >= gerviosTime)
  {
    lcd.clear();
    perviosTime = currentTime;
  }


  Y1 = digitalRead (sw1);
  if (Y1 == HIGH) {
    digitalWrite(relay1 , HIGH );
  }
  else  digitalWrite(relay1 , LOW );


  Y2 = digitalRead (sw2);
  if (Y2 == HIGH) {
    digitalWrite(relay2 , HIGH );
    delay(10);
    digitalWrite(relay2 , LOW );


  }



  analogWrite(en1 , 120);
  analogWrite(en2 , 120);

  analogWrite(enq1 , 100);
  analogWrite(enw2 , 130);

  digitalWrite(q1, en1);
  digitalWrite(q2, 0);
  digitalWrite(w1, 0);
  digitalWrite(w2, en2);


  ultrasonic1();
  ultrasonic2();
  ultrasonic3();

  Serial.print ("distance1 =");
  Serial.println(distance1);
  Serial.print ("distance2 =");
  Serial.println(distance2);
  Serial.print ("distance3 =");
  Serial.println(distance3);
  delay(100);


  reading = digitalRead(IR);
  if ( reading == 1)
  {
    Back();
    delay(1000);
    right ();
    delay(2700);
  }




  if (distance1 < 30)
  {
    A++;
  }
  if ( A == 0  || A == 2 )
  {
    straight();
    if (distance2 < 14)
      right();
    delay(14);
    if (distance3 < 14)
      left();
    delay(14);
  }
  if (A == 1)
  {
    left ();
    if (distance2 < 14)
      right();
    delay(14);
    if (distance3 < 14)
      left();
    delay(14);
    delay(3500);//////////////////
    A = 2;
  }
  if (A == 3)
  {
    right ();
    if (distance2 < 14)
      right();
    delay(14);
    if (distance3 < 14)
      left();
    delay(14);
    delay(3200);/////////////////
    A = 4;
  }

  if (A == 4)
  {
    A = 0 ;
  }


}
