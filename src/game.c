/* File game.c */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* Include ADT */
#include "adt/mesinkata.h"

#include "game.h"

#define digit 5

unsigned long long int randm(int n);
unsigned long long int von(unsigned long long int x, int n);

void game_buatan(Word game) {
/* 
I.S.: Pemain membuat game buatan dengan menggunakan command CREATE GAME
F.S.: Program langsung menghentikan game dan mengeluarkan skor akhir berupa random integer.
      Algoritma yang digunakan adalah Von Neumann Middle Square.
*/
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

    printf("Selamat datang di %s!\n\n", game.TabWord);
    printf("Permainan selesai!\n\n");
    printf("Skor Anda: %lld\n", randNumber);
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

/* CODE DI BAWAH INI BUAT NGE-RUN game_buatan */
/*
int main() {
    Word game;
    STARTWORD();
    game = currentWord;
    ADVWORD();

    while (!EndWord) {
        int tempLen = game.Length;
        game.Length += (currentWord.Length + 1);

        int j = 0;
        game.TabWord[tempLen] = ' ';
        for (int i = tempLen+1; i < game.Length; i++) {
            game.TabWord[i] = currentWord.TabWord[j];
            j++;
        }
        ADVWORD();
    }
    game_buatan(game);
    return 0;
}
*/