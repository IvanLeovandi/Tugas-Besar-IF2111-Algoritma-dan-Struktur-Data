// File queue.h
#include <stdio.h>
#include "../adt/Queue/queue.h"

#ifndef QUEUEGAME_H
#define QUEUEGAME_H

void queuegame (Queue *q, Queue list);
/* 
I.S.: Queue/antrian game terdefinisi, antrian mungkin kosong, antrian tidak mungkin penuh
F.S.: Program akan melakukan enqueue game ke-num;
      Jika num memiliki nilai yang lebih besar dari jumlah list game yang tersedia
      maka program tidak beroperasi dan menampilkan pesan error
*/

#endif