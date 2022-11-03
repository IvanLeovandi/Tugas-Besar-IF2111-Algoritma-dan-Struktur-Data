/* File playgame.c */
#include <stdio.h>
#include "playgame.h"

/* File ADT*/
#include "queue.h"

void playgame(Queue* game, char* name);
/* 
I.S.: menerima input queue game 
F.S.: melakukan dequeue dan menyimpan hasil elemen yang baru dihapus di dalam name
*/
{
    printf("Berikut adalah daftar Game-mu\n");
    int i;
    for(i = 0; i < game->Neff; i++){
        printf("%d. %s\n",i+1,game->TI[i]);
    }
    dequeue(game,name);

}