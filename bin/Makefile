main:
	gcc ../src/adt/Array/array.c ../src/adt/Queue/queue.c ../src/adt/Mesin/mesinkarakter.c ../src/adt/Mesin/mesinkata.c ../src/adt/Mesin/loader.c ../src/adt/Array/array_diner.c ../src/adt/Queue/queue_diner.c ../src/adt/Stack/stack.c ../src/adt/Stack/stackhistory.c ../src/adt/List/linkedlist.c ../src/adt/Tree/tree.c ../src/adt/Set/set.c ../src/adt/map/map.c ../src/LOAD/load.c  ../src/STARTGAME/start.c ../src/LISTGAME/listgame.c ../src/SCOREBOARD/scoreboard.c ../src/HELP/help.c ../src/COMMANDLAIN/commandlain.c ../src/main.c -o main ../src/CREATEGAME/creategame.c ../src/DELETEGAME/deletegame.c ../src/QUEUEGAME/queuegame.c ../src/QUITGAME/quitgame.c ../src/SKIPGAME/skipgame.c ../src/GAMEBUATAN/game.c ../src/PLAYGAME/playgame.c ../src/RNG/random_number.c ../src/RNG/rng.c ../src/DINERDASH/dinerdash.c ../src/RPS/RPS.c ../src/SAVE/save.c ../src/TOWEROFHANOI/towerofhanoi.c ../src/clear.c ../src/SNAKEONMETEOR/snake.c ../src/GUESSNUMBER/guess_number.c -lm

mesintest:
	gcc -o mesintest ../src/adt/Mesin/driver_mesin.c  ../src/adt/Mesin/mesinkata.c ../src/adt/Mesin/mesinkarakter.c ../src/adt/Mesin/loader.c

arraytest:
	gcc -o arraytest ../src/adt/Array/driver_array.c ../src/adt/Array/array.c ../src/adt/Mesin/mesinkata.c ../src/adt/Mesin/mesinkarakter.c

arraydiner:
	gcc -o arraydiner ../src/adt/Array/driver_array_diner.c ../src/adt/Array/array_diner.c

stacktest:
	gcc -o stacktest ../src/adt/Stack/driver_stack.c ../src/adt/Stack/stack.c

treetest:
	gcc -o treetest ../src/adt/Tree/driver_tree.c ../src/adt/Tree/tree.c

exec:
	./main

clean:
	rm main *.o