/*
    myrm.c
*/

#include "myrm.h"

void myrm(command* C)
{
	int i;
	
	for(i=1;i<C->argc;i++)
	{
		if(unlink(C->argv[i])<0)		//simple call unlink of function. Return value less than zero means error.
			printf("Failed to unlink file: %s\n",C->argv[i]);
	}
}

