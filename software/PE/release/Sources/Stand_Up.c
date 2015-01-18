/*
 * Stand_Up.c
 *
 *  Created on: May 25, 2013
 *      Author: chenty
 */
#include "PE_LDD.h"
#define Zero_AAC_Z -9300
extern int	AAC_Z_Correct;
extern int32_t SpeedL_Integral,SpeedR_Integral;
int 		Correction_Before_Stand_Up = 0;
int 		NotStand_Up = 1;

void PowerUp_Correction(){
	Correction_Before_Stand_Up = 1;
	WAIT1_Waitms(60);
	Correction_Before_Stand_Up = 0;
	AAC_Z_Correct = Zero_AAC_Z;
}

void Stand_Up(){
	/* Motor Reset */
	MotorRight_PTA5_SetRatio16(0);
	MotorRight_PTA4_SetRatio16(0);
	MotorLeft_PTE30_SetRatio16(0);
	MotorLeft_PTE31_SetRatio16(0);
	
	/* Power-up Correction Enable */
	Servo_PowerOFF();
	
	/* Stand-up */
	Servo_Down();
	WAIT1_Waitms(300);
	SpeedL_Integral = 0;
	SpeedR_Integral = 0;
	NotStand_Up = 0;
	Servo_UP();
}

void Lay_Down(){
	/* Stand-up */
	Servo_Down2();
	WAIT1_Waitms(300);
	MotorRight_PTA5_SetRatio16(0x0FFF);
	MotorLeft_PTE30_SetRatio16(0x0FFF);
	MotorRight_PTA4_SetRatio16(0);
	MotorLeft_PTE31_SetRatio16(0);	
	SpeedL_Integral = 0;
	SpeedR_Integral = 0;
	NotStand_Up = 1;
	Servo_UP2();
	WAIT1_Waitms(300);
	Servo_PowerOFF();
	MotorRight_PTA5_SetRatio16(0);
	MotorRight_PTA4_SetRatio16(0);
	MotorLeft_PTE30_SetRatio16(0);
	MotorLeft_PTE31_SetRatio16(0);	
}
