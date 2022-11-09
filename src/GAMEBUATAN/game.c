/* File game.c */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* Include ADT */
#include "../adt/Mesin/mesinkata.h"

#include "game.h"

void game_buatan(char *game) {
/* 
I.S.: Pemain membuat game buatan dengan menggunakan command CREATE GAME
F.S.: Program langsung menghentikan game dan mengeluarkan skor akhir berupa random integer.
      Algoritma yang digunakan adalah Von Neumann Middle Square.
*/
    /* KAMUS LOKAL */
    /* ALGORITMA */
    printf("Selamat datang di %s!\n\n", game);
    printf("Permainan selesai!\n\n");
    printf("Skor Anda: %lld\n", randomNumber());
}