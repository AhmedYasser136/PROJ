int led1 = 4;
int led2 = 5;
int led3 = 6;
int led4 = 7;
int sw = 8;
int A = 0;
int Y;
void setup()
{


  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);



  pinMode(sw, INPUT);



  digitalWrite(led1 , HIGH );
  digitalWrite(led2 , HIGH );
  digitalWrite(led3 , HIGH );
  digitalWrite(led4 , HIGH );






}

void loop()
{
  Y = digitalRead (sw);
  if (Y == HIGH) {
    delay (250);
    A++;
  }



  if (A == 1) {
    digitalWrite(led1 , LOW );
    delay(1000);
    digitalWrite(led2 , LOW );
    delay(1000);
    digitalWrite(led3 , LOW );
    delay(1000);
    digitalWrite(led4 , LOW );
  }



  else if (A == 2) {
    digitalWrite(led1 , HIGH );
    digitalWrite(led2 , HIGH );
    digitalWrite(led3 , HIGH );
    digitalWrite(led4 , HIGH );

    delay(500);



  }

  else if (A == 3) {
    digitalWrite(led1 , LOW );
    delay(1000);
    digitalWrite(led3 , LOW );
    delay(1000);
    digitalWrite(led2 , HIGH );
    digitalWrite(led4 , HIGH );


  }
  else if (A == 4) {
    digitalWrite(led1 , HIGH );
    digitalWrite(led3 , HIGH );
    digitalWrite(led2 , HIGH );
    digitalWrite(led4 , HIGH );
    delay(500);



  }

  else if (A == 5) {

    digitalWrite(led2 , LOW );
    delay(1000);
    digitalWrite(led4 , LOW );
    delay(1000);
    digitalWrite(led1 , HIGH );
    digitalWrite(led3 , HIGH );

  }
  else if (A == 6) {
    digitalWrite(led1 , HIGH );
    digitalWrite(led3 , HIGH );
    digitalWrite(led2 , HIGH );
    digitalWrite(led4 , HIGH );
    delay(500);

    A = 0 ;


  }





}
