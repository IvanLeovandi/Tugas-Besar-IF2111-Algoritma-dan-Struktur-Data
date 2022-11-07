/* File dinerdash.c */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "dinerdash.h"

int main() {
    /* KAMUS LOKAL */
    int saldo = 0;
    int i, id;
    int lb_durasi = 1, up_durasi = 5, lb_harga = 10000, up_harga = 50000;
    unsigned long long int durasi, ketahanan, harga, x;
    /* ALGORITMA */
    printf("Selamat Datang di Diner Dash!\n\n");
    printf("SALDO: %d\n\nDaftar Pesanan\n", saldo);
    printf("Makanan | Durasi memasak | Ketahanan | Harga\n");
    printf("----------------------------------------------\n");

    for (i = 0; i < 3; i++) {
        id = i;
        durasi = randomNumberMinMax(lb_durasi, up_durasi);
        ketahanan = randomNumberMinMax(lb_durasi, up_durasi);
        harga = randomNumberMinMax(lb_harga, up_harga);
        printf("M%d     | %lld             | %lld        | %lld\n", id, durasi, ketahanan, harga);
    }

    printf("Daftar Makanan yang sedang dimasak\n");

    return 0;
}