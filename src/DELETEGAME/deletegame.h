/* File game.h */
#include "../adt/Array/array.h"
#include "../adt/Mesin/mesinkata.h"
#include "../adt/Queue/queue.h"
#include "../adt/Set/set.h"
#include "../adt/Map/map.h"

#ifndef DELETEGAME_H
#define DELETEGAME_H

void deletegame(Array* game, Queue queue_game, ArraySet *list_name, ArrayMap *scoreboard);
/* 
I.S.: input list game yang akan dihapus dan nomor dari list tersebut
F.S.: Program menghapus nama game dengan nomor padalist tersebut
*/


#endif