/*
    mycp.c
*/

#include "mycp.h"

void mycp(command* C)
{
	int source, destination;
	long size;
	char* buf;
	if ( (((source = open((const char*)C->argv[1],O_RDONLY)) < 0) )&
					((destination = open((const char*)C->argv[2],O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH))<0 )) //source read-only
	{																										//destination write (create flag)
		printf("Failed to open the file!\n");
	}
	else
	{
		size = lseek(source, 0, SEEK_END); 	//read size
		buf = malloc(sizeof *buf * size);	//allocate space for file to be read (to avoid reading file one by one letter)
		lseek(source, 0, SEEK_SET);			//move file pointer to beginning
		read(source,buf,size);				//read file (the whole file)
		write(destination,buf,size);		//write whole buffer to destination file
		close(source);						//close opened files
		close(destination);
		free(buf);							//free allocated space
	}		
}

