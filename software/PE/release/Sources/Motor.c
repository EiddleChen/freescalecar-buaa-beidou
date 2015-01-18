/*
 * Motor.c
 *
 *  Created on: Apr 22, 2013
 *      Author: chenty
 */
#include "PE_Types.h"
#include "MotorRight_PTA4.h"
#include "MotorLeft_PTE31.h"
#include "MotorLeft_PTE30.h"
#include "MotorRight_PTA5.h"
#define Death_Range 0
#define Enhanced 500
#define k4 1 //0.5
#define Over_Range 50000
#define Anti_Shake_Freq 100

int Dead = 0;
int Over = 0;
int AntiShake_Buff[Anti_Shake_Freq][2],AntiShake_Pointer = 3-1;
int AntiShake_Pos_L = 0,AntiShake_Pos_R = 0;
extern int32_t SpeedL_Integral;
extern int32_t SpeedR_Integral;

void Set_Motors_Mono(int32_t Left,int32_t Right){
	Set_Motors( (Left+Right) / 2, (Left+Right) / 2);
}

void Set_Motors(int32_t Left,int32_t Right){
	/* Motor Dead! */
	//Right *= 1.19;
	Dead = 0;
	Over = 0;
	if (abs(Left) < Death_Range){
		MotorLeft_PTE30_SetRatio16(0);
		MotorLeft_PTE31_SetRatio16(0);
		Dead = 1;
	}
	if (abs(Right) < Death_Range){
		MotorRight_PTA5_SetRatio16(0);
		MotorRight_PTA4_SetRatio16(0);		
		Dead = 1;
	} 
	if (Dead == 1) return;
	
	/* Motor Over Range */
	if (abs(Left) > Over_Range){
		if (Left > 0 ) Left = Over_Range;
		else Left = - Over_Range;
	}
	if (abs(Right) > Over_Range){
		if (Right > 0 ) Right = Over_Range;
		else Right = - Over_Range;
	}

	/* Anti-Shake */
/*	AntiShake_Pos_L -= AntiShake_Buff[AntiShake_Pointer][0];
	AntiShake_Pos_L += AntiShake_Buff[AntiShake_Pointer][0] = (Left >=0 ) ? 1:0;
	AntiShake_Pos_R -= AntiShake_Buff[AntiShake_Pointer][1];
	AntiShake_Pos_R += AntiShake_Buff[AntiShake_Pointer][1] = (Right >=0) ? 1:0;	
	AntiShake_Pointer = (AntiShake_Pointer + 1) % Anti_Shake_Freq;
//	Left = (AntiShake_Pos_L > Anti_Shake_Freq / 2)  || (abs(Left) > 10000) ? Left : -Left;
//	Right = (AntiShake_Pos_R > Anti_Shake_Freq / 2) || (abs(Right) > 10000) ? Right : -Right;
*/	
	/* Motor Work! */
	if (Left > 0){
		MotorLeft_PTE30_SetRatio16( (uint16_t)( k4 * (Left + Enhanced) ) );
		MotorLeft_PTE31_SetRatio16(0);
	}
	else{
		MotorLeft_PTE30_SetRatio16(0);
		MotorLeft_PTE31_SetRatio16( (uint16_t)( -k4 * (Left - Enhanced) ) );		
	}
	if (Right > 0){
		MotorRight_PTA5_SetRatio16( (uint16_t)( k4 * (Right + Enhanced) ) );
		MotorRight_PTA4_SetRatio16(0);
	}
	else{
		MotorRight_PTA5_SetRatio16(0);
		MotorRight_PTA4_SetRatio16( (uint16_t)( -k4 * (Right - Enhanced) ) );		
	}
}

void Update_Speeder_Integral(){
	SpeedL_Integral = SpeedR_Integral = (SpeedL_Integral + SpeedR_Integral) / 2;
}
