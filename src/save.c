/* File save.c */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "save.h"

void save(char* filename, Array arrSentence) {
/* State game pemain tersave ke *.txt */
    /* KAMUS LOKAL */
    char* temp;
    temp = (char*) malloc (10 *sizeof(char));
    int tempLength = 0;
    /* ALGORITMA */
    FILE *fp = fopen(filename, "w+");

    for (int i = 0; i <= arrSentence.Neff; i++) {
        int cnt = 0;
        while (arrSentence.TI[i][cnt] != '\0') {
            cnt++;
        }

        for (int j = 0; j < cnt; j++) {
            temp[tempLength] = arrSentence.TI[i][j];
            tempLength++;
        }
        temp[tempLength] = 0x0A;
        tempLength++;
    }

    fputs(temp, fp);

    if (!fp) {
        printf("Failed to save.\n");
    }

    fclose(fp);
}