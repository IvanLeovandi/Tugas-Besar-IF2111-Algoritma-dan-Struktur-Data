// File skipgame.h
#include <stdio.h>
#include "../adt/Queue/queue.h"
#include "../adt/Array/array.h"

#ifndef SKIPGAME_H
#define SKIPGAME_H

void skipgame (Queue *q, Array array_game, int n);
/* 
I.S.: Queue/antrian game terdefinisi, antrian mungkin kosong, antrian tidak mungkin penuh
F.S.: Program akan melakukan dequeue sebanyak n kali dari antrian game yang dimasukkan pada parameter
*/

#endif