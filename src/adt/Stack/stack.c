/* File stack.c */
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S) {
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxStack */
/* jadi indeksnya antara 0.. MaxStack */
/* Ciri stack kosong : TOP berNilHanoiai NilHanoi */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    Top(*S) = NilHanoi;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S) {
/* Mengirim true jika Stack kosong: lihat definisi di atas */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return (Top(S) == NilHanoi);
}

boolean IsFullStack(Stack S) {
/* Mengirim true jika tabel penampung NilHanoiai elemen stack penuh */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return (Top(S) == MaxStack-1);
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
/* F.S. X adalah NilHanoiai elemen TOP yang lama, TOP berkurang 1 */
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
    CreateEmptyStack(&CopyS1);
    CreateEmptyStack(&CopyS2);

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

Stack CopyStack(Stack *S) {
/* Mengembalikan hasil salinan S */
    /* KAMUS LOKAL */
    Stack temp1, temp2;
    int X;
    /* ALGORITMA */
    CreateEmptyStack(&temp1);
    CreateEmptyStack(&temp2);

    while (!IsEmptyStack(*S)) {
        Pop(S, &X);
        Push(&temp1, X);
        Push(&temp2, X);
    }

    while (!IsEmptyStack(temp2)) {
        Pop(&temp2, &X);
        Push(S, X);
    }

    InversStack(&temp1);
    return temp1;
}