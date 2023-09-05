/*
 * slots.c
 *
 *  Created on: Aug 19, 2023
 *      Author: Pc
 */
#include "../HeaderFiles/slots.h"
#include "../HeaderFiles/patient.h"
slot slots[5];
extern patient *first;
//Define function to initialize slots
void initSlots()
{
	char times[5][20] = {"2pm-2:30pm",
			"2:30pm-3pm",
			"3pm-3:30pm",
			"4pm-4:30pm",
			"4:30pm-5pm"};

	//initialize each slot with the time and default values
	int i;
	for (i = 0; i < 5; ++i)
	{
		strcpy(slots[i].time,times[i]);
		// 0 means not reserved, 1 means reserved
		slots[i].reserved = 0;
		// -1 means no patient assigned
		slots[i].patientID = -1;
	}
}
// Define a function to display the available slots
void displaySlots()
{
	printf("the available slots are:\n");
	int i;
	for (i = 0; i < 5; ++i)
	{
		if(slots[i].reserved == 0)
		{
			printf("%s\n",slots[i].time);
		}
	}
}
