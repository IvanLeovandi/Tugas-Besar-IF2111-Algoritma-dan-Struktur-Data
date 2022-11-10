/* File playgame.h */
#include <stdio.h>
#include "../adt/Queue/queue.h"
#include "../LISTGAME/listgame.h"
#include "../RNG/rng.h"
#include "../DINERDASH/dinerdash.h"
#include "../GAMEBUATAN/game.h"
#include "../BONUSGAME/RPS.h"

#ifndef PLAYGAME_H
#define PLAYGAME_H

void playgame(Queue *game);
/* 
I.S.: menerima input queue game 
F.S.: melakukan dequeue dan menyimpan hasil elemen yang baru dihapus di dalam name
*/

#endif