/** ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2012-10-23, 21:59, # CodeGen: 0
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
#include "LED1.h"
#include "LED2.h"
#include "LED3.h"
#include "LED4.h"
#include "WAIT1.h"
#include "GPIO1.h"
#include "AS1.h"
#include "ASerialLdd1.h"
#include "AS2.h"
#include "ASerialLdd2.h"
#include "AS3.h"
#include "ASerialLdd3.h"
#include "USB1.h"
#include "USBInit1.h"
#include "Tx1.h"
#include "Rx1.h"
#include "I2C2.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

#include "MMA8451.h"

static uint8_t cdc_buffer[USB1_DATA_BUFF_SIZE];
static uint8_t in_buffer[USB1_DATA_BUFF_SIZE];

static void CDC_Run(void) {
  int i;

  for(;;) {
    while(USB1_App_Task(cdc_buffer, sizeof(cdc_buffer))==ERR_BUSOFF) {
      /* device not enumerated */
      LED1_Neg(); LED2_Off();
      WAIT1_Waitms(10);
    }
    LED1_Off(); LED2_Neg();
    if (USB1_GetCharsInRxBuf()!=0) {
      i = 0;
      while(   i<sizeof(in_buffer)-1
            && USB1_GetChar(&in_buffer[i])==ERR_OK
           )
      {
        i++;
      }
      in_buffer[i] = '\0';
      (void)USB1_SendString((unsigned char*)"echo: ");
      (void)USB1_SendString(in_buffer);
      (void)USB1_SendString((unsigned char*)"\r\n");
    } else {
      WAIT1_Waitms(10);
    }
  }
}

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
  //MMA8451_Run();
  CDC_Run();
  for(;;)
  {
	  LED1_Neg();
	  AS1_SendChar('U');
	  AS1_SendChar('1');
	  WAIT1_Waitms(500);
	  LED2_Neg();
	  AS2_SendChar('U');
	  AS2_SendChar('2');	  
	  WAIT1_Waitms(500);
	  LED3_Neg();
	  AS3_SendChar('U');
	  AS3_SendChar('3');	  
	  WAIT1_Waitms(500);
	  LED4_Neg();
	  AS1_SendChar(0x0d);
	  AS1_SendChar(0x0a);
	  AS2_SendChar(0x0d);
	  AS2_SendChar(0x0a);	  
	  AS3_SendChar(0x0d);
	  AS3_SendChar(0x0a);	  	  
	  WAIT1_Waitms(500);	  
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
