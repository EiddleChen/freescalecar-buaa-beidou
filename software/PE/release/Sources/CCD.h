/*
 * CCD.h
 *
 *  Created on: 2013-3-22
 *      Author: chenty
 *
 *  ADC usage:
 *  	Channel0: PTB1	(VIDEO2)
 *  	Channel1: PTB2	(VIDEO3)
 *  	Channel2: PTB3	(AZ)
 *  	Channel3: PTD6	(AR2)
 *  	
 *  AR2 :
 *  	Front:		Sag_Temp2 = 87296651
 *  	Balanced:	Sag_Temp2 = 7497179
 *  	
 */

#ifndef CCD_H_
#define CCD_H_

/* Define for Channel */
#define LCCDL_CH	0
#define LCCDR_CH	1
#define ACC_Z_CH	2
#define AR2_CH		3

/* Const for CCD */
#define CCD_Channels 7
#define CCD_Pixels_Width 128
#define CCD_Setup_Time 2	//tsu us
#define CCD_Hold_Time 1		//th(SI) us
#define CCD_Init_Time 1 	//us
#define CCDL(i) Pixels[i][0]
#define CCDR(i) Pixels[i][1]
#define CCDL_Diff(i) Pixels_Diff[i][0]
#define CCDR_Diff(i) Pixels_Diff[i][1]
#define CCD_Diff_Pattern_Length 6
#define Counter_Patterned (Counter - CCD_Diff_Pattern_Length + 1)
#define MaxTrackL_Threhold 0.006
#define MaxTrackR_Threhold 0.006
#define MaxCCDSag 8388096
#define MinCCDSag 332800

/* Const for Acc&Gyo */
//#define AAC_X(i)	Pixels[i][2]
//#define AAC_Y(i)	Pixels[i][3]
//#define AR1(i)	(Pixels[i][5])
#define AAC_div_AR2 3800
#define AAC_Z		(( ADC_Measured[ACC_Z_CH] - 30272 + AAC_Z_Correct)*AAC_div_AR2) //53919
#define AR2			(( -ADC_Measured[AR2_CH] + 28299 + AR2_Correct))  //DONT MOD this //30625 //29260 //29200 //29260 //28180

/* Const for Speeder */
#define Speed_Correct_Times 8
#define SpeedL		(int32_t)( (SpeedL_Correct_Counter >= Speed_Correct_Times || SpeedL_Correct_Counter <= 0 ) ? (-SpeedL_Edges) : (SpeedL_Edges) - MotorControlL )
#define SpeedR		(int32_t)( (SpeedR_Correct_Counter >= Speed_Correct_Times || SpeedR_Correct_Counter <= 0 ) ? (-0.941*SpeedR_Edges) : (0.941*SpeedR_Edges) - MotorControlR )
#define SpeedL_FB	(int32_t)( k1_Speeder * SpeedL_Integral + K2_Speeder * (int32_t)SpeedL )
#define SpeedR_FB	(int32_t)( k1_Speeder * SpeedR_Integral + K2_Speeder * (int32_t)SpeedR )

/* Define for CCD measure*/
#define CLK_Low_Period CCD_CLK_PutVal(00)
#define CLK_High_Period CCD_CLK_PutVal(11)
		

void GetPixels();

#endif /* CCD_H_ */
 
