/*
    mypwd.c
*/

#include "mypwd.h"

char* mypwd()
{
 	if (getcwd(buff, sizeof(buff)) == NULL)
	{
		perror("getcwd() error");
		return NULL;
	}
   	else
		return buff;
}

