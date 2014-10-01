all: uShell

mycat: mycat.o 
	gcc -g -Wall -o mycat mycat.o

mycd: mycd.o  
	gcc -g -Wall -o mycd mycd.o

mycp: mycp.o  
	gcc -g -Wall -o mycp mycp.o

myls: myls.o  
	gcc -g -Wall -o myls myls.o

mypwd: mypwd.o  
	gcc -g -Wall -o mypwd mypwd.o

myrm: myrm.o  
	gcc -g -Wall -o myrm myrm.o

parser: parser.o  
	gcc -g -Wall -o parser parser.o

main: main.o parser.o myrm.o mypwd.o myls.o mycp.o mycd.o mycat.o 
	gcc -g -Wall -o main main.o parser.o myrm.o mypwd.o myls.o mycp.o mycd.o mycat.o 

mycat.o: mycat.c mycat.h parser.h 
	gcc -g -Wall -c -o mycat.o mycat.c

mycd.o: mycd.c mycd.h parser.h 
	gcc -g -Wall -c -o mycd.o mycd.c

mycp.o: mycp.c mycp.h parser.h 
	gcc -g -Wall -c -o mycp.o mycp.c

myls.o: myls.c myls.h parser.h 
	gcc -g -Wall -c -o myls.o myls.c

mypwd.o: mypwd.c mypwd.h
	gcc -g -Wall -c -o mypwd.o mypwd.c

myrm.o: myrm.c myrm.h parser.h 
	gcc -g -Wall -c -o myrm.o myrm.c

main.o: main.c myrm.h mypwd.h myls.h mycp.h mycd.h mycat.h parser.h 
	gcc -g -Wall -c -o main.o main.c
 
parser.o: parser.c parser.h 
	gcc -g -Wall -c -o parser.o parser.c

uShell: main.o parser.o myrm.o mypwd.o myls.o mycp.o mycd.o mycat.o
	gcc -g -Wall -o uShell main.o parser.o myrm.o mypwd.o myls.o mycp.o mycd.o mycat.o

clean:
	rm -f main.o myls.o mycat.o mycd.o mycp.o mypwd.o myrm.o parser.o
	rm -f uShell
	$(RM) *~ 
