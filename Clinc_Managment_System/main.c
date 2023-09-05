/*
 * main.c
 *
 *  Created on: Aug 18, 2023
 *      Author: Pc
 */
#include "HeaderFiles/patient.h"
int main()
{
	while(1)
	{
		int option;
		printf("1- admin mode \n2- user mode\n3- Exit the program\n");
		printf("Enter option:");
		fflush(stdin);fflush(stdout);
		scanf("%d",&option);
		switch(option)
		{
		case 1:
			admin_mode();
			break;
		case 2:
			user_mode();
			break;
		case 3:
			exit(1);
		default:
			printf("wrong choice");
		}
	}

	return 0;
}
