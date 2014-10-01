/*
    main.c
	
	Based on provided file example.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "parser.h"
#include "mypwd.h"
#include "myls.h"
#include "mycd.h"
#include "mycat.h"
#include "mycp.h"
#include "myrm.h"

void recognize_command (command * C, char* initialDir); //function responsible for recognition of given command
char* currentDir();	//function which returns current path 
void mymkdir(command * C);	
void myrmdir(command * C);

int main ()
{
    command C;
    int r;
	char initialDir[256];	//buffer for initial directory
	
	strcpy(initialDir,currentDir());	//saving initial directory in initialDir array

    printf ("Type commands (press Ctrl-D to finish)\n");

    do 
    {
        init_command (&C);
        printf ("$ %s>",currentDir());
        r = read_command (&C, stdin);

        if (r < 0)
            fprintf (stderr, "\nError %d: %s\n",
                             -r, err_messages[-r]);
        else
		{
			if(C.argc!=0)	//check if user typed anything
			{
				if(strcmp(C.raw_command,"exit")==0)	 //user typed 'exit' -> quit
					return 0;
				else     
					recognize_command (&C, initialDir);	//function responsible for recognizing commands
			}
		}
        free_command (&C);
    }
    while (r==0);

    return 0;
}

void recognize_command (command * C, char* initialDir)
{
	if(strcmp(C->argv[0],"mypwd")==0)
	{	
		printf("\t%s\n",mypwd());
	}		 	 

	else if(strcmp(C->argv[0],"myls")==0)
	{	
		if(C->argc==1)	//there was no parameter to 'myls' call
		{
			myls(C,currentDir(),0);
		}
		if(C->argc==2)	//there was one parameter 
		{
			if(strcmp(C->argv[1],"-l")==0)	//if it was '-l' parameter set detailFlag on
				myls(C,currentDir(),1);
			else
				myls(C,C->argv[1],0);
		}
		if(C->argc==3)
		{
			if(strcmp(C->argv[2],"-l")==0)	//if the second param is 'l'
				myls(C,C->argv[1],1);
			else
				printf("Unknown parameter: %s\n",C->argv[2]);
		}
	}

	else if(strcmp(C->argv[0],"mymkdir")==0)
	{	
		mymkdir(C);		
	}
		 
	else if(strcmp(C->argv[0],"myrmdir")==0)	//almost the same as 'mymkdir'
	{	
		myrmdir(C);
	}
		 
	else if(strcmp(C->argv[0],"mycd")==0) 
	{
		mycd(C,initialDir);
	}
		
	else if(strcmp(C->argv[0],"mycat")==0)
	{
		mycat(C);
	}
		  
	else if(strcmp(C->argv[0],"mycp")==0)
	{
		if(C->argc!=3)
			printf("Not enough parameters\n");
		else
			mycp(C);
	}
		
	else if(strcmp(C->argv[0],"myrm")==0)
	{
		if(C->argc<2)
			printf("Not enough parameters\n");
		else
			myrm(C);
	}
	else
	{
		printf("Command not recognized\n");
	}
		
}//gcc -Wall main.c parser.c mypwd.c myls.c mycd.c mycat.c mycp.c -o mshell


char* currentDir()
{
	return mypwd();
}

void mymkdir(command * C)
{
	char buff[256] = {'\0'};
	int i,j;	//loops' iterators

	for(i=1;i<C->argc;i++)	//create as many directories as was given in parameters
	{
		for(j=0;j<256;j++)	//making sure that buff is empty
			buff[j] = '\0';

		strcat(buff,currentDir());	// Preparing dir path 
		strcat(buff,"/");	
		strcat(buff, C->argv[i]);
 
		if(mkdir(buff,0777)!=0)	//creation of dir with standard privilages
			printf("Failed to create new directory\n");
	}	
}

void myrmdir(command * C)
{
	int i,j; 
	char buff[256] = {'\0'};

	for(i=1;i<C->argc;i++) 
	{
		for(j=0;j<256;j++)	
			buff[j] = '\0';

		strcat(buff,currentDir());	  
		strcat(buff,"/");	
		strcat(buff, C->argv[i]);

		if(rmdir(buff)!=0)	
			printf("Failed to delete directory: %s \n",C->argv[i]);
	}
}

