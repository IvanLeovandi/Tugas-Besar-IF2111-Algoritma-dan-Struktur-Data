/* File array.c */
#include "array.h"
#include "../Mesin/mesinkata.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty (Array *T) {
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
    // KAMUS LOKAL
    // ALGORITMA
    T->Neff = 0;
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (Array T) {
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
    // KAMUS LOKAL
    // ALGORITMA
    return T.Neff;
}

/* *** Daya tampung container *** */
int MaxNbEl (Array T) {
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
    // KAMUS LOKAL
    // ALGORITMA
    return IdxMax - IdxMin + 1;
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (Array T) {
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
    // KAMUS LOKAL
    // ALGORITMA
    return IdxMin;
}

IdxType GetLastIdx (Array T) {
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
    // KAMUS LOKAL
    // ALGORITMA
    return T.Neff;
}

/* *** Menghasilkan sebuah elemen *** */
ElType GetElmt (Array T, IdxType i) {
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
    // KAMUS LOKAL
    // ALGORITMA
    return T.TI[i];
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (Array Tin, Array *Tout) {
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
    // KAMUS LOKAL
    // ALGORITMA
    MakeEmpty(Tout);
    for (int i = IdxMin; i <= Tin.Neff; i++) {
        Tout->TI[i] = Tin.TI[i];
    }
    Tout->Neff = Tin.Neff;
}

void SetEl (Array *T, IdxType i, ElType v) {
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
    // KAMUS LOKAL
    // ALGORITMA
    T->TI[i] = v;
    if (i > T->Neff) {
        T->Neff = i;
    }
}

void SetNeff (Array *T, IdxType N) {
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
    // KAMUS LOKAL
    // ALGORITMA
    T->Neff = N;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (Array T) {
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
    // KAMUS LOKAL
    // ALGORITMA
    return T.Neff == 0;
}

/* *** Test tabel penuh *** */
boolean IsFull (Array T) {
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
    // KAMUS LOKAL
    // ALGORITMA
    return T.Neff == IdxMax;
}

boolean IsElmt(Array array_game, char *str_game)
{
    if(IsEmpty(array_game))
    {
        return false;
    } else
    {
        int i = 0;
        while(i < NbElmt(array_game) && !compareSTR(array_game.TI[i], str_game))
        {
            i++;
        }
        if(i < NbElmt(array_game))
        {
            return true;
        } else
        {
            return false;
        }
    }
}