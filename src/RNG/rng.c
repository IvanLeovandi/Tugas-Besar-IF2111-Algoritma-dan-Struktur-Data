#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rng.h"
#include "random_number.h"
#include "../adt/Mesin/mesinkata.h"

void rng() {
    /*
    Fungsi rng menentukan angka random antara 0-300. Pengguna menebak angka hingga tebakan benar. 
    Fungsi mengembalikan skor pengguna antara 1-30, dengan skor maksimal 30 dan
    skor berkurang 1 untuk tiap tebakan salah.
    */

    int angka = randomNumberWithMaxDigit(3); // mengambil angka random
    int tebakan;
    // int score = 30;

    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");

    printf("Tebakan: "); // mengambil masukan tebakan
    tebakan = InputInt();
    // scanf("%d", &tebakan);

    while (tebakan != angka){  // iterasi hingga input benar
        if (tebakan>angka){printf("Lebih kecil\n");} //memberitahu tebakan lebih kecil atau lebih besar dari angka
        else {printf("Lebih besar\n");}

        // if (score>1) {score --;} // mengurangi skor untuk tiap tebakan salah

        printf("Tebakan: ");  // tebakan berikutnya
        tebakan = InputInt();
        // scanf("%d", &tebakan);
    }

    printf("Ya, X adalah %d.\n", angka); // output berhasil

}