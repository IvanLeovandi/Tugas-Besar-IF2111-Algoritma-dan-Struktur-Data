// File game.c
#include <stdio.h>
#include "game.h"

void game_buatan(Word game) {
/* 
I.S.: Pemain membuat game buatan dengan menggunakan command CREATE GAME
F.S.: Program langsung menghentikan game dan mengeluarkan skor akhir berupa random integer
*/
    // KAMUS LOKAL
    int score;
    // ALGORITMA
    printf("Selamat datang di %s!\n\n", game.TabWord);
    printf("Permainan selesai!\n\n");
    printf("Skor Anda: %d", score);
}