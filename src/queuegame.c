/* File skipgame.c */
#include <stdio.h>
#include "queuegame.h"

/* File ADT*/
#include "adt/queue.h"

void queuegame (Queue *q, Queue list)
/* 
I.S.: Queue/antrian game terdefinisi, antrian mungkin kosong, antrian tidak mungkin penuh
F.S.: Program akan melakukan enqueue game ke-num;
      Jika num memiliki nilai yang lebih besar dari jumlah list game yang tersedia
      maka program tidak beroperasi dan menampilkan pesan error
*/
{
    if(isEmpty(*q))
    {
        printf("Belum ada game yang terdaftar pada antrian.");
    } else
    {
        printf("test\n");
        // displayQueue(*q); --> harus dimodif adtnya biar bisa ngeprint nomor/indeksnya
        // listgame();
        int num;
        scanf("Nomor Game yang mau ditambahkan ke antrian: %d", &num);
        if(num <= length(*q))
        {
            enqueue(q, list.buffer[num-1]);
            printf("Game berhasil ditambahkan kedalam daftar antrian");
        } else
        {
            printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.");
        }
    }

}