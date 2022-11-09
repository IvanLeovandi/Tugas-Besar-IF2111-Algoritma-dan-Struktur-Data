/* File load.c */
#include <stdio.h>
#include <stdlib.h>
#include "load.h"


static FILE *tape;
static int retval;

void load(Array *array_game, char *filename) {
/* Membaca isi file "filename" dan memasukkannya ke dalam array_game */
    /* KAMUS LOKAL */
    int i, j, n;
    /* ALGORITMA */
    /* Buka file */
    StartLOAD(filename);
    n = currentChar - '0';
    array_game->Neff = n;
    ADVLOAD();
    for (i = 0; i < n; i++) {
        ADVWORDLOAD();
        char *strgame;
        strgame = (char *)malloc(currentWord.Length * sizeof(char));
        int idx;
        for(idx = 0; idx < currentWord.Length; idx++)
        {
            *(strgame + idx) = currentWord.TabWord[idx];
        }
        *(strgame + currentWord.Length) = '\0';
        array_game->TI[i] = strgame;
    }
}

