/* File load.c */
#include <stdio.h>
#include <stdlib.h>
#include "load.h"

static FILE *tape;
static int retval;

void load(Array *array_game, char *filename, boolean isStart) {
/* Membaca isi file "filename" dan memasukkannya ke dalam array_game */
    /* KAMUS LOKAL */
    int i, j, n;
    boolean valid;
    /* ALGORITMA */
    /* Mengecek apakah melakukan load pada file konfigurasi atau bukan*/
    if(isStart)
    {
        valid = StartLOAD(filename);
    } else
    {
        valid = StartLOAD(concatSTR("../data/", filename));
    }

    if(valid)
    {
        n = currentChar - '0';
        array_game->Neff = n;
        ADVLOAD();
        for (i = 0; i < n; i++) {
            ADVWORDLOAD();
            char *strgame;
            strgame = (char *)malloc(currentWord.Length * sizeof(char));
            if(strgame == NULL)
            {
                printf("File tidak ditemukan, mohon masukan nama file yang valid.\n");
            } else
            {
                int idx;
                for(idx = 0; idx < currentWord.Length; idx++)
                {
                    *(strgame + idx) = currentWord.TabWord[idx];
                }
                *(strgame + currentWord.Length) = '\0';
                array_game->TI[i] = strgame;
            }
        }
        if(!isStart)
        {
            printf("File berhasil dibaca. BNMO berhasil dijalankan.\n");
        }
    } else
    {
        printf("File tidak ditemukan, mohon masukan nama file yang valid.\n");
    }
}

