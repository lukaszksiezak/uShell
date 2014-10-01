/*
    mycat.c
*/

#include "mycat.h"

void mycat(command* C)
{
	int fd;		//file descriptor
	long size;	
	char *fileStream;

	if ((fd = open((const char*)C->argv[1],O_RDONLY)) < 0)	//file in read-only mode, checking if file exists
	{
		printf("Failed to open the file!\n");
	}
	else
	{
		size = lseek(fd, 0, SEEK_END);	//reading size of the file
		lseek(fd, 0, SEEK_SET);	//moving pointer to the begining
 		fileStream = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);	//mmapping file
		printf("%s\n",fileStream);	//presenting output on tty (redirections were not required)
	}
}

