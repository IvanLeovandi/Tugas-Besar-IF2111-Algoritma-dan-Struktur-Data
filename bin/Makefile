# makefile (template, will be updated soon)

CC = gcc
OBJ = main

# $(OBJ): test.o
# 	$(CC) test.o -o $(OBJ)

# test.o: test.c
# 	$(CC) -c test.c
$(OBJ):
	$(CC) ../src/main.c ../src/load.c  ../src/start.c ../src/listgame.c ../src/help.c ../src/adt/mesinkarakter.c ../src/adt/mesinkata.c ../src/adt/array.c ../src/adt/loader.c -o main
#include "main.h"
#include "adt/array.h"
#include "adt/mesinkarakter.h"
#include "adt/mesinkata.h"
#include "adt/queue.h"
#include "start.h"
#include "listgame.h"
#include "help.h"
exec:
	./main

clean:
	rm main *.o


# how to makefile with source file in different directory : mingw32-make -C ../src