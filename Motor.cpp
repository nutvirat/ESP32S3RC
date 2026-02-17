#include <Arduino.h>
#include "Motor.h"

#define MR_IN1 16 //backright motor
#define MR_IN2 15 //backright motor
#define MR_IN3 7  //frontright motor
#define MR_IN4 6  //frontright motor

#define ML_IN1 42 //frontleft motor
#define ML_IN2 41 //frontleft motor
#define ML_IN3 40 //backleft motor
#define ML_IN4 39 //backleft motor

#define BR_ENA 17  //Pin speed backright motor
#define FR_ENB 5   //Pin speed frontright motor
#define FL_ENA 2   //Pin speed frontleft motor
#define BL_ENB 38  //Pin speed backleft motor

uint8_t BR_Speed = 220;  //Adjust speed backright motor
uint8_t FR_Speed = 220;  //Adjust speed frontright motor
uint8_t BL_Speed = 220;  //Adjust speed backleft motor
uint8_t FL_Speed = 220;  //Adjust speed frontleft motor

void motorsetup()
{
  pinMode(MR_IN1, OUTPUT);
  pinMode(MR_IN2, OUTPUT);
  pinMode(MR_IN3, OUTPUT);
  pinMode(MR_IN4, OUTPUT);
  pinMode(ML_IN1, OUTPUT);
  pinMode(ML_IN2, OUTPUT);
  pinMode(ML_IN3, OUTPUT);
  pinMode(ML_IN4, OUTPUT);
  pinMode(FL_ENA, OUTPUT);
  pinMode(BL_ENB, OUTPUT);
  pinMode(BR_ENA, OUTPUT);
  pinMode(FR_ENB, OUTPUT);
  stop(100);
}
void forward(int d)
{
  analogWrite(BR_ENA, BR_Speed); //Pin speed //backright motor
  analogWrite(FR_ENB, FR_Speed); //Pin speed //frontright motor
  analogWrite(BL_ENB, BL_Speed); //Pin speed //backleft motor
  analogWrite(FL_ENA, FL_Speed); //Pin speed //frontleft motor

  digitalWrite(MR_IN1, 0);  //backright motor
  digitalWrite(MR_IN2, 1);   //backright motor
  digitalWrite(MR_IN3, 0);  //frontright motor
  digitalWrite(MR_IN4, 1);   //frontright motor
  digitalWrite(ML_IN1, 1);  //frontleft motor
  digitalWrite(ML_IN2, 0);   //frontleft motor
  digitalWrite(ML_IN3, 0);  //backleft motor
  digitalWrite(ML_IN4, 1);   //backleft motor
  delay(d);
}

void backward(int d)
{
  analogWrite(BR_ENA, BR_Speed); //Pin speed //backright motor
  analogWrite(FR_ENB, FR_Speed); //Pin speed //frontright motor
  analogWrite(BL_ENB, BL_Speed); //Pin speed //backleft motor
  analogWrite(FL_ENA, FL_Speed); //Pin speed //frontleft motor

  digitalWrite(MR_IN1, 1);   //backright motor
  digitalWrite(MR_IN2, 0);  //backright motor
  digitalWrite(MR_IN3, 1);   //frontright motor
  digitalWrite(MR_IN4, 0);  //frontright motor
  digitalWrite(ML_IN1, 0);   //frontleft motor
  digitalWrite(ML_IN2, 1);  //frontleft motor
  digitalWrite(ML_IN3, 1);   //backleft motor
  digitalWrite(ML_IN4, 0);  //backleft motor
  delay(d);
}

void turn_right(int d)
{
  analogWrite(BR_ENA, BR_Speed); //Pin speed //backright motor
  analogWrite(FR_ENB, FR_Speed); //Pin speed //frontright motor
  analogWrite(BL_ENB, BL_Speed); //Pin speed //backleft motor
  analogWrite(FL_ENA, FL_Speed); //Pin speed //frontleft motor

  digitalWrite(MR_IN1, 1);   //backright motor
  digitalWrite(MR_IN2, 0);  //backright motor
  digitalWrite(MR_IN3, 1);   //frontright motor
  digitalWrite(MR_IN4, 0);  //frontright motor
  digitalWrite(ML_IN1, 1);  //frontleft motor
  digitalWrite(ML_IN2, 0);   //frontleft motor
  digitalWrite(ML_IN3, 0);  //backleft motor
  digitalWrite(ML_IN4, 1);   //backleft motor
  delay(d);
}

void turn_left(int d)
{
  analogWrite(BR_ENA, BR_Speed); //Pin speed //backright motor
  analogWrite(FR_ENB, FR_Speed); //Pin speed //frontright motor
  analogWrite(BL_ENB, BL_Speed); //Pin speed //backleft motor
  analogWrite(FL_ENA, FL_Speed); //Pin speed //frontleft motor

  digitalWrite(MR_IN1, 0);  //backright motor
  digitalWrite(MR_IN2, 1);   //backright motor
  digitalWrite(MR_IN3, 0);  //frontright motor
  digitalWrite(MR_IN4, 1);   //frontright motor
  digitalWrite(ML_IN1, 0);   //frontleft motor
  digitalWrite(ML_IN2, 1);  //frontleft motor
  digitalWrite(ML_IN3, 1);   //backleft motor
  digitalWrite(ML_IN4, 0);  //backleft motor
  delay(d);
}

