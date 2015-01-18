/*
 * CCD.c
 *
 *  Created on: 2013-3-22
 *      Author: chenty
 */


#include "CCD.h"
#include "PE_Types.h"
#include "CCD_SI.h"
#include "CCD_CLK.h"

/* Global value for CCD */
uint16_t Pixels[CCD_Pixels_Width][2];
uint16_t Counter = CCD_Pixels_Width;
uint16_t Pixels_Diff[CCD_Pixels_Width][2];
uint16_t MaxTrackL = 0;
uint16_t MaxTrackR = 0;
int		 Last_TrackL = 127;
int		 Last_TrackR = 0;
int		 TrackL = 127;
int		 TrackR = 0;
int		 TrackL_Diff = 0;
int		 TrackR_Diff = 0;
int 	 TrackL_Finsh,TrackR_Finsh;
uint32_t	CCD_SagL = 0;
uint32_t 	CCD_SagR = 0;
uint32_t	CCD_SagL_Diff = 0;
uint32_t 	CCD_SagR_Diff = 0;


/* Init for CCD Measure */
void CCD_Init(){
	/* Make all SI and CLK be Low for init */
	CCD_SI_PutVal(00);
	CCD_CLK_PutVal(00);
	WAIT1_Waitus(CCD_Init_Time);

	/* set SI to enable CCD Measure  */
	CCD_SI_PutVal(11);
	WAIT1_Waitus(CCD_Setup_Time);
	CCD_CLK_PutVal(11);
	WAIT1_Waitus(CCD_Hold_Time);
	CCD_SI_PutVal(00);
	
	/* CLK Low */
	CLK_Low_Period;
	
	/* Init for Counter & Track */
	Counter = 0;
	MaxTrackL = MaxTrackR = 0;
}

void CCD_measure_init(){		
	/* CLK High Period */
	CCD_CLK_PutVal(11);
//	WAIT1_Waitus(CCD_TW);

	/* CLK Low Period */
	CCD_CLK_PutVal(00);
//	WAIT1_Waitus(CCD_TW);
    if (Counter < CCD_Pixels_Width) AD1_Measure(FALSE);  // measure all channel, wait for result
    else Counter = 0 ;
//    AD1_GetValue16(Pixels[Counter]);  // Get AD conversion result
}
