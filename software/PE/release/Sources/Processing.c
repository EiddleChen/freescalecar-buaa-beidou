/*
 * Processing.c
 *
 *  Created on: May 26, 2013
 *      Author: chenty
 */
#include "stdio.h"
#include "PE_LDD.h"
void Processing_Interact(int16_t Wave0, int16_t Wave1, int16_t Wave2, int16_t Wave3 ){
	//printf("%c%c\t%c%c\t%c%c\t%c%c\t", Wave0 >> 8, Wave0 & 255, Wave1 >> 8, Wave1 & 255, Wave2 >> 8, Wave2 & 255, Wave3 >> 8, Wave3 & 255);
	printf("%c%c\t",Wave0 >> 8, Wave0 & 255);
	//printf("A");
}
