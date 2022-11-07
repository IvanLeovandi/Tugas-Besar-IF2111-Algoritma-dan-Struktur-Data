/* File playgame.c */
#include <stdio.h>
#include "playgame.h"

/* File ADT*/
#include "../adt/Queue/queue.h"

void playgame(Queue* game, char* name)
/* 
I.S.: menerima input queue game 
F.S.: melakukan dequeue dan menyimpan hasil elemen yang baru dihapus di dalam name
*/
{
    printf("Berikut adalah daftar Game-mu\n");
    int i = 0;
    int sum = 0;
    while (sum < length(*game)){
        if (i + IDX_HEAD(*game) == CAPACITY){
            i = 0;
        }
        printf("%d. %s\n",i + 1,game->buffer[IDX_HEAD(*game) + i]);
    }
    dequeue(game,name);

}