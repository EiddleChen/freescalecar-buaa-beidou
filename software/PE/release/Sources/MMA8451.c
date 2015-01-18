/*
 * MMA8451.c
 *
 *  Created on: Mar 28, 2013
 *      Author: Chenty
 */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "stdio.h"
#include "MMA8451.h"
#include "I2C2.h"

#define delay 6 //us

volatile bool DataReceivedFlg = FALSE;
volatile bool DataTransmittedFlg = FALSE;

uint8_t OutData[2] = {0x2A, 0x01};                /* Initialization of output data buffer */
uint8_t InData[MMA845X_BUFFER_SIZE];
LDD_TError Error;

LDD_TDeviceData *MyI2CPtr;


MMA845X mma845x;
int16_t mma845_tmp;

volatile bool DataTransmittedFlg;
volatile bool DataReceivedFlg;

static MMA845_STATE measuring = IDLE;
static MMA845_STATE measuring_last = RECEIVE;


/**************************************************************************//*!
* @brief    Timer Interrupt CallBack function
******************************************************************************/
void Timer_Interrupt_CB(void)
{
  if(measuring == IDLE)
  {
    if(measuring_last == TRANSMIT)
      measuring = RECEIVE; 
    else if(measuring_last == RECEIVE)
      measuring = TRANSMIT;
  }
}

/**************************************************************************//*!
* @brief    The IIC Initialization for MMA845x
******************************************************************************/
void MMA845X_Init(void)
{
	// IIC initialization
	MyI2CPtr = I2C2_Init(NULL);
	 

	/* Configure I2C BUS device(e.g. RTC) - Write Operation */
	Error = I2C2_MasterSendBlock(MyI2CPtr, &OutData, 2, LDD_I2C_NO_SEND_STOP); /* Send OutData (4 bytes) on the I2C bus and generates a stop condition to end transmission */
	WAIT1_Waitus(delay);
	//while (!DataTransmittedFlg); 
	DataTransmittedFlg = FALSE;
  
	OutData[0] = MMA845X_DEVICE_ID; 

	Error = I2C2_MasterSendBlock(MyI2CPtr, &OutData, 1, LDD_I2C_NO_SEND_STOP);
	WAIT1_Waitus(delay);
	//while (!DataTransmittedFlg);  
	//DataTransmittedFlg = FALSE;
  
	Error = I2C2_MasterReceiveBlock(MyI2CPtr, &mma845x.id, 1, LDD_I2C_SEND_STOP);
	WAIT1_Waitus(delay);
	//while (!DataReceivedFlg);
	//DataReceivedFlg = FALSE;
}

/**************************************************************************//*!
* @brief    MMA845x polling function 
******************************************************************************/
void MMA845X_Poll(void)
{
    //if(measuring == TRANSMIT)
    {
      measuring = IDLE;
      measuring_last = TRANSMIT;
       
      OutData[0] = MMA845X_CFG_VALUE;
      Error = I2C2_MasterSendBlock(MyI2CPtr, &OutData, 1, LDD_I2C_NO_SEND_STOP); /* Send OutData (4 bytes) on the I2C bus and generates a stop condition to end transmission */
      WAIT1_Waitus(delay);
      //while (!DataTransmittedFlg); 
      //DataTransmittedFlg = FALSE;   
    }
    //else if(measuring == RECEIVE)
    {
      measuring = IDLE;
      measuring_last = RECEIVE;
      Error = I2C2_MasterReceiveBlock(MyI2CPtr, &InData, MMA845X_BUFFER_SIZE, LDD_I2C_SEND_STOP);
      WAIT1_Waitus(delay);
      //while (!DataReceivedFlg);
      //DataReceivedFlg = FALSE;  

      mma845_tmp = InData[1] | (InData[0] << 8);
      mma845x.x = (mma845_tmp / MMA845X_DIVIDER);

      mma845_tmp = InData[3] | (InData[2] << 8);
      mma845x.y = (mma845_tmp / MMA845X_DIVIDER);

      mma845_tmp = InData[5] | (InData[4] << 8);     
      mma845x.z = (mma845_tmp / MMA845X_DIVIDER);   
      
      //printf("x-axis %d \ny-axis %d \nz-axis %d \n", mma845x.x, mma845x.y, mma845x.z);
      //printf("\n");
    }
  //  return mma845x;
}

