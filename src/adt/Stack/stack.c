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
    int cnt = 0;
    /* ALGORITMA */
    while (InfoTop(*S)[cnt] != '\0') {
        *(*X + cnt) = InfoTop(*S)[cnt];
        cnt++;
    }
    Top(*S)--;
}

void InversStack(Stack *S) {
    /* KAMUS LOKAL */
    Stack CopyS1, CopyS2;
    char *X;
    /* ALGORITMA */
    X = (char*) malloc (10 *sizeof(char));
    /* Make X empty */

    CreateEmpty(&CopyS1);
    CreateEmpty(&CopyS2);

    while (!IsEmptyStack(*S)) {
        makeStringEmpty(X);
        char* CopyX;
        CopyX = (char*) malloc (10 *sizeof(char));
        makeStringEmpty(CopyX);

        Pop(S, &X);
        CopyString(X, CopyX);
        Push(&CopyS1, CopyX);
    }

    while (!IsEmptyStack(CopyS1)) {
        makeStringEmpty(X);
        char* CopyX;
        CopyX = (char*) malloc (10 *sizeof(char));
        makeStringEmpty(CopyX);

        Pop(&CopyS1, &X);
        CopyString(X, CopyX);
        Push(&CopyS2, CopyX);
    }

    while (!IsEmptyStack(CopyS2)) {
        makeStringEmpty(X);
        char* CopyX;
        CopyX = (char*) malloc (10 *sizeof(char));
        makeStringEmpty(CopyX);
        
        Pop(&CopyS2, &X);
        CopyString(X, CopyX);
        Push(S, CopyX);
    }
}

void TulisStack(Stack S) {
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    for (i = Top(S); i >= 0; i--) {
        printf("%s\n", S.T[i]);
    }
}

void CopyString(char* str, char* output) {
    /* KAMUS LOKAL */
    int i = 0;
    /* ALGORITMA */
    while (str[i] != '\0') {
        output[i] = str[i];
        i++;
    }
}

void makeStringEmpty(char* str) {
    /* KAMUS LOKAL */
    int k;
    /* ALGORITMA */
    for (k = 0; k < 10; k++) {
        str[k] = '\0';
    }
}