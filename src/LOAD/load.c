/* File load.c */
#include <stdio.h>
#include <stdlib.h>
#include "load.h"

static FILE *tape;
static int retval;

void load(Array *array_game, StackHis *history, ArraySet *list_name, ArrayMap *scoreboard, char *filename) {
/* Membaca isi file "filename" dan memasukkannya ke dalam array_game */
    /* KAMUS LOKAL */
    int i, j, n, nhist;
    boolean valid;
    /* ALGORITMA */
    /* Mengecek apakah melakukan load pada file konfigurasi atau bukan*/
    valid = StartLOAD(concatSTR("../data/", filename));
    if(valid)
    {
// load game
        n = StrToInt(KataToSTR(currentWord));
        array_game->Neff = n;
        ADVLOAD();
        for (i = 0; i < n; i++) {
            ADVWORDLOAD();
            char *strgame;
            strgame = (char *)malloc(currentWord.Length * sizeof(char));
            if(strgame == NULL)
            {
                printf("Game gagal dimuat.\n");
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
// load history
        ADVWORDLOAD();
        nhist = StrToInt(KataToSTR(currentWord));
        ADVLOAD();
        for (i = 0; i < nhist; i++) {
            ADVWORDLOAD();
            char *strhist;
            strhist = (char *)malloc(currentWord.Length * sizeof(char));
            if(strhist == NULL)
            {
                printf("History gagal dimuat.\n");
            } else
            {
                int idx;
                for(idx = 0; idx < currentWord.Length; idx++)
                {
                    *(strhist + idx) = currentWord.TabWord[idx];
                }
                *(strhist + currentWord.Length) = '\0';
                PushHis(history, strhist);
            }
        }
// load scoreboard
        SetNeffArrMap(scoreboard, n);
        for(i = 0; i < n; i++)
        {
            Map score_game; CreateEmptyMap(&score_game);
            Set nama_per_game; CreateEmptySet(&nama_per_game);
            ADVWORDLOAD();
            int nscore = StrToInt(KataToSTR(currentWord));
            ADVLOAD();
            for (j = 0; j < nscore; j++) {
                ADVWORDLOAD();
                char *score_lengkap;
                score_lengkap = (char *)malloc(currentWord.Length * sizeof(char));
                if(score_lengkap == NULL)
                {
                    printf("Score gagal dimuat.\n");
                } else
                {
                    int idx;
                    for(idx = 0; idx < currentWord.Length; idx++)
                    {
                        *(score_lengkap + idx) = currentWord.TabWord[idx];
                    }
                    *(score_lengkap + currentWord.Length) = '\0';
                    char *nama = FirstSTR(score_lengkap);
                    int score = StrToInt(SecSTR(score_lengkap));
                    add_to_scoreboard(&score_game, &nama_per_game, nama, score);
                }
            }
            SetElArrMap(scoreboard, i, score_game);
            SetElArrSet(list_name, i, nama_per_game);
        }
        printf("File berhasil dibaca. BNMO berhasil dijalankan.\n");
    }
    else
    {
        printf("File tidak ditemukan, mohon masukan nama file yang valid.\n");
    }
}

