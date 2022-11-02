/* File save.c */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "save.h"

void save(char* filename, Array arrGame, Array arrHistory) {
/*
I.S.: file *.txt kosong atau sudah terisi
F.S.: State game dan history pemain tersave ke file *.txt
*/
    /* KAMUS LOKAL */
    char* temp;
    temp = (char*) malloc (InitialSize *sizeof(char));
    int tempLength = 0;
    int i, j, cnt;
    int n = 0; /* jumlah sudah berapa kali temp melakukan malloc */
    /* ALGORITMA */
    FILE *fp = fopen(filename, "w+");

    /* Membuat temp menjadi kosong */
    makeMallocEmpty(temp, tempLength);

    for (i = 0; i <= arrGame.Neff; i++) {
        cnt = 0;
        /* Menghitung panjang string */
        while (arrGame.TI[i][cnt] != '\0') {
            cnt++;
        }

        for (j = 0; j < cnt; j++) {
            temp[tempLength] = arrGame.TI[i][j];
            tempLength++;
        }

        temp[tempLength] = 0x0A;
        tempLength++;
        if (tempLength >= InitialSize*n) {
            /* buat string hasil malloc menjadi kosong tanpa mengubah isi temp */
            makeMallocEmpty(temp, tempLength);
            n++;
        }
    }
    
    for (i = 0; i <= arrHistory.Neff; i++) {
        cnt = 0;
        /* Menghitung panjang string */
        while (arrHistory.TI[i][cnt] != '\0') {
            cnt++;
        }

        for (j = 0; j < cnt; j++) {
            temp[tempLength] = arrHistory.TI[i][j];
            tempLength++;
        }

        temp[tempLength] = 0x0A;
        tempLength++;
        if (tempLength >= InitialSize*n) {
            /* buat string hasil malloc menjadi kosong tanpa mengubah isi temp */
            makeMallocEmpty(temp, tempLength);
            n++;
        }
    }
    
    fputs(temp, fp);

    if (!fp) {
        printf("Failed to save.\n");
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