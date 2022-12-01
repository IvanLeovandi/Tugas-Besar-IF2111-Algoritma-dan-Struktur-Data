/* File guess_number.h */
#include "../adt/Tree/tree.h"
#include "../RNG/random_number.h"
#include "../adt/Mesin/mesinkata.h"
#include "../clear.h"

#ifndef GUESS_NUMBER_H
#define GUESS_NUMBER_H

void guess_number(int *score_game);
/*
Game tebak angka dengan menggunakan konsep binary tree.
Konsep binary tree: 
- Nilai LEFT(tree) selalu lebih kecil dari nilai ROOT(tree).
- Nilai RIGHT(tree) selalu lebih besar dari nilai ROOT(tree).
*/

#endif