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
    x = randm(n);
    for (i = 0; i < n*n; i++) {
        randNumber = von(x, n);
        x = randNumber + (randNumber+1)*von(randm(n), n); /* lakukan LCG */
    }
    return randNumber;
}

unsigned long long int randomNumberMinMax(int lowerbound, int upperbound) {
/* Mengembalikan random number dengan masukan batas minimum dan maksimum angka */
    /* KAMUS LOKAL */
    unsigned long long int a;
    /* ALGORITMA */
    return randomNumberWithMaxDigit(9) % (upperbound + 1 - lowerbound) + lowerbound;
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
    long long int seed;
    unsigned long long int y;
    int i;
    /* ALGORITMA */
    // u = (double*) malloc (sizeof(double));

    for (i = 0; i < n*n*n; i++) {
        x = (rand() + seed) / (double)RAND_MAX;
        y = x * pow(10.0, n*1.0);
    }
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