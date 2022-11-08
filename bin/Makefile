# makefile (template, will be updated soon)

CC = gcc
OBJ = main

# $(OBJ): test.o
# 	$(CC) test.o -o $(OBJ)

# test.o: test.c
# 	$(CC) -c test.c
$(OBJ):
	$(CC) ../src/adt/Mesin/mesinkarakter.c ../src/adt/Mesin/mesinkata.c ../src/adt/Array/array.c ../src/adt/Mesin/loader.c ../src/LOAD/load.c  ../src/STARTGAME/start.c ../src/LISTGAME/listgame.c ../src/HELP/help.c ../src/COMMANDLAIN/commandlain.c ../src/main.c -o main ../src/CREATEGAME/creategame.c ../src/DELETEGAME/deletegame.c ../src/QUEUEGAME/queuegame.c ../src/QUITGAME/quitgame.c ../src/SKIPGAME/skipgame.c
#../src/GAMEBUATAN/game.c ../src/PLAYGAME/playgame.c ../src/RNG/random_number.c ../src/RNG/rng.c ../src/SAVE/save.c
exec:
	./main

clean:
	rm main *.o


# how to makefile with source file in different directory : mingw32-make -C ../src