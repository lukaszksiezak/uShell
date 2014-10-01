/*
    mycd.c
*/

#include "mycd.h"

void mycd(command* C, char* initDir)
{
	if(C->argc == 1)	//there is no parameters passed
	{ 		
		chdir(initDir);
	}
	else 
	{
		if(chdir(C->argv[1])!=0)
			printf("Failed to open directory %s\n",C->argv[1]);
	}
}

