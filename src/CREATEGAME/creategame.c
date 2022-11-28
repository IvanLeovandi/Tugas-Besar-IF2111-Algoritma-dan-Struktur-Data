/* File creategame.c */
#include <stdio.h>
#include "creategame.h"
#include "../clear.h"

/* File ADT*/
#include "../adt/Mesin/mesinkata.h"

void creategame (Array *game)
/* 
I.S.: Input nama game dan melakukan enqueue ke game
F.S.: Program menambahkan nama game ke list game
*/
{
    printf("Masukkan nama game yang akan ditambahkan: ");
    char* name = Input();
    ClearScreen();
    if(IsElmt(*game, name))
    {
        printf("Game sudah ditambahkan, silahkan masukan nama game yang lain\n");
    } else
    {
        SetEl(game, NbElmt(*game), name);
        SetNeff(game, NbElmt(*game) +1);
        printf("Game berhasil ditambahkan\n");
    }
}