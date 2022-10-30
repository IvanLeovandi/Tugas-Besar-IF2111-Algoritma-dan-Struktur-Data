# makefile (template, will be updated soon)

CC = gcc
OBJ = main

$(OBJ): test.o
	$(CC) test.o -o $(OBJ)

test.o: test.c
	$(CC) -c test.c

exec:
	./main

clean:
	rm main *.o


# how to makefile with source file in different directory : mingw32-make -C ../src