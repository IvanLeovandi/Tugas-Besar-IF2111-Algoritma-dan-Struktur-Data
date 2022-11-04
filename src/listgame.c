#include "listgame.h"

void listgame(Array array_game)
/*
I.S : Array array_game terdefinisi
F.S : Tercetak list game yang tersedi
*/
{
    int i;
    for (i=0;i<NbElmt(array_game);i++)
    {
        printf("%d %s\n",i+1,array_game.TI[i]);
    }
}