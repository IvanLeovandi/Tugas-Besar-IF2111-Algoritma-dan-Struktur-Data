/* File playgame.h */
#include <stdio.h>
#include "../adt/Queue/queue.h"
#include "../LISTGAME/listgame.h"
#include "../RNG/rng.h"
#include "../DINERDASH/dinerdash.h"
#include "../GAMEBUATAN/game.h"
#include "../BONUSGAME/RPS.h"
#include "../TOWEROFHANOI/towerofhanoi.h"
#include "../SNAKEONMETEOR/snake.h"
#include "../GUESSNUMBER/guess_number.h"
#include "../adt/Set/set.h"
#include "../adt/Map/map.h"
#include "../SCOREBOARD\scoreboard.h

#ifndef PLAYGAME_H
#define PLAYGAME_H
void playgame(Queue *game, Array array_game, ArraySet *nama_pemain, ArrayMap *scoreboard_game);
/* 
I.S.: menerima input queue game 
F.S.: melakukan dequeue dan menyimpan hasil elemen yang baru dihapus di dalam name
*/

#endif