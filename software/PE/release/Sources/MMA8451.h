/** ###################################################################
**     Filename    : ProcessorExpert.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**
** ###################################################################*/

#ifndef __MMA8451_H
#define __MMA8451_H


typedef struct
{
    int16_t x;
    int16_t y;
    int16_t z;
    int8_t id;
}MMA845X;


typedef enum
{
  IDLE,  
  TRANSMIT,
  RECEIVE
}MMA845_STATE;


#define MMA845X_DIVIDER         0x04
#define MMA845X_BUFFER_SIZE     0x06
#define MMA845X_CFG_VALUE       0x01
#define MMA845X_DEVICE_ID       0x1D

void MMA845X_Init(void);
void MMA845X_Poll(void);




#endif
