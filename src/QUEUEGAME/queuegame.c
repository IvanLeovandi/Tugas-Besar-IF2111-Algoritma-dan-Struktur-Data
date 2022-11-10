/* File skipgame.c */
#include <stdio.h>
#include "queuegame.h"
#include "../LISTGAME/listgame.h"

/* File ADT*/
#include "../adt/Queue/queue.h"
#include "../adt/Array/array.h"
#include "../adt/Mesin/mesinkata.h"

void queuegame (Queue *q, Array array_game)
/* 
I.S.: Queue/antrian game terdefinisi, antrian mungkin kosong, antrian tidak mungkin penuh
F.S.: Program akan melakukan enqueue game ke-num;
      Jika num memiliki nilai yang lebih besar dari jumlah list game yang tersedia
      maka program tidak beroperasi dan menampilkan pesan error
*/
{
    if(isEmpty(*q))
    {
        printf("Belum ada game yang terdaftar pada antrian.\n");
    } else
    {
        displayQueue(*q);
    }
    listgame(array_game);
    printf("\nNomor Game yang mau ditambahkan ke antrian: ");
    char *strnum = Input();
    int num = StrToInt(strnum);
    if(num <= NbElmt(array_game) && num > 0)
    {
        enqueue(q, GetElmt(array_game, num-1));
        printf("Game berhasil ditambahkan kedalam daftar antrian");
    } else
    {
        printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.");
    }

}