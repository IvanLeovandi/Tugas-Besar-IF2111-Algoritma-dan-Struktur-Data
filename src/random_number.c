#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "random_number.h"

unsigned long long int randm(int n);
unsigned long long int von(unsigned long long int x, int n);

unsigned long long int randomNumberWithMaxDigit(int digit) {
/* Mengembalikan random number dengan masukan jumlah digit */
    /* KAMUS LOKAL */
    unsigned long long int x, randNumber;
    int n = digit; /* jumlah digit random number yang diinginkan */
    int i;
    /* ALGORITMA */
    srand(time(NULL));

    x = randm(n);
    for (i = 0; i < n; i++) {
        randNumber = von(x, n);
        x = randNumber;
    }
    return randNumber;
}

unsigned long long int randomNumber() {
/* Mengembalikan random number tanpa masukan jumlah digit */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return randomNumberWithMaxDigit(5); /* default jumlah digit diset 5 */
}

unsigned long long int randm(int n) {
/* Mengembalikan random number dari jumlah digit n yang diinginkan */
    /* KAMUS LOKAL */
    double x;
    unsigned long long int y;
    /* ALGORITMA */
    srand(getpid()); /* Membuat seed */
    x = rand() / (double)RAND_MAX;
    y = x * pow(10.0, n*1.0);
    return y;
}

unsigned long long int von(unsigned long long int x, int n) {
/* Mengembalikan random number dengan algoritma Von Neumann Middle Square */ 
    /* KAMUS LOKAL */
    unsigned long long int y;
    int k;
    /* ALGORITMA */
    k = n * 0.5;
    y = (unsigned long long int)(x / pow(10.0, k*1.0) * x) % (unsigned long long int)(pow(10.0, n*1.0));
    return y;
}