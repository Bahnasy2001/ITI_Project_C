/*
 * patient.h
 *
 *  Created on: Aug 18, 2023
 *      Author: Pc
 */

#ifndef HEADERFILES_PATIENT_H_
#define HEADERFILES_PATIENT_H_
//Patients system in linked list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define NULL ((void*)0)
typedef struct Patient_record patient;
struct Patient_record
{
	char name[20];
	int age;
	char gender;
	int ID;
	patient *Next;
};

int checkID(int ID);

void addPatient();

void editPatient();

void reserve();

void cancelReservation();

void admin_mode();
//=============================================
void viewReservations();

void viewPatient();

void user_mode();
#endif /* HEADERFILES_PATIENT_H_ */
