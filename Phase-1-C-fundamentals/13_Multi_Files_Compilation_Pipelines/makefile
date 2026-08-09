program: main.o utils.o
	gcc main.o utils.o -o program

main.o: main.c utils.h 
	gcc -c main.c -o main.o

utils.o: utils.c utils.h
	gcc -c utils.c -o utils.o

clean: 
	del /Q *.o program.exe