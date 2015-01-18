/*
 * Correction.c
 *
 *  Created on: May 25, 2013
 *      Author: chenty
 */
#include "PE_LDD.h"
#include "CCD.h"

int		AR2_Correct = 0;
int		AAC_Z_Correct = 0;
int64_t	AR2_Correct_Temp = 0;
int64_t	AAC_Z_Correct_Temp = 0;
int		Correct_Times = 0; 
extern int32_t Temp1,Temp2;
extern int32_t Integral_AAC_E;
extern int32_t SpeedL_Integral,SpeedR_Integral;

void Correction_Start(){
	Correct_Times++;
	AR2_Correct_Temp += Temp1;
	AAC_Z_Correct_Temp += Temp2;
}

void Correction_End(){
	if (AR2_Correct_Temp){
		AR2_Correct -= AR2_Correct_Temp / Correct_Times;
		AAC_Z_Correct -= AAC_Z_Correct_Temp / Correct_Times / AAC_div_AR2 ;
		AR2_Correct_Temp = AAC_Z_Correct_Temp = 0;
		Correct_Times = 0;
		Integral_AAC_E = 0;
		SpeedL_Integral = 0;
		SpeedR_Integral = 0;
	}
}
