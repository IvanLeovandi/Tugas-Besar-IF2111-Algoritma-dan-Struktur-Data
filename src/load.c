/* File load.c */
#include "adt/array.h"
#include "adt/mesinkarakter.h"
#include "adt/mesinkata.h"
#include "load.h"
#include "adt/loader.h"

#include <stdio.h>
#include <stdlib.h>

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

// int main()
// {
//     Array a;
//     MakeEmpty(&a);
//     load(&a, "../data/config.txt");

//     printf("Neff: %d\n", a.Neff);
//     int i;
//     for(i = 0; i < a.Neff; i++)
//     printf("%s\n", a.TI[i]);

//     // TulisIsi(a);

//     return 0;

// }