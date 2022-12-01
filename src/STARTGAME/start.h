//File start.h
#include <stdio.h>
#include "../adt/Array/array.h"
#include "../adt/Mesin/mesinkata.h"
#include "../boolean.h"
#include "../adt/Stack/stackhistory.h"
#include "../adt/map/map.h"
#include "../adt/Set/set.h"
#include "../LOAD/load.h"

#ifndef START_H
#define START_H

void STARTGAME(Array *array_game, StackHis *history, ArraySet *list_name, ArrayMap *scoreboard, boolean isStart);
/*
I.S. ArrayGame a terdefinisi, ArrayGame a kosong;
F.S. ArrayGame a terisi dengan game yang berada pada file config.txt
*/

#endif