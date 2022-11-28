/* File creategame.h */
#include "../adt/Array/array.h"
#include "../adt/Set/set.h"
#include "../adt/Map/map.h"
#include "../SCOREBOARD/scoreboard.h"

#ifndef CREATEGAME_H
#define CREATEGAME_H

void creategame (Array *game, ArrayMap *scoreboard, ArraySet *list_name);
/* 
I.S.: Input nama game
F.S.: Program menambahkan nama game ke list game
*/

#endif