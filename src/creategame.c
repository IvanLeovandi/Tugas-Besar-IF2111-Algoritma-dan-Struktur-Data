/* File creategame.c */
#include <stdio.h>
#include "creategame.h"

/* File ADT*/
#include "queue.h"

void creategame (Queue *game, char* name)
/* 
I.S.: Input nama game dan melakukan enqueue ke game
F.S.: Program menambahkan nama game ke list game
*/
{
    printf("Masukkan nama game yang akan ditambahkan: ");
    scanf("%s",name);
    enqueue(game, name);
    printf("Game berhasil ditambahkan");
}