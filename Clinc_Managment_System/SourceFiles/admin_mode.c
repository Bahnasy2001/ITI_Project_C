/*
 * admin_mode.c
 *
 *  Created on: Aug 18, 2023
 *      Author: Pc
 */
#include "../HeaderFiles/patient.h"
#include "../HeaderFiles/slots.h"

// Define a global pointer to the head of the list
patient *first = NULL;

int checkID(int ID)
{
	patient *temp = first;
	while (temp != NULL) {
		if (temp->ID == ID) {
			return 1; // ID found
		}
		temp = temp->Next;
	}
	return 0; // ID not found
}
void admin_mode()
{
	int password =1234,pass;
	int trails = 3;
	while(trails >0)
	{
		printf("Enter the password: ");
		fflush(stdout);fflush(stdin);
		scanf("%d",&pass);
		if(pass == password)
		{
			break;
		}
		else
		{

			if(trails!=0)
			{
				if(trails>1){
					printf("\nplease Enter correct password\n");
				}
				trails--;
			}
			else
				exit(1);
		}
	}
	while(1)
	{
		int choice;
		printf("\n1- Add new patient record\n"
				"\n2- Edit patient record\n"
				"\n3- Reserve a slot with the doctor\n"
				"\n4- Cancel reservation\n"
				"\n5- Exit the program\n");
		fflush(stdout);fflush(stdin);
		printf("\nEnter choice: ");
		fflush(stdout);fflush(stdin);
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			addPatient();
			break;
		case 2:
			editPatient();
			break;
		case 3:
			initSlots();
			displaySlots();
			reserve();
			break;
		case 4:
			cancelReservation();
			break;
		case 5:
			main();
			break;
		default:
			printf("Wrong choice");
		}
	}
}


