/* File game.c */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "game.h"

void game_buatan(char *game, int *score) {
/* 
I.S.: Pemain membuat game buatan dengan menggunakan command CREATE GAME
F.S.: Program langsung menghentikan game dan mengeluarkan skor akhir berupa random integer.
      Algoritma yang digunakan adalah Von Neumann Middle Square.
*/
    /* KAMUS LOKAL */
    int score_sem;
    /* ALGORITMA */
    printf("Selamat datang di %s!\n\n", game);
    printf("Permainan selesai!\n\n");
    score_sem =randomNumber();
    printf("Skor Anda: %d\n", score_sem);
    *score = score_sem;
}