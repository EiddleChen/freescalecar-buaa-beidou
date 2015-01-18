/** ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-03-28, 17:52, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/* MODULE ProcessorExpert */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "CsIO1.h"
#include "IO1.h"
#include "I2C2.h"
#include "MotorRight_PTA5.h"
#include "PwmLdd2.h"
#include "MotorLeft_PTE30.h"
#include "PwmLdd3.h"
#include "MotorLeft_PTE31.h"
#include "PwmLdd4.h"
#include "MotorRight_PTA4.h"
#include "PwmLdd1.h"
#include "TU1.h"
#include "WAIT1.h"
#include "CCD_CLK.h"
#include "BitsIoLdd1.h"
#include "CCD_SI.h"
#include "BitsIoLdd2.h"
#include "EInt1.h"
#include "ExtIntLdd1.h"
#include "EInt2.h"
#include "ExtIntLdd2.h"
#include "Bit1.h"
#include "BitIoLdd1.h"
#include "TU3.h"
#include "Servo_Video1.h"
#include "PwmLdd5.h"
#include "TU2.h"
#include "AD1.h"
#include "AdcLdd1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "stdio.h"
#include "MMA8451.h"
#include "CCD.h"
#include "Motor.h"

/* Global value for TUx*/
LDD_TDeviceData *TU2_Ptr,*TU3_Ptr;

/* Global value for MMA8451 */
extern MMA845X mma845x;

/* Global value for AAC AR2 */
extern int32_t Temp1,Temp2;

/* Global value for CCD */
extern uint16_t Pixels[CCD_Pixels_Width][CCD_Channels];
extern int		CCD_TW_Counter;
extern int		TrackL_Diff;
extern int		TrackR_Diff;

/* Global value for speed */
extern uint32_t SpeedL_Edges;
extern uint32_t SpeedR_Edges;
extern uint32_t SpeedL_Integral,SpeedR_Integral;
extern int32_t Motor_Speed_PWM,Motor_Speed_PWM2;
extern int32_t Sag_Temp1;
extern int32_t Sag_Temp2;
extern int32_t Sag_Temp3;
extern int32_t Integral_AAC_E,Integral_AAC_E2;
extern int32_t	AAC_Z_Correct_Temp;
extern int32_t DebugI,DebugI2;

/* Global value for Motor Control */
extern int32_t MotorControlL,MotorControlR,Mono;
extern int 	 TrackL_Finsh,TrackR_Finsh;

/* Globale value for Console IO */
int State = 0;

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */


int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */



  
  printf("\n\n*----------------------------------------\n");
  printf("* Freescale car Project \n");
  printf("*----------------------------------------\n\n");
  
  /* Internal Accelerometer initialization */
  //MMA845X_Init();
  
 
  /* Timer initialization after all Components init */
  TU3_Init(NULL);
  TU2_Init(NULL);
  
  
  /* Default parameter for Car Control */
  Mono = 1;
  
  /* Before Stand-up  */
  Servo_UP();
  WAIT1_Waitms(300);
  Servo_PowerOFF();
  WAIT1_Waitms(300);
  PowerUp_Correction();
  MotorRight_PTA5_SetRatio16(0);
  MotorRight_PTA4_SetRatio16(0);
  MotorLeft_PTE30_SetRatio16(0);
  MotorLeft_PTE31_SetRatio16(0);	

  
  for(;;)
 {
	 //MMA845X_Poll();
//	 printf("x-axis %d \ny-axis %d \nz-axis %d \n", mma845x.x, mma845x.y, mma845x.z);
//	 printf("\n");

//	 for (i = 0;i < CCD_Pixels_Width; i++) printf("%d,",CCDL(i) / 1000);
//	 printf("\n");
//	 for (i = 0;i < CCD_Pixels_Width; i++) printf("%d,",CCDR(i) / 1000);
//	 printf("\n\n");
//	 printf("Motor_Speed = %d\n",Motor_Speed_PWM);
//	 printf("%d\t%d\t%d\t\n",Motor_Speed_PWM,DebugI,DebugI2);
//	 WAIT1_Waitms(100);
	  
	 /* Polling ACC&Gyo */
//	prinmattf("Sag_Temp2 = %d\n\n",(int32_t)Sag_Temp2);
//	printf("Sag_Temp2 = %d\n\n",(int32_t)( Sag_Temp3 / 20 ));	

	/* Polling Motor */
//	printf("%d,%d\n",(int32_t)Motor_Speed_PWM2,(int32_t)Motor_Speed_PWM);
//	printf("%d\n",Temp2 / 3800);
//	printf("%d\n",(int32_t)Integral_AAC_E);
//	printf("%d\t%d\t\n",Motor_Speed_PWM ,Integral_AAC_E * 0);
//	printf("%d\t%d\t\n",Sag_Temp3 / 128,Integral_AAC_E);
//	printf("\n");
	
	 /* Debug for Motor Control */ 
	 int i;
/*	 for(i = 0; i < 10; i++) WAIT1_Waitms(1000);
	 MotorControlL = 0;
	 MotorControlR = 0;
	 for(i = 0; i < 5; i++) WAIT1_Waitms(1000);
	 MotorControlL = 30000;
	 MotorControlR = 30000;
	 for(i = 0; i < 5; i++) WAIT1_Waitms(1000);
	 MotorControlL = -30000;
	 MotorControlR = -30000;	
*/	 

/*	 for(i = 0; i < 20; i++) WAIT1_Waitms(1000);
	 MotorControlL = -1000;
	 MotorControlR = 1000;	
	 for(i = 0; i < 20; i++) WAIT1_Waitms(1000);
	 MotorControlL = 0;
	 MotorControlR = 0;	
*/
	 /* Debug for Speeder */
//	 printf("%d\t%d\n",SpeedL_Integral,SpeedR_Integral);
	 
	 /* Motor Controled by CCD */
	 //printf("%c\t%c\n",TrackL_Finsh,TrackR_Finsh);
	 
	 /* Debug for Servo */

	 /* Console IO */
	 scanf("%c",&State);
	 switch (State){
	 	 case	'W':{ Processing_Interact(Integral_AAC_E / 1000,Temp2 / 1000,SpeedL_Integral * 10,SpeedR_Integral * 10);break; }
	 	 case 	'w':{ printf("%d\t%d\t%d\t%d\n",Integral_AAC_E / 1000,Temp2 / 1000,SpeedL_Integral * 10,SpeedR_Integral * 10);break; }
	 	 case	'0':{ MotorControlL = MotorControlR = 0; Mono = 1; break;}
		 case	'1':{ if (Mono) Update_Speeder_Integral(); MotorControlL += 2; Mono = 0; break;}
		 case 	'2':{ if (Mono) Update_Speeder_Integral(); MotorControlR += 2; Mono = 0; break;}
		 case	'3':{ if (Mono) Update_Speeder_Integral(); MotorControlL -= 2; Mono = 0; break;}
		 case 	'4':{ if (Mono) Update_Speeder_Integral(); MotorControlR -= 2; Mono = 0; break;} 
		 case 	'5':{ MotorControlL = MotorControlR = (MotorControlL + MotorControlR)  / 2 + 5; Mono = 1; break;} 
		 case 	'6':{ MotorControlL = MotorControlR = (MotorControlL + MotorControlR)  / 2 - 10; Mono = 1; break;} 
		 case	's':{ Stand_Up();break; }
		 case	'l':{ Lay_Down();break; }
	 }
  }

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END ProcessorExpert */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
