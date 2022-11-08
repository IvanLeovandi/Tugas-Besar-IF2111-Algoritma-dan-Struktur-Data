/* File creategame.c */
#include <stdio.h>
#include "creategame.h"

/* File ADT*/
#include "../adt/Array/array.h"
#include "../adt/Mesin/mesinkata.h"

void creategame (Array *game)
/* 
I.S.: Input nama game dan melakukan enqueue ke game
F.S.: Program menambahkan nama game ke list game
*/
{
    printf("Masukkan nama game yang akan ditambahkan: ");
    char* name = Input();
    SetEl(game, GetLastIdx(*game) + 1, name);
    printf("Game berhasil ditambahkan");
}