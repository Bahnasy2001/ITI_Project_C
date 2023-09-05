/*
 * slots.h
 *
 *  Created on: Aug 19, 2023
 *      Author: Pc
 */

#ifndef HEADERFILES_SLOTS_H_
#define HEADERFILES_SLOTS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct slot slot;
struct slot
{
	char time[20];
	int reserved;
	int patientID;
};

void initSlots();
void displaySlots();
#endif /* HEADERFILES_SLOTS_H_ */
