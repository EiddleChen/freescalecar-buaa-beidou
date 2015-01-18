/*
 * Servo.c
 *
 *  Created on: May 25, 2013
 *      Author: chenty
 */
#include "Servo_Video1.h"
int PWM_Servo = 0;
int PWM_Servo_High = 11000,PWM_Servo_Low = 2500;

void Servo_Down(){
	for (PWM_Servo = PWM_Servo_Low ; PWM_Servo <= PWM_Servo_High; PWM_Servo+=10){
		Servo_Video1_SetRatio16(0xFFFF-PWM_Servo);
		WAIT1_Waitms(1);
	}
}

void Servo_UP(){
	for (PWM_Servo = PWM_Servo_High ; PWM_Servo >= PWM_Servo_Low; PWM_Servo-=2000){
		Servo_Video1_SetRatio16(0xFFFF-PWM_Servo);
		WAIT1_Waitms(10);
	}
}

void Servo_Down2(){
	for (PWM_Servo = PWM_Servo_Low ; PWM_Servo <= PWM_Servo_High; PWM_Servo+=2000){
		Servo_Video1_SetRatio16(0xFFFF-PWM_Servo);
		WAIT1_Waitms(10);
	}
}

void Servo_UP2(){
	for (PWM_Servo = PWM_Servo_High ; PWM_Servo >= PWM_Servo_Low; PWM_Servo-=10){
		Servo_Video1_SetRatio16(0xFFFF-PWM_Servo);
		WAIT1_Waitms(1);
	}
}


void Servo_PowerOFF(){
	Servo_Video1_SetRatio16(0);
}
