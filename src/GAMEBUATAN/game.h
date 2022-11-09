/* File game.h */
#include <stdio.h>
#include "../adt/Mesin/mesinkata.h"

#include "../RNG/random_number.h"

#ifndef GAME_H
#define GAME_H

void game_buatan(char *game);
/* 
I.S.: Pemain membuat game buatan dengan menggunakan command CREATE GAME
F.S.: Program langsung menghentikan game dan mengeluarkan skor akhir berupa random integer
*/

#endif