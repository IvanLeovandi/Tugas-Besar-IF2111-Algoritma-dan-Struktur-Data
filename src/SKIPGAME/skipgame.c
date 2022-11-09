/* File skipgame.c */
#include <stdio.h>
#include "skipgame.h"


void skipgame (Queue *q, Array array_game, int n)
/* 
I.S.: Queue/antrian game terdefinisi, antrian mungkin kosong, antrian tidak mungkin penuh
F.S.: Program akan melakukan dequeue sebanyak n kali dari antrian game yang dimasukkan pada parameter
*/
{
    if(isEmpty(*q))
    {
        printf("Tidak ada permainan lagi dalam daftar antrian kamu.\n");
    } else if(n > CAPACITY)
    {
        printf("Masukan tidak valid.\n");
    } else
    {
        ElType val;
        int i;
        for(i = 0; i < n; i++)
        {
            dequeue(q, &val);
        }
        playgame(q);
    }
}