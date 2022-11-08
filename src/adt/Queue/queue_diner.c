/* File queue_diner.c */

#include "queue_diner.h"
#include <stdio.h>

/* *** Kreator *** */
void CreateQueue(QueueDiner *q) {
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
boolean isEmpty(QueueDiner q) {
/* Mengirim true jika q kosong: lihat definisi di atas */
    // KAMUS LOKAL
    // ALGORITMA
    return (q.idxHead == IDX_UNDEF && q.idxTail == IDX_UNDEF);
}

boolean isFull(QueueDiner q) {
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
    // KAMUS LOKAL
    // ALGORITMA
    return (q.idxHead == 0 && q.idxTail == CAPACITY-1);
}

int length(QueueDiner q) {
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
    // KAMUS LOKAL
    // ALGORITMA
    if (isEmpty(q)) {
        return 0;
    } else if (q.idxTail >= q.idxHead) {
        return (q.idxTail - q.idxHead + 1);
    } else {
        return (CAPACITY - q.idxHead + q.idxTail + 1);
    }
}

/* *** Primitif Add/Delete *** */
void enqueue4(QueueDiner *q, ElType id, ElType durasi, ElType ketahanan, ElType harga) {
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
    // KAMUS LOKAL
    // ALGORITMA
    if (isEmpty(*q)) {
        q->idxHead = 0;
        q->idxTail = 0;
    } else {
        q->idxTail = (q->idxTail + 1) % CAPACITY;
    }
    
    q->buffer[q->idxTail][0] = id;
    q->buffer[q->idxTail][1] = durasi;
    q->buffer[q->idxTail][2] = ketahanan;
    q->buffer[q->idxTail][3] = harga;
}

void enqueue2(QueueDiner *q, ElType id, ElType durasi_tahan) {
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
    // KAMUS LOKAL
    // ALGORITMA
    if (isEmpty(*q)) {
        q->idxHead = 0;
        q->idxTail = 0;
    } else {
        q->idxTail = (q->idxTail + 1) % CAPACITY;
    }
    
    q->buffer[q->idxTail][0] = id;
    q->buffer[q->idxTail][1] = durasi_tahan;
}

void dequeue(QueueDiner *q, ElType **val) {
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */
    // KAMUS LOKAL
    // ALGORITMA
    val[0] = q->buffer[q->idxHead];
    if (q->idxHead == q->idxTail) {
        q->idxHead = IDX_UNDEF;
        q->idxTail = IDX_UNDEF;
    } else {
        q->idxHead = (q->idxHead + 1) % CAPACITY;
    }
}

void displayQueue4(QueueDiner q) {
/* I.S. q boleh kosong */
/* F.S. Menuliskan seluruh isi q ke layar */
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    for (i = 0; i <= IDX_TAIL(q); i++) {
        printf("M%d     | %d             | %d        | %d\n", q.buffer[i][0], q.buffer[i][1], q.buffer[i][2], q.buffer[i][3]);
    }
}

void displayQueue2(QueueDiner q) {
/* I.S. q boleh kosong */
/* F.S. Menuliskan seluruh isi q ke layar */
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    if (isEmpty(q)) printf("        |\n");
    else {
        for (i = 0; i <= IDX_TAIL(q); i++) {
            printf("M%d     | %d\n", q.buffer[i][0], q.buffer[i][1]);
        }
    }
}