//File start.h
#include <stdio.h>
#include "../adt/Array/array.h"
#include "../adt/Mesin/mesinkarakter.h"
#include "../adt/Mesin/mesinkata.h"
#include "../boolean.h"
#include "../LOAD/load.h"

#ifndef START_H
#define START_H

void STARTGAME(Array *array_game);
/*
I.S. ArrayGame a terdefinisi, ArrayGame a kosong;
F.S. ArrayGame a terisi dengan game yang berada pada file config.txt
*/

#endif