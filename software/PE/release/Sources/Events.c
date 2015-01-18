/** ###################################################################
**     Filename    : Events.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-03-28, 17:52, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
/**     Settings    :
**     Contents    :
**         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
**
** ###################################################################*/
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "stdio.h"
#include "MMA8451.h"
#include "CCD.h"
#include "Motor.h"

extern volatile bool DataTransmittedFlg;
extern volatile bool DataReceivedFlg;
extern void Timer_Interrupt_CB(void);


/* Global value for speed */
int32_t SpeedL_Counter = 0;
int32_t SpeedL_Edges;
int32_t SpeedR_Counter = 0;
int32_t SpeedR_Edges;
int32_t SpeedL_Integral = 0;
int32_t SpeedR_Integral = 0;
int		SpeedL_Correct_Buff[Speed_Correct_Times], SpeedL_Correct_Pointer = 0, SpeedL_Correct_Counter = 0;
int		SpeedR_Correct_Buff[Speed_Correct_Times], SpeedR_Correct_Pointer = 0, SpeedR_Correct_Counter = 0;


/* Global value for MMA8451 */
extern MMA845X mma845x;

/* Global value for CCD */
extern uint16_t Pixels[CCD_Pixels_Width][2];
extern uint16_t Counter;
uint16_t AAC_Z_ADC;
uint16_t AR2_ADC;
uint16_t ADC_Measured[CCD_Channels];
int		 CCD_TW = 1; 			// *150us
int		 CCD_TW_Counter = 0;

/* Global value for CCD Track */
extern uint16_t MaxTrackL;
extern uint16_t MaxTrackR;
extern int   	Last_TrackL;
extern int		Last_TrackR;
extern int		TrackL;
extern int		TrackR;
extern int		TrackL_Diff;
extern int		TrackR_Diff;
extern uint16_t Pixels_Diff[CCD_Pixels_Width][2];
extern int 	 	TrackL_Finsh,TrackR_Finsh;
extern uint32_t	CCD_SagL;
extern uint32_t CCD_SagR;
extern uint32_t	CCD_SagL_Diff;
extern uint32_t CCD_SagR_Diff;

/* Global value for Self balanced */
int32_t AAC_E[CCD_Pixels_Width],AAC_E2[CCD_Pixels_Width];
int32_t Integral_AAC_E = 0,Integral_AAC_E2 = 0;
int32_t Motor_Speed;
int32_t Sag_Temp1 = 0;
int32_t Sag_Temp2 = 0;
int32_t Sag_Temp3 = 0;
int32_t Temp1,Temp2;
int32_t DebugI,DebugI2;
int32_t Motor_Speed_PWM,Motor_Speed_PWM2;
int32_t MotorControlL = 0,MotorControlR = 0;

/* Global value for Stand-up and  Correction */
extern int	AR2_Correct;
extern int	AAC_Z_Correct;
extern int	Correction_Before_Stand_Up;
extern int	NotStand_Up;

/* Parameter for Control */
#define k 0.0001//0.001
#define k1 0.014//0.02 //0.006	Proportional component for Motor
#define k2 0.9 //0.01 	Integral component for Motor
#define k1_Speeder 20///34// max 220		Proportional component for Speeder
#define K2_Speeder 45//230//300 //220 //		Integral component for Speeder
int		Motor_Controler = 0;
int 	Mono = 1;
/*
** ===================================================================
**     Event       :  TU2_OnCounterRestart_Old (module Events)
**
**     Component   :  TU2 [TimerUnit_LDD]
**     !!IMPORTANT!!:
**         This Function hacked TU2_OnCounterRestart() so to use this 
**         ADD TU2_OnCounterRestart_Old() to TU2_OnCounterRestart() 
**         in PwmLdd5.c first
** ===================================================================
*/

/* Main Interrupt at 100Hz */
void TU2_OnCounterRestart_Old()
{
  /* Write your code here ... */
	//Timer_Interrupt_CB();
	
	 /* MMA8451 working */ 
	//MMA845X_Poll();

	/* CCD&Speed Working */

	/* Speed Polling */
	SpeedL_Edges = SpeedL_Counter;
	SpeedR_Edges = SpeedR_Counter;
	SpeedL_Integral += SpeedL;
	SpeedR_Integral += SpeedR;	
	
	/* Speed Correction */
	SpeedL_Correct_Counter -= SpeedL_Correct_Buff[SpeedL_Correct_Pointer];
	SpeedL_Correct_Buff[SpeedL_Correct_Pointer] = ((Motor_Speed_PWM * 100 + Integral_AAC_E) <= 0);
	SpeedL_Correct_Counter += SpeedL_Correct_Buff[SpeedL_Correct_Pointer];
	SpeedL_Correct_Pointer = (SpeedL_Correct_Pointer + 1) % SpeedL_Correct_Pointer;

	SpeedR_Correct_Counter -= SpeedR_Correct_Buff[SpeedR_Correct_Pointer];
	SpeedR_Correct_Buff[SpeedL_Correct_Pointer] = ((Motor_Speed_PWM * 100 + Integral_AAC_E) <= 0);
	SpeedR_Correct_Counter += SpeedR_Correct_Buff[SpeedR_Correct_Pointer];
	SpeedR_Correct_Pointer = (SpeedR_Correct_Pointer + 1) % SpeedR_Correct_Pointer;
		
	
	/* Speed Init */
	SpeedL_Counter = 0;
	SpeedR_Counter = 0;
	
	/* CCD Polling Debug */
	int i;
//	uint16_t Pix_Temp[CCD_Pixels_Width][2];
//	for (i = 0;i < CCD_Pixels_Width; i++) { Pix_Temp[CCD_Pixels_Width][0] = CCDL(i);Pix_Temp[CCD_Pixels_Width][1] = CCDR(i); }
//	for (i = 0;i < CCD_Pixels_Width; i++) printf("%d\t%d\t%d\t%d\t%d\n",CCDL(i) >> 10,CCDR(i) >> 10,(i>=Temp1)?70:0,(i>=Temp2)?70:0,i);	
//	for (i = 0;i < CCD_Pixels_Width; i++) printf("%d\t%d\t%d\t%d\t%d\n",CCDL(i) >> 10,CCDL_Diff(i) >> 10,(i>=TrackL_Finsh)?70:0,0,i);	
//	for (i = 0;i < CCD_Pixels_Width; i++) printf("%d\t%d\t%d\t%d\t%d\n",CCDR(i) >> 10,CCDR_Diff(i) >> 10,(i>=TrackR_Finsh)?70:0,0,i);	

	
	/* Polling parameters of Components finish, write your code before */	
	
	/* Use click or Correction_Before_Stand_Up for Correction */
	if (!Bit1_GetVal() || Correction_Before_Stand_Up) Correction_Start();
	else Correction_End();
	
	/* Use powerup for Correction */
	Motor_Speed_PWM = (int32_t)( Temp1 * k2  + k1 * Integral_AAC_E );
	DebugI = k1_Speeder * SpeedL_Integral;
	DebugI2 =  (int32_t)SpeedL;

	if (!NotStand_Up){
		if (Mono==1) Set_Motors_Mono( Motor_Speed_PWM - SpeedL_FB , Motor_Speed_PWM - SpeedR_FB ); 
		else Set_Motors( Motor_Speed_PWM - SpeedR_FB , Motor_Speed_PWM - SpeedL_FB ); 
	}
}

/*
** ===================================================================
**     Event       :  I2C2_OnMasterBlockSent (module Events)
**
**     Component   :  I2C2 [I2C_LDD]
**     Description :
**         This event is called when I2C in master mode finishes the
**         transmission of the data successfully. This event is not
**         available for the SLAVE mode and if MasterSendBlock is
**         disabled. 
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void I2C2_OnMasterBlockSent(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
	  DataTransmittedFlg = TRUE;
}

/*
** ===================================================================
**     Event       :  I2C2_OnMasterBlockReceived (module Events)
**
**     Component   :  I2C2 [I2C_LDD]
**     Description :
**         This event is called when I2C is in master mode and finishes
**         the reception of the data successfully. This event is not
**         available for the SLAVE mode and if MasterReceiveBlock is
**         disabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void I2C2_OnMasterBlockReceived(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
	  DataReceivedFlg = TRUE;
}

/*
** ===================================================================
**     Event       :  I2C2_OnError (module Events)
**
**     Component   :  I2C2 [I2C_LDD]
**     Description :
**         This event is called when an error (e.g. Arbitration lost)
**         occurs. The errors can be read with GetError method.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void I2C2_OnError(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  EInt1_OnInterrupt (module Events)
**
**     Component   :  EInt1 [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void EInt1_OnInterrupt(void)
{
  /* Write your code here ... */
	SpeedR_Counter++;
}

/*
** ===================================================================
**     Event       :  EInt2_OnInterrupt (module Events)
**
**     Component   :  EInt2 [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void EInt2_OnInterrupt(void)
{
  /* Write your code here ... */
	SpeedL_Counter++;
}

/*
** ===================================================================
**     Event       :  AD1_OnEnd (module Events)
**
**     Component   :  AD1 [ADC]
**     Description :
**         This event is called after the measurement (which consists
**         of <1 or more conversions>) is/are finished.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/*
** ===================================================================
**     Event       :  TU3_OnCounterRestart (module Events)
**
**     Component   :  TU3 [TimerUnit_LDD]
**     Description :
**         Called if counter overflow/underflow or counter is
**         reinitialized by modulo or compare register matching.
**         OnCounterRestart event and Timer unit must be enabled. See
**         <SetEventMask> and <GetEventMask> methods. This event is
**         available only if a <Interrupt> is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer passed as
**                           the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/

void TU3_OnCounterRestart(LDD_TUserData *UserDataPtr)
{
	
	if ( Counter == CCD_Pixels_Width){
		
		/* Verify Track & Update Last_Track,Track_Diff */
		if ( MaxTrackL > MaxTrackL_Threhold * CCD_SagL_Diff ){
			TrackL_Diff = TrackL - Last_TrackL;
			Last_TrackL = TrackL;
		}
		else TrackL_Diff = 0;				
		if ( MaxTrackR > MaxTrackR_Threhold * CCD_SagR_Diff ){
			TrackR_Diff = TrackR - Last_TrackR;
			Last_TrackR = TrackR;
		}
		else TrackR_Diff = 0;
		
		/* CCD Auto Exposure */
		if ((CCD_SagL > MaxCCDSag)&&(CCD_TW >= 1)) CCD_TW--;
		if (((CCD_SagL+CCD_SagR)/2 < MinCCDSag)&&(CCD_TW <= 10)) CCD_TW++;
		
		/* Track Finshed */
		TrackL_Finsh = TrackL;
		TrackR_Finsh = TrackR;
		/* CCD cycle finish  */
		//////////////////////
		
		//////////////////////
		/* CCD cycle start  */
		// Init ADC Counter, SI and CLK
		CCD_Init();
		CCD_SagL = CCD_SagR = CCD_SagL_Diff = CCD_SagR_Diff = 0;
	}
	else{
		// ADC start working
		AD1_Measure(TRUE);
		AD1_GetValue16(ADC_Measured);
		if (CCD_TW_Counter == CCD_TW - 1) CLK_High_Period;
		
		// Calc the Parameters	
		Temp1 = AR2;
		Temp2 = AAC_Z;
		Integral_AAC_E += Temp1 + k * ( Temp2 - Integral_AAC_E );
		if (CCD_TW_Counter == CCD_TW - 1) {
			CCD_SagL += CCDL(Counter) =  ADC_Measured[LCCDL_CH];
			CCD_SagR += CCDR(Counter) =  ADC_Measured[LCCDR_CH];
			if (Counter > CCD_Diff_Pattern_Length - 1) {
				
				/* Calc CCD_Diff & CCD_Sag */
				CCD_SagL_Diff += CCDL_Diff(Counter) = ( CCDL(Counter) > CCDL(Counter_Patterned) ) ?
												 	  ( CCDL(Counter) - CCDL(Counter_Patterned) ) : 0 ;
				CCD_SagR_Diff += CCDR_Diff(Counter) = ( CCDR(Counter_Patterned) > CCDR(Counter) ) ?
												 	  ( CCDR(Counter_Patterned) - CCDR(Counter) ) : 0 ;
				
				/* Update Track & MaxTrack */
				if (CCDL_Diff(Counter) > MaxTrackL) {
					TrackL = Counter;
					MaxTrackL = CCDL_Diff(Counter);
				}
				if (CCDR_Diff(Counter) > MaxTrackR) {
					TrackR = Counter;
					MaxTrackR = CCDR_Diff(Counter);
				}			
			} 
			Counter++;
			CCD_TW_Counter = 0;
			CLK_Low_Period;
		}
		else { CCD_TW_Counter++;}
	} 
}


/*
** ===================================================================
**     Event       :  Servo_Video1_OnEnd (module Events)
**
**     Component   :  Servo_Video1 [PWM]
**     Description :
**         This event is called when the specified number of cycles has
**         been generated. (Only when the component is enabled -
**         <Enable> and the events are enabled - <EnableEvent>). The
**         event is available only when the <Interrupt service/event>
**         property is enabled and selected peripheral supports
**         appropriate interrupt.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Servo_Video1_OnEnd(void)
{
  /* Write your code here ... */
}

/* END Events */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