void slide_left(int d)
{
  analogWrite(BR_ENA, BR_Speed); //Pin speed //backright motor
  analogWrite(FR_ENB, FR_Speed); //Pin speed //frontright motor
  analogWrite(BL_ENB, BL_Speed); //Pin speed //backleft motor
  analogWrite(FL_ENA, FL_Speed); //Pin speed //frontleft motor

  digitalWrite(MR_IN1, 1);   //backright motor
  digitalWrite(MR_IN2, 0);  //backright motor
  digitalWrite(MR_IN3, 0);  //frontright motor
  digitalWrite(MR_IN4, 1);   //frontright motor
  digitalWrite(ML_IN1, 0);   //frontleft motor
  digitalWrite(ML_IN2, 1);  //frontleft motor
  digitalWrite(ML_IN3, 0);  //backleft motor
  digitalWrite(ML_IN4, 1);   //backleft motor
  delay(d);
}

void slide_right(int d)
{
  analogWrite(BR_ENA, BR_Speed); //Pin speed //backright motor
  analogWrite(FR_ENB, FR_Speed); //Pin speed //frontright motor
  analogWrite(BL_ENB, BL_Speed); //Pin speed //backleft motor
  analogWrite(FL_ENA, FL_Speed); //Pin speed //frontleft motor

  digitalWrite(MR_IN1, 0);  //backright motor
  digitalWrite(MR_IN2, 1);   //backright motor
  digitalWrite(MR_IN3, 1);   //frontright motor
  digitalWrite(MR_IN4, 0);  //frontright motor
  digitalWrite(ML_IN1, 1);  //frontleft motor
  digitalWrite(ML_IN2, 0);   //frontleft motor
  digitalWrite(ML_IN3, 1);   //backleft motor
  digitalWrite(ML_IN4, 0);  //backleft motor
  delay(d);
}

void slide_left_forward(int d)
{
  analogWrite(BR_ENA, BR_Speed); //Pin speed //backright motor
  analogWrite(FR_ENB, FR_Speed); //Pin speed //frontright motor
  analogWrite(BL_ENB, BL_Speed); //Pin speed //backleft motor
  analogWrite(FL_ENA, FL_Speed); //Pin speed //frontleft motor

  digitalWrite(MR_IN1, 0);   //backright motor
  digitalWrite(MR_IN2, 0);   //backright motor
  digitalWrite(MR_IN3, 0);  //frontright motor
  digitalWrite(MR_IN4, 1);   //frontright motor
  digitalWrite(ML_IN1, 0);   //frontleft motor
  digitalWrite(ML_IN2, 0);   //frontleft motor
  digitalWrite(ML_IN3, 0);  //backleft motor
  digitalWrite(ML_IN4, 1);   //backleft motor
  delay(d);
}

void slide_right_forward(int d)
{
  analogWrite(BR_ENA, BR_Speed); //Pin speed //backright motor
  analogWrite(FR_ENB, FR_Speed); //Pin speed //frontright motor
  analogWrite(BL_ENB, BL_Speed); //Pin speed //backleft motor
  analogWrite(FL_ENA, FL_Speed); //Pin speed //frontleft motor

  digitalWrite(MR_IN1, 0);  //backright motor
  digitalWrite(MR_IN2, 1);   //backright motor
  digitalWrite(MR_IN3, 0);   //frontright motor
  digitalWrite(MR_IN4, 0);   //frontright motor
  digitalWrite(ML_IN1, 1);  //frontleft motor
  digitalWrite(ML_IN2, 0);   //frontleft motor
  digitalWrite(ML_IN3, 0);   //backleft motor
  digitalWrite(ML_IN4, 0);   //backleft motor
  delay(d);
}

void slide_left_backward(int d)
{
  analogWrite(BR_ENA, BR_Speed); //Pin speed //backright motor
  analogWrite(FR_ENB, FR_Speed); //Pin speed //frontright motor
  analogWrite(BL_ENB, BL_Speed); //Pin speed //backleft motor
  analogWrite(FL_ENA, FL_Speed); //Pin speed //frontleft motor

  digitalWrite(MR_IN1, 1);   //backright motor
  digitalWrite(MR_IN2, 0);  //backright motor
  digitalWrite(MR_IN3, 0);   //frontright motor
  digitalWrite(MR_IN4, 0);   //frontright motor
  digitalWrite(ML_IN1, 0);   //frontleft motor
  digitalWrite(ML_IN2, 1);  //frontleft motor
  digitalWrite(ML_IN3, 0);   //backleft motor
  digitalWrite(ML_IN4, 0);   //backleft motor
  delay(d);
}

void slide_right_backward(int d)
{
  analogWrite(BR_ENA, BR_Speed); //Pin speed //backright motor
  analogWrite(FR_ENB, FR_Speed); //Pin speed //frontright motor
  analogWrite(BL_ENB, BL_Speed); //Pin speed //backleft motor
  analogWrite(FL_ENA, FL_Speed); //Pin speed //frontleft motor

  digitalWrite(MR_IN1, 0);   //backright motor
  digitalWrite(MR_IN2, 0);   //backright motor
  digitalWrite(MR_IN3, 1);   //frontright motor
  digitalWrite(MR_IN4, 0);  //frontright motor
  digitalWrite(ML_IN1, 0);   //frontleft motor
  digitalWrite(ML_IN2, 0);   //frontleft motor
  digitalWrite(ML_IN3, 1);   //backleft motor
  digitalWrite(ML_IN4, 0);  //backleft motor
  delay(d);
}

void stop(int d)
{
  digitalWrite(MR_IN1, 0);  //backright motor
  digitalWrite(MR_IN2, 0);  //backright motor
  digitalWrite(MR_IN3, 0);  //frontright motor
  digitalWrite(MR_IN4, 0);  //frontright motor
  digitalWrite(ML_IN1, 0);  //frontleft motor
  digitalWrite(ML_IN2, 0);  //frontleft motor
  digitalWrite(ML_IN3, 0);  //backleft motor
  digitalWrite(ML_IN4, 0);  //backleft motor
  delay(d);
}