/* File ArrayDiner.c */
#include "array_diner.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmptyDiner (ArrayDiner *T) {
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
    // KAMUS LOKAL
    // ALGORITMA
    T->Neff = IdxUndef;
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmtDiner (ArrayDiner T) {
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
    // KAMUS LOKAL
    // ALGORITMA
    return T.Neff;
}

/* *** Daya tampung container *** */
int MaxNbElDiner (ArrayDiner T) {
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
    // KAMUS LOKAL
    // ALGORITMA
    return IdxMax - IdxMin + 1;
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdxDiner (ArrayDiner T) {
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
    // KAMUS LOKAL
    // ALGORITMA
    return IdxMin;
}

IdxType GetLastIdxDiner (ArrayDiner T) {
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
    // KAMUS LOKAL
    // ALGORITMA
    return T.Neff;
}

/* *** Menghasilkan sebuah elemen *** */
void SetNeffDiner (ArrayDiner *T, IdxType N) {
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
    // KAMUS LOKAL
    // ALGORITMA
    T->Neff = N;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidDiner (ArrayDiner T, IdxType i) {
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
    // KAMUS LOKAL
    // ALGORITMA
    return (i >= IdxMin && i <= IdxMax);
}

boolean IsIdxEffDiner (ArrayDiner T, IdxType i) {
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
    // KAMUS LOKAL
    // ALGORITMA
    return (i >= IdxMin && i <= T.Neff);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyDiner (ArrayDiner T) {
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
    // KAMUS LOKAL
    // ALGORITMA
    return T.Neff == IdxUndef;
}

/* *** Test tabel penuh *** */
boolean IsFullDiner (ArrayDiner T) {
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
    // KAMUS LOKAL
    // ALGORITMA
    return T.Neff == IdxMax;
}