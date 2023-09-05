/*
 * editPatient.c
 *
 *  Created on: Aug 19, 2023
 *      Author: Pc
 */
#include "../../HeaderFiles/patient.h"
extern patient *first;
void editPatient()
{
	patient *temp = first;
	int ID;
	printf("\nEnter ID: ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&ID);
	// Find the node with the given ID
	while(temp != NULL && temp->ID !=ID)
	{
		temp = temp->Next;
	}
	// Check if the node exists
	  if (temp == NULL) {
	    printf("The ID %d does not exist. Please enter a valid ID.\n", ID);
	    return;
	  }
	  // Ask the user for the new information
		char name[20];
		int age;
		char gender;
		printf("\nEnter Name: ");
		fflush(stdout);fflush(stdin);
		gets(name);
		printf("\nEnter age: ");
		fflush(stdout);fflush(stdin);
		scanf("%d",&age);
		printf("\nEnter gender: ");
		fflush(stdout);fflush(stdin);
		scanf("%c",&gender);
		strcpy(temp->name,name);
		temp->age = age;
		temp->gender = gender;
		printf("The patient information with ID %d "
				"has been updated.\n", ID);
}
