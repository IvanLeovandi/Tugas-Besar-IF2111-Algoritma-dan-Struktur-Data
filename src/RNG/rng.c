#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rng.h"

void rng(int *score) {
    /*
    Fungsi rng menentukan angka random antara 0-300. Pengguna menebak angka hingga tebakan benar. 
    Fungsi mengembalikan skor pengguna antara 1-30, dengan skor maksimal 30 dan
    skor berkurang 1 untuk tiap tebakan salah.
    */

    int angka = randomNumberWithMaxDigit(3) % 301;
    // int angka = rand()%301; // mengambil angka random
    int tebakan;
    int score_rng = 20;

    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");

    printf("Tebakan: "); // mengambil masukan tebakan
    tebakan = InputInt();
    // scanf("%d", &tebakan);

    while (tebakan != angka){  // iterasi hingga input benar
        if (tebakan>angka){printf("Lebih kecil\n");} //memberitahu tebakan lebih kecil atau lebih besar dari angka
        else {printf("Lebih besar\n");}

        if (score_rng>1) {score_rng --;} // mengurangi skor untuk tiap tebakan salah

        printf("Tebakan: ");  // tebakan berikutnya
        tebakan = InputInt();
    }
    printf("Ya, X adalah %d.\n", angka); // output berhasil
    printf("Kamu mendapatkan score : %d\n", score_rng);
    *score = score_rng;
}