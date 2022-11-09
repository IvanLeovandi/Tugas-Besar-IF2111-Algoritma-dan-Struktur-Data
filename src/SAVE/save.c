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
    
    fputs(temp, fp);
   
    if (!fp) {
        printf("Failed to save.\n");
    } else
    {
        printf("Save berhasil");
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

// int main() {
//     char filename[] = "test.txt";
//     Word recentSentence;
//     Array arrSentence;
//     MakeEmpty(&arrSentence);
   
//     // for (int num = 0; num < 2; num++) {
//     STARTWORD();
//     recentSentence = currentWord;
//     printf("recentSentence: %s\n\n", recentSentence.TabWord);
//     int n = recentSentence.TabWord[0] - '0';
//     // ADVWORD();
//     for (int i = 0; i < n; i++) {
//         recentSentence.TabWord[recentSentence.Length] = '\n';
//         int tempLength = recentSentence.Length+1;
//         EndWord = false;
//         // printf("Input: ");
//         STARTWORD();
//         int k = 0;
//         recentSentence.Length += (currentWord.Length + 1);
//         for (int j = tempLength; j < recentSentence.Length; j++) {
//             recentSentence.TabWord[j] = currentWord.TabWord[k];
//             k++;
//         }
//         // printf("\n%d\nrecentSentence: %s\n\n", i, recentSentence.TabWord);
//     }
    
//     arrSentence.TI[arrSentence.Neff] = recentSentence.TabWord;
//     // arrSentence.Neff++;
//     save(filename, arrSentence);
    
//     return 0;
// }