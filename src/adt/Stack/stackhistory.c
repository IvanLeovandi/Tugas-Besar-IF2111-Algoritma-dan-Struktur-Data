/* File stackhis.c */
#include "stackhistory.h"
#include <stdio.h>
#include <stdlib.h>

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStackHis(StackHis *S) {
/* I.S. sembarang; */
/* F.S. Membuat sebuah StackHis S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri StackHis kosong : TOP bernilai Nil */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    Top(*S) = NilHis;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStackHis(StackHis S) {
/* Mengirim true jika StackHis kosong: lihat definisi di atas */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return (Top(S) == NilHis);
}

boolean IsFullStackHis(StackHis S) {
/* Mengirim true jika tabel penampung NilHanoiai elemen StackHis penuh */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return (Top(S) == MaxHis-1);
}

/* ************ Menambahkan sebuah elemen ke StackHis ************ */
void PushHis(StackHis * S, infotypeHis X) {
/* Menambahkan X sebagai elemen StackHis S. */
/* I.S. S mungkin kosong, tabel penampung elemen StackHis TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    Top(*S)++;
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen StackHis ************ */
void PopHis(StackHis * S, infotypeHis* X) {
/* Menghapus X dari StackHis S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah NilHanoiai elemen TOP yang lama, TOP berkurang 1 */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    *X = InfoTop(*S);
    Top(*S)--;
}

void InversStackHis(StackHis *S) {
/* Membalikkan StackHis S */
/* I.S. S terdefinisi */
/* F.S. Urutan elemen pada S menjadi terbalik */
    /* KAMUS LOKAL */
    StackHis CopyS1, CopyS2;
    char *X;
    /* ALGORITMA */
    CreateEmptyStackHis(&CopyS1);
    CreateEmptyStackHis(&CopyS2);

    while (!IsEmptyStackHis(*S)) {
        PopHis(S, &X);
        PushHis(&CopyS1, X);
    }

    while (!IsEmptyStackHis(CopyS1)) {
        PopHis(&CopyS1, &X);
        PushHis(&CopyS2, X);
    }

    while (!IsEmptyStackHis(CopyS2)) {        
        PopHis(&CopyS2, &X);
        PushHis(S, X);
    }
}

void TulisStackHis(StackHis *S) {
/* Menuliskan seluruh elemen StackHis S ke layar */
    /* KAMUS LOKAL */
    char* X;
    StackHis temp;
    /* ALGORITMA */
    CreateEmptyStackHis(&temp);
    printf("[");
    while (!IsEmptyStackHis(*S)) {
        PopHis(S, &X);
        PushHis(&temp, X);
        if (IsEmptyStackHis(*S)) printf("%s]\n", X);
        else printf("%s,", X);
    }

    while (!IsEmptyStackHis(temp)) {
        PopHis(&temp, &X);
        PushHis(S, X);
    }
}

StackHis CopyStackHis(StackHis *S) {
/* Mengembalikan hasil salinan S */
    /* KAMUS LOKAL */
    StackHis temp1, temp2;
    char *X;
    /* ALGORITMA */
    CreateEmptyStackHis(&temp1);
    CreateEmptyStackHis(&temp2);

    while (!IsEmptyStackHis(*S)) {
        PopHis(S, &X);
        PushHis(&temp1, X);
        PushHis(&temp2, X);
    }

    while (!IsEmptyStackHis(temp2)) {
        PopHis(&temp2, &X);
        PushHis(S, X);
    }

    InversStackHis(&temp1);
    return temp1;
}