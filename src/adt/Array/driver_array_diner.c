#include <stdio.h>
#include <stdlib.h>
#include "array_diner.h"

int main () {
    /* KAMUS LOKAL */
    ArrayDiner arrDiner;
    ElTypeDiner val1, val2, val3;
    int idx;
    /* ALGORITMA */
    MakeEmptyDiner(&arrDiner);

    if (IsEmptyDiner(arrDiner)) printf("arrDiner kosong\n");
    
    val1.id_makanan = 1;
    val1.durasi = 3;
    val1.ketahanan = 5;
    val1.harga = 15000;

    val2.id_makanan = 2;
    val2.durasi = 5;
    val2.ketahanan = 3;
    val2.harga = 35000;

    val3.id_makanan = 3;
    val3.durasi = 4;
    val3.ketahanan = 1;
    val3.harga = 25000;

    AddEl(&arrDiner, val1);
    AddEl(&arrDiner, val2);
    AddEl(&arrDiner, val3);

    printf("Banyaknya elemen arrDiner: %d\n", NbElmtDiner(arrDiner));
    printf("Banyaknya elemen max arrDiner: %d\n\n", MaxNbElDiner(arrDiner));

    printf("Indeks pertama arrDiner: %d\n", GetFirstIdxDiner(arrDiner));
    printf("Indeks terakhir arrDiner: %d\n\n", GetLastIdxDiner(arrDiner));

    SetNeffDiner(&arrDiner, 3);

    if (IsFullDiner(arrDiner)) printf("arrDiner full\n");

    idx = SearchIdArray(arrDiner, 0);

    printf("Isi arrDiner sebelum didelete:\n");
    TulisArrayDiner(arrDiner);
    printf("\n");

    DelEl(&arrDiner, &val2, idx);
    printf("Isi arrDiner setelah didelete:\n");
    TulisArrayDiner(arrDiner);

    return 0;
}

/* How To Run */
/* gcc -o driver driver_array_diner.c array_diner.c */