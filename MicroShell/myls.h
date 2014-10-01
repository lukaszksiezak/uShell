/*
    myls.h
*/

#ifndef _MYLS_H_
#define _MYLS_H_

#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include <pwd.h>

#include "parser.h"

void myls(command* C,char* currentDir,char detailFlag);
void printDetails(char* name, struct stat* buffer);
#endif

