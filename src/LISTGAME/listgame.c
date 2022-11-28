#include <stdio.h>
#include "listgame.h"

void listgame(Array array_game)
/*
I.S : Array array_game terdefinisi
F.S : Tercetak list game yang tersedi
*/
{
    int i;
    printf("Berikut adalah daftar game yang tersedia\n");
    for (i=0;i<NbElmt(array_game);i++)
    {
        printf("%d. %s\n",i+1,array_game.TI[i]);
    }
}