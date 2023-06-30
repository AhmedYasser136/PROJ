// Ahmed Yasser
// 2 motor industrial

int M1 = 7;
int M2 = 8;

int M3 = 5;
int M4 = 4;

int en1 = 6;
int en2 = 3;


void setup()
{

  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);

}

void loop() {


 
 {

  

  analogWrite(en1 , 60);
  analogWrite(en2 , 60);


  digitalWrite( M1 , 1 );
  digitalWrite( M2 , 0 );
  digitalWrite( M3 , 1 );
  digitalWrite( M4 , 0 );
delay(5000);
 }

   {

    digitalWrite( M1 , 0 );
    digitalWrite( M2 , 1 );
    digitalWrite( M3 , 0 );
    digitalWrite( M4 , 1 );
    delay(5000);
  }


}
