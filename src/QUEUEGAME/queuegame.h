// File queue.h
#include <stdio.h>
#include "../adt/Queue/queue.h"
#include "../adt/Array/array.h"

#ifndef QUEUEGAME_H
#define QUEUEGAME_H

void queuegame (Queue *q, Array array_game);
/* 
I.S.: Queue/antrian game terdefinisi, antrian mungkin kosong, antrian tidak mungkin penuh
F.S.: Program akan melakukan enqueue game ke-num;
      Jika num memiliki nilai diluar dari list game yang tersedia
      maka program tidak beroperasi dan menampilkan pesan error
*/

#endif