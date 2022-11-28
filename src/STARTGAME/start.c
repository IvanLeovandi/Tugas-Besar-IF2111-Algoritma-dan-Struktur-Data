#include <stdio.h>
#include "../adt/Array/array.h"
#include "start.h"
#include "../LOAD/load.h"


void STARTGAME(Array *array_game, StackHis *history, ArraySet *list_name, ArrayMap *scoreboard)
{

/*
I.S. Array array_game terdefinisi, Array array_game kosong;
F.S. Array array_game terisi dengan game yang berada pada file config.txt
*/
    boolean valid;
    valid = StartLOAD("../data/config.txt");
    if (valid)
    {
        int n, i;
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
    }
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
}