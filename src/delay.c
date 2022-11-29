#include <stdio.h>
#include <time.h>

void delay(int seconds) {
/* Memberi delay waktu pada program */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    int milli_seconds = 1000 * seconds; /* Konversi waktu ke milisekon*/
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

void loadingDelay() {
/* Memberi delay waktu pada saat loading game */
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    for (i = 0; i < 3; i++) {
        printf(". ");
        delay(1);
    }
}