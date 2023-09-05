/*
 * addPatient.c
 *
 *  Created on: Aug 19, 2023
 *      Author: Pc
 */
#include "../../HeaderFiles/patient.h"
extern patient *first;


void addPatient()
{
	char name[20];
	int age;
	char gender;
	int ID;
	int flag = -1;
	patient*newPatient;
	newPatient = (patient*)malloc(sizeof(patient));
	newPatient->Next = NULL;
	//Enter name for new patient
	printf("\nEnter Name: ");
	fflush(stdout);fflush(stdin);
	gets(name);
	strcpy(newPatient->name, name);
	//Enter age for new patient
	printf("\nEnter age: ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&age);
	newPatient->age = age;
	//Enter gender for new patient
	printf("Choose m for male Or f for female\n");
	while(flag == -1)
	{
		printf("\nEnter gender: ");
		fflush(stdout);fflush(stdin);
		scanf("%c",&gender);
		if(gender == 'm' || gender == 'f')
		{
			flag = 1;
			break;
		}
		else
		{
			printf("Wrong choice");
		}
	}
	newPatient->gender =gender;
	// Check if the ID is unique
	printf("\nEnter ID: ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&ID);
	if (checkID(ID))
	{
		printf("The ID %d already exists. Please enter"
				" a different ID.\n", ID);
		return;
	}
	else
	{
		newPatient->ID = ID;
	}

	// Insert the new node at the beginning of the list
	newPatient ->Next = first;
	first = newPatient;
}
