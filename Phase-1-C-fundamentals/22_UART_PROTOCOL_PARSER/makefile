program: main.o Ring_Buffer.o
	gcc -Wall -Wextra main.o Ring_Buffer.o -o program


main.o: main.c Ring_Buffer.h
	gcc -c main.c -o main.o


Ring_Buffer.o: Ring_Buffer.c Ring_Buffer.h
	gcc -c Ring_Buffer.c -o Ring_Buffer.o


clean:
	del /Q *.o program.exe