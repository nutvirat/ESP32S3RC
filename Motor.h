#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

extern uint8_t BR_Speed;
extern uint8_t FR_Speed;
extern uint8_t BL_Speed;
extern uint8_t FL_Speed;

void motorsetup();
void forward(int d);
void backward(int d);
void turn_right(int d);
void turn_left(int d);
void slide_left(int d);
void slide_right(int d);
void slide_left_forward(int d);
void slide_right_forward(int d);
void slide_left_backward(int d);
void slide_right_backward(int d);
void stop(int d);

#endif