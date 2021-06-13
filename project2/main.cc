/*
*Filename 	main
*Date		2/4/21
*Author		Brianna Murray
*Course		CS 3377.0W6
*Version	1.0
*Copyright	2021, All Rights Reserved
*
*Description
*
*	Main file that calls function and displays argc
*/

#include <stdio.h>
#include "header.h"

void function();

int main(int argc, char *argv[])
{
	if(argc == 1) {printf("No arguments passes\n");}
	else
	{
		printf("Arguments:\n");
		for(int i = 1; i < argc; i++){
			printf("%d. %s\n", i, argv[i]);
		}
	}
	
	printf("argc: %d\n", argc);
	function();
	printf("BACK INSIDE MAIN\n\n");
	return 0;													
}
