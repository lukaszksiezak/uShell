/*
    myls.c
*/

#include "myls.h"

void myls(command* C, char* currentDir,char detailFlag)
{
	DIR *directory;
	struct dirent *dir;
	directory = opendir(currentDir);
   	struct stat stbuf;
	
	if (directory)
	{
		if(detailFlag==1)
			printf("NAME: User ID/Group ID/Size/Last mod. date/Type+Permissions");

		while ((dir = readdir(directory)) != NULL)
		{
			if(detailFlag==0)
				printf("%s\n", dir->d_name);
			else
			{		
				stat(dir->d_name, &stbuf);
				printDetails(dir->d_name, &stbuf);
			}
		}		
		closedir(directory);
	}
	else
		printf("Couldn't open directory: %s\n",currentDir);
}


void printDetails( char * name, struct stat * buffer)
{

	struct passwd *passent;		//structure which allows to obtain user name by ID
	passent = getpwuid(buffer -> st_uid);
	
	printf("%s: %d:%s\t%d\t%ld\t%s",name,buffer->st_uid,passent->pw_name, buffer->st_gid,buffer->st_size,
									ctime( &(buffer -> st_mtime)));

	printf( (S_ISDIR(buffer->st_mode)) ? "d" : "-"); //Simple parsing flags into symbols known from Linux terminal
    printf( (buffer->st_mode & S_IRUSR) ? "r" : "-");
    printf( (buffer->st_mode & S_IWUSR) ? "w" : "-");
    printf( (buffer->st_mode & S_IXUSR) ? "x" : "-");
    printf( (buffer->st_mode & S_IRGRP) ? "r" : "-");
    printf( (buffer->st_mode & S_IWGRP) ? "w" : "-");
    printf( (buffer->st_mode & S_IXGRP) ? "x" : "-");
    printf( (buffer->st_mode & S_IROTH) ? "r" : "-");
    printf( (buffer->st_mode & S_IWOTH) ? "w" : "-");
    printf( (buffer->st_mode & S_IXOTH) ? "x\n" : "-\n");

}

