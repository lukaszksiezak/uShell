/*
    mycat.h
*/

#ifndef _MYCAT_H_
#define _MYCAT_H_

#include <sys/param.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
 
#include "parser.h"

void mycat(command* C);

#endif
