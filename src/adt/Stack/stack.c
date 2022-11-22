/* File stack.c */
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S) {
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    Top(*S) = Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S) {
/* Mengirim true jika Stack kosong: lihat definisi di atas */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return (Top(S) == Nil);
}

boolean IsFullStack(Stack S) {
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return (Top(S) == MaxEl-1);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, infotype X) {
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    Top(*S)++;
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, infotype* X) {
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    *X = InfoTop(*S);
    Top(*S)--;
}

void InversStack(Stack *S) {
/* Membalikkan Stack S */
/* I.S. S terdefinisi */
/* F.S. Urutan elemen pada S menjadi terbalik */
    /* KAMUS LOKAL */
    Stack CopyS1, CopyS2;
    int X;
    /* ALGORITMA */
    CreateEmpty(&CopyS1);
    CreateEmpty(&CopyS2);

    while (!IsEmptyStack(*S)) {
        Pop(S, &X);
        Push(&CopyS1, X);
    }

    while (!IsEmptyStack(CopyS1)) {
        Pop(&CopyS1, &X);
        Push(&CopyS2, X);
    }

    while (!IsEmptyStack(CopyS2)) {        
        Pop(&CopyS2, &X);
        Push(S, X);
    }
}

void TulisStack(Stack S) {
/* Menuliskan seluruh elemen Stack S ke layar */
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    for (i = Top(S); i >= 0; i--) {
        printf("%d\n", S.T[i]);
    }
}