/* File save.c */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "save.h"

void save(char* filename, Array arrGame) {
/*
I.S.: file *.txt kosong atau sudah terisi
F.S.: State game dan history pemain tersave ke file *.txt
*/
    /* KAMUS LOKAL */
    char* temp;
    temp = (char*) malloc (100 *sizeof(char));
    int tempLength = 0;
    int i, j, cnt;
    int n = 0; /* jumlah sudah berapa kali temp melakukan malloc */
    /* ALGORITMA */
    FILE *fp = fopen(concatSTR("../data/", filename), "w+");

    /* Membuat temp menjadi kosong */
    makeMallocEmpty(temp, tempLength);

    temp[tempLength] = arrGame.Neff + '0';
    temp[tempLength+1] = '\n';
    tempLength = 2;

    for (i = 0; i < arrGame.Neff; i++) {
        cnt = 0;
        /* Menghitung panjang string */
        while (arrGame.TI[i][cnt] != '\0') {
            cnt++;
        }
        // printf("arrGame: %s\n", arrGamme.TI[i]);

        for (j = 0; j < cnt; j++) {
            temp[tempLength] = arrGame.TI[i][j];
            tempLength++;
        }

        if (i != arrGame.Neff-1) {
            temp[tempLength] = '\n';
            tempLength++;
        }
        
        if (tempLength >= InitialSize*n) {
            /* buat string hasil malloc menjadi kosong tanpa mengubah isi temp */
            makeMallocEmpty(temp, tempLength);
            n++;
        }
    }
    
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