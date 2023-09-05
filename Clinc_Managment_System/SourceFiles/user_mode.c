/*
 * user_mode.c
 *
 *  Created on: Aug 19, 2023
 *      Author: Pc
 */

#include "../HeaderFiles/patient.h"
#include "../HeaderFiles/slots.h"

extern patient *first;
extern slot slots[5];
void viewPatient()
{
	//need to select patient data i needed to view
	// temp to can traverse the patients
	patient *temp = first,*need;
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
	while(temp != NULL)
	{
		if(temp->ID == ID)
			need = temp;
		temp = temp->Next;
	}
	printf("Patient Record:\n");
	printf("Name: %s\n",need->name);
	printf("Age: %d\n",need->age);
	printf("gender: %c\n",need->gender);
}


void viewReservations()
{
	printf("Today's reservations:\n");
	for (int i = 0; i < 5; i++)
	{
		printf("Slot %d: ", i+1);
		if (slots[i].patientID == -1) // -1 means no reservation
		{
			printf("Available\n");
		}
		else
		{
			printf("Reserved by patient %d at %s\n", slots[i].patientID, slots[i].time);
		}
	}
}


void user_mode()
{
	while(1)
	{
		int choice;
		printf("\n1- View patient record"
				"\n2- View today’s reservations"
				"\n3- Exit the program\n");
		fflush(stdout);fflush(stdin);
		printf("\nEnter choice: ");
		fflush(stdout);fflush(stdin);
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			viewPatient();
			break;
		case 2:
			viewReservations();
			break;
		case 3:
			exit(1);
		default:
			printf("Wrong choice");
		}
	}
}

