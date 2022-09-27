/*
   wheel diagram
    IN1  IN4
    IN2  IN3
*/


#include <Wire.h>
#include <NewPing.h>

NewPing sonar(49, 51); //trig(49) and echo(51)
long inches;
int i = 1000;
int PWM1 = 50;
int PWM2 = 48;
int Speed1 = 130;
int Speed2 = 255;

int IN1 = 31;
int IN2 = 33;
int IN3 = 37;
int IN4 = 35;
int LEFT = 47;
int CENTER = 45;
int RIGHT = 43;

void setup()

{
  pinMode(LEFT, INPUT);
  pinMode(CENTER, INPUT);
  pinMode(RIGHT, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);
}

void Forward()
{
  analogWrite(PWM1, Speed1);
  analogWrite(PWM2, Speed1);
  digitalWrite(IN1, 1);
  digitalWrite(IN2, 0);
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 1);
}

void TurnRight()
{
  analogWrite(PWM1, Speed1);
  analogWrite(PWM2, Speed1);
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 1);
}

void TurnLeft()
{
  analogWrite(PWM1, Speed1);
  analogWrite(PWM2, Speed1);
  digitalWrite(IN1, 1);
  digitalWrite(IN2, 0);
  digitalWrite(IN3, 1);
  digitalWrite(IN4, 0);;
}

void Backward()
{
  analogWrite(PWM1, Speed1);
  analogWrite(PWM2, Speed1);
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);
  digitalWrite(IN3, 1);
  digitalWrite(IN4, 0);
}

void Stop()
{
  analogWrite(PWM1, 0);
  analogWrite(PWM2, 0);
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 0);
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 0);
}

void loop()
{

  inches = sonar.ping_in();

  if (inches > 4) {

    if ((digitalRead(LEFT) == 1) && (digitalRead(CENTER) == 0) && (digitalRead(RIGHT) == 1))
    {
      Forward();
    }

    if ((digitalRead(LEFT) == 0) && (digitalRead(CENTER) == 0) && (digitalRead(RIGHT) == 1))
    {
      TurnRight();
    }

    if ((digitalRead(LEFT) == 0) && (digitalRead(CENTER) == 1) && (digitalRead(RIGHT) == 1))
    {
      TurnRight();
    }

    if ((digitalRead(LEFT) == 1) && (digitalRead(CENTER) == 0) && (digitalRead(RIGHT) == 0))
    {
      TurnLeft();
    }

    if ((digitalRead(LEFT) == 1) && (digitalRead(CENTER) == 1) && (digitalRead(RIGHT) == 0))
    {
      TurnLeft();
    }

    if ((digitalRead(LEFT) == 0) && (digitalRead(CENTER) == 0) && (digitalRead(RIGHT) == 0))
    {
      Forward();
    }

    if ((digitalRead(LEFT) == 1) && (digitalRead(CENTER) == 1) && (digitalRead(RIGHT) == 1))
    {
      Forward();
    }
  }

  else
  {
    Stop();
  }
}
