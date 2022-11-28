#include "../boolean.h"
#include "../adt/Array/array.h"
#include "../adt/Mesin/mesinkarakter.h"
#include "../adt/Mesin/mesinkata.h"
#include "../adt/Mesin/loader.h"
#include "../adt/Stack/stackhistory.h"
#include "../adt/map/map.h"
#include "../adt/Set/set.h"
#include "../SCOREBOARD/scoreboard.h"


#ifndef LOAD_H
#define LOAD_H

void load(Array *array_game, StackHis *history, ArraySet *list_name, ArrayMap *scoreboard, char *filename);
/* Membaca isi file "filename" dan memasukkannya ke dalam array_game */

#endif