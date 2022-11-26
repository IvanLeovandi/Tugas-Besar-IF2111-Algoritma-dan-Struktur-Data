/* File guess_number.h */
#include <stdio.h>
#include "../adt/Tree/tree.h"
#include "../RNG/random_number.h"
#include "../adt/Mesin/mesinkata.h"

#ifndef GUESS_NUMBER_H
#define GUESS_NUMBER_H

int guess_number();
/*
Game tebak angka dengan menggunakan konsep binary tree.
Konsep binary tree: 
- Nilai LEFT(tree) selalu lebih kecil dari nilai ROOT(tree).
- Nilai RIGHT(tree) selalu lebih besar dari nilai ROOT(tree).
*/

#endif