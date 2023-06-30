
//Ahmed Yasser 
int relay1 = 50;
int sw1 = 49;

int relay2 = 52;
int sw2 = 45;

int Y1 ;
int Y2 ;

void setup()
{
  pinMode(relay1, OUTPUT);
  pinMode(sw1, INPUT);

    pinMode(relay2, OUTPUT);
  pinMode(sw2, INPUT);
}
void loop()
{
  Y1 = digitalRead (sw1);
  if (Y1 == HIGH){ 
    digitalWrite(relay1 , HIGH );
  }
  
  else  digitalWrite(relay1 , LOW );

  Y2 = digitalRead (sw2);
  if (Y2 == HIGH){ 
    digitalWrite(relay2 , HIGH );
  }
  
  else  digitalWrite(relay2 , LOW );


  
}
