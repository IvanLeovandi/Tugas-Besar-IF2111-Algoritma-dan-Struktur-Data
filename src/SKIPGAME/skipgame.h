// File skipgame.h
#include "../PLAYGAME/playgame.h"
#include "../adt/Array/array.h"

#ifndef SKIPGAME_H
#define SKIPGAME_H

void skipgame (Queue *q, Array array_game, ArraySet *list_name, ArrayMap *scoreboard, int n);
/* 
I.S.: Queue/antrian game terdefinisi, antrian mungkin kosong, antrian tidak mungkin penuh
F.S.: Program akan melakukan dequeue sebanyak n kali dari antrian game yang dimasukkan pada parameter
*/

#endif