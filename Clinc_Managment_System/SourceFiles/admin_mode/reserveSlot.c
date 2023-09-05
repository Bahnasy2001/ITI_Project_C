/*
 * reserveSlot.c
 *
 *  Created on: Aug 19, 2023
 *      Author: Pc
 */

#include "../../HeaderFiles/patient.h"
#include "../../HeaderFiles/slots.h"
extern slot slots[5];
extern patient *first;
// Define a function to reserve a slot for a patient by ID and time
void reserve()
{
	int ID;
	printf("\nEnter ID: ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&ID);
	if(!checkID(ID))
	{
		printf("The ID %d does not exist."
				" Please enter a valid ID.\n", ID);
		return;
	}
	char time[20];
	printf("\nEnter time: ");
	fflush(stdout);fflush(stdin);
	gets(time);

	int index =-1; //to save the index for reserved slot
	int i;
	for (i = 0; i < 5; ++i)
	{
		if(strcmpi((slots[i].time),time)==0)
		{
			index = i;
			break;
		}
	}
	// Check if the index is valid and the slot is not reserved
	if (index == -1) {
		printf("The time %s is not valid. Please enter a valid time.\n", time);
		return;
	}

	if(slots[index].reserved == 1)
	{
	    printf("The time %s is already reserved."
	    		" Please choose another time.\n", time);
	    return;
	}
	slots[index].reserved=1;
	slots[index].patientID = ID;

	  printf("The patient with ID %d "
			  "has reserved the slot %s.\n", ID, time);
}
