/*
 * cancelReservation.c
 *
 *  Created on: Aug 19, 2023
 *      Author: Pc
 */

#include "../../HeaderFiles/patient.h"
#include "../../HeaderFiles/slots.h"
extern slot slots[5];
void cancelReservation()
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
	//find the index of the slot with given ID
	int index =-1;
	int i;
	for (i = 0; i < 5; ++i)
	{
		if(slots[i].patientID == ID)
		{
			index = i;
			break;
		}
	}

	if(index == -1)
	{
	    printf("The patient with ID %d "
	    		"does not have any reservation.\n", ID);
	    return;
	}
	if(slots[index].reserved == 0)
	{
	    printf("The slot %s is not reserved. Please enter a valid slot.\n", slots[index].time);
	    return;
	}
	  // Cancel the reservation and reset the patient ID
	  slots[index].reserved = 0;
	  slots[index].patientID = -1;

	  printf("The reservation for the patient with ID %d has been cancelled.\n", ID);
}
