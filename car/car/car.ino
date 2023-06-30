#define REMOTEXY_MODE__HARDSERIAL
#include <RemoteXY.h>
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 9600
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
{ 255, 6, 0, 0, 0, 28, 0, 14, 31, 0,
  6, 0, 84, 15, 31, 31, 2, 26, 5, 52,
  -13, 9, 47, 47, 2, 26, 31, 4, 0, 51,
  4, 9, 56, 2, 26
};
struct {
  uint8_t rgb_1_r; // =0..255 Red color value
  uint8_t rgb_1_g; // =0..255 Green color value
  uint8_t rgb_1_b; // =0..255 Blue color value
  int8_t joystick_1_x; // =-100..100 x-coordinate joystick position
  int8_t joystick_1_y; // =-100..100 y-coordinate joystick position
  unsigned char slider_1; /* =0..100 slider position */
  uint8_t connect_flag;  // =1 if wire connected, else =0
} RemoteXY;
#pragma pack(pop)
#define red 3
#define green 10
#define blue 11
#define PIN_MOTOR_RIGHT_UP 7
#define PIN_MOTOR_RIGHT_DN 8
#define PIN_MOTOR_RIGHT_SPEED 5

#define PIN_MOTOR_LEFT_UP 2
#define PIN_MOTOR_LEFT_DN 4
#define PIN_MOTOR_LEFT_SPEED 6

unsigned char RightMotor[3] =
{PIN_MOTOR_RIGHT_UP, PIN_MOTOR_RIGHT_DN, PIN_MOTOR_RIGHT_SPEED};
unsigned char LeftMotor[3] =
{PIN_MOTOR_LEFT_UP, PIN_MOTOR_LEFT_DN, PIN_MOTOR_LEFT_SPEED};
void Wheel (unsigned char * motor, int v)
{
  if (v > 100) v = 100;
  if (v < -100) v = -100;

  if (v > 0) {
    digitalWrite(motor[0], HIGH);
    digitalWrite(motor[1], LOW);
    analogWrite(motor[2], v * 2.55);
  }
  else if (v < 0) {
    digitalWrite(motor[0], LOW);
    digitalWrite(motor[1], HIGH);
    analogWrite(motor[2], (-v) * 2.55);
  }
  else {
    digitalWrite(motor[0], LOW);
    digitalWrite(motor[1], LOW);
    analogWrite(motor[2], 0);
  }
}
#include <Servo.h>
Servo myservo;

void setup()
{
  RemoteXY_Init ();
  myservo.attach(9);
  RemoteXY.slider_1 = 50;
  pinMode (PIN_MOTOR_RIGHT_UP, OUTPUT);
  pinMode (PIN_MOTOR_RIGHT_DN, OUTPUT);
  pinMode (PIN_MOTOR_LEFT_UP, OUTPUT);
  pinMode (PIN_MOTOR_LEFT_DN, OUTPUT);


}
void loop()
{
  RemoteXY_Handler ();
  Wheel (RightMotor, RemoteXY.joystick_1_y - RemoteXY.joystick_1_x);
  Wheel (LeftMotor, RemoteXY.joystick_1_y + RemoteXY.joystick_1_x);
  analogWrite(blue, 255);
  analogWrite(green, 255);
  analogWrite(red, 255);
  analogWrite(blue, RemoteXY.rgb_1_b);
  analogWrite(green, RemoteXY.rgb_1_g);
  analogWrite(red, RemoteXY.rgb_1_r);
  int ms = RemoteXY.slider_1 * 20 + 500;
  myservo.writeMicroseconds(ms);

}
