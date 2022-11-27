/* File save.c */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "save.h"

void save(char* filename, Array arrGame, StackHis history, ArrayMap scoreboard) {
/*
I.S.: file *.txt kosong atau sudah terisi
F.S.: State game dan history pemain tersave ke file *.txt
*/
    /* KAMUS LOKAL */
    char* temp;
    temp = (char*) malloc (500 *sizeof(char));
    int tempLength = 0;
    int i, j, k, cnt, cnt_name, cnt_score;
    int n = 0; /* jumlah sudah berapa kali temp melakukan malloc */
    /* ALGORITMA */
    FILE *fp = fopen(concatSTR("../data/", filename), "w+");

    /* Membuat temp menjadi kosong */
    makeMallocEmpty(temp, tempLength);
    /* Save list game */
    temp[tempLength] = arrGame.Neff + '0';
    temp[tempLength+1] = '\n';
    tempLength = 2;

    for (i = 0; i < arrGame.Neff; i++) {
        cnt = str_len(arrGame.TI[i]);
        /* Menghitung panjang string */

        for (j = 0; j < cnt; j++) {
            temp[tempLength] = arrGame.TI[i][j];
            tempLength++;
        }
        temp[tempLength] = '\n';
        tempLength++;
        
        if (tempLength >= InitialSize*n) {
            /* buat string hasil malloc menjadi kosong tanpa mengubah isi temp */
            makeMallocEmpty(temp, tempLength);
            n++;
        }
    }
    
    /* Save history game */
    temp[tempLength] = (Top(history) + 1) + '0';
    temp[tempLength+1] = '\n';
    tempLength = tempLength + 2;

    /* invers stack history */
    InversStackHis(&history);
    StackHis tempHis = CopyStackHis(&history);
    InversStackHis(&history);

    while(!IsEmptyStackHis(tempHis)) {
        /* Menghitung panjang string */
        char* history_name;
        PopHis(&tempHis, &history_name);
        cnt = str_len(history_name);

        for (j = 0; j < cnt; j++) {
            temp[tempLength] = history_name[j];
            tempLength++;
        }
        temp[tempLength] = '\n';
        tempLength++;
        
        if (tempLength >= InitialSize*n) {
            /* buat string hasil malloc menjadi kosong tanpa mengubah isi temp */
            makeMallocEmpty(temp, tempLength);
            n++;
        }
    }

    /* Save scoreboard */
    for (k = 0; k < arrGame.Neff; k++)
    {
        temp[tempLength] = scoreboard.TIMap[k].CountMap + '0';
        temp[tempLength+1] = '\n';
        tempLength = tempLength + 2;

        if(!IsEmptyMap(scoreboard.TIMap[k]))
        {
            for (i = 0; i < scoreboard.TIMap[k].CountMap; i++) 
            {
                /* Menghitung panjang string nama */
                cnt_name = str_len(scoreboard.TIMap[k].ElementsMap[i].Key);

                for (j = 0; j < cnt_name; j++) {
                    temp[tempLength] = scoreboard.TIMap[k].ElementsMap[i].Key[j];
                    tempLength++;
                }

                temp[tempLength] = ' ';
                tempLength++;

                /* Menghitung panjang string score */

                /* mengubah integer score menjadi string */
                cnt_score = len_score(scoreboard.TIMap[k].ElementsMap[i].Value);
                char str_score[cnt_score];
                sprintf(str_score, "%d", scoreboard.TIMap[k].ElementsMap[i].Value);

                for (j = 0; j < cnt_score; j++) {
                    temp[tempLength] = str_score[j];
                    tempLength++;
                }
                temp[tempLength] = '\n';
                tempLength++;

                if (tempLength >= InitialSize*n) {
                    /* buat string hasil malloc menjadi kosong tanpa mengubah isi temp */
                    makeMallocEmpty(temp, tempLength);
                    n++;
                }
            }
        }
    }
    temp[tempLength-1] = '\0';

    if (temp != NULL) fputs(temp, fp);
    else {
        printf("Save gagal.\n");
    }
   
    if (!fp) {
        printf("Save gagal.\n");
    } else
    {
        printf("Save berhasil\n");
    }

    fclose(fp);
}

void makeMallocEmpty(char* temp, int len) {
/*
I.S.: temp hasil malloc berisi karakter-karakter sampah
F.S.: temp menjadi kosong
*/
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    for (i = len; i < InitialSize+len; i++) {
        temp[i] = '\0';
    }
}