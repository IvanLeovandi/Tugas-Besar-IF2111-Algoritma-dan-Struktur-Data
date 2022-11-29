/* File queue.c */

#include "queuehangman.h"
#include <stdio.h>

/* *** Kreator *** */
void CreateQueueHangman(QueueHangman *q) {
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
    // KAMUS LOKAL
    // ALGORITMA
    q->idxHead = IDX_UNDEF;
    q->idxTail = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmptyHangman(QueueHangman q) {
/* Mengirim true jika q kosong: lihat definisi di atas */
    // KAMUS LOKAL
    // ALGORITMA
    return (q.idxHead == IDX_UNDEF && q.idxTail == IDX_UNDEF);
}

boolean isFullHangman(QueueHangman q) {
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
    // KAMUS LOKAL
    // ALGORITMA
    return (q.idxHead == 0 && q.idxTail == CAPACITY-1);
}

int lengthHangman(QueueHangman q) {
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
    // KAMUS LOKAL
    // ALGORITMA
    if (isEmptyHangman(q)) {
        return 0;
    } else {
        return (q.idxTail - q.idxHead + 1);
    }
}

/* *** Primitif Add/Delete *** */
void enqueueHangman(QueueHangman *q, ElTypeq val) {
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
    // KAMUS LOKAL
    // ALGORITMA
    if (isEmptyHangman(*q)) {
        q->idxHead = 0;
        q->idxTail = 0;
    } else {
        q->idxTail = q->idxTail + 1;
    }
    q->buffer[q->idxTail] = val;
}

void dequeueHangman(QueueHangman *q, ElTypeq *val) {
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */
    // KAMUS LOKAL
    // ALGORITMA
    *val = q->buffer[q->idxHead];
    if (q->idxHead == q->idxTail) {
        q->idxHead = IDX_UNDEF;
        q->idxTail = IDX_UNDEF;
    } else {
        int i;
        for(i = 0; i < lengthHangman(*q); i++)
        {
            q->buffer[i] = q->buffer[i+1];
        }
        q->idxTail--;
    }
}

/* *** Display Queue *** */
void displayQueueHangman(QueueHangman q) {
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
    // KAMUS LOKAL
    int i;
    // ALGORITMA
    if (isEmptyHangman(q)) {
        printf("Queue kosong\n");
    } else {
        for (i = q.idxHead; i < lengthHangman(q); i++) {
            printf("%d. %c\n", i+1, q.buffer[i]);
        }
        printf("\n");
    }
}

boolean SearchElmtQueueHangman(QueueHangman q, char str)
/* Sebuah fungsi yang mengembalikan tipe boolean apakah sebuah elemen ada pada queue atau tidak.*/
{
    if(isEmptyHangman(q))
    {
        return false;
    } else
    {
        int i = 0;
        while(i < lengthHangman(q) && q.buffer[i] != str)
        {
            i++;
        }
        if(i < lengthHangman(q))
        {
            return true;
        } else
        {
            return false;
        }
    }
}