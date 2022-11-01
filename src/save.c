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

    for (int i = 0; i < arrSentence.Neff; i++) {
        int cnt = 0;
        while (arrSentence.TI[i][cnt] != '\0') {
            cnt++;
        }

        for (int j = 0; j < cnt; j++) {
            temp[tempLength] = arrSentence.TI[i][j];
            tempLength++;
        }
        temp[tempLength] = '\n';
        tempLength++;
    }

    fputs(temp, fp);

    if (!fp) {
        printf("Failed.\n");
    }

    fclose(fp);
}

/*
int main() {
    char filename[] = "test.txt";
    Word recentSentence;
    Array arrSentence;
    MakeEmpty(&arrSentence);
    STARTWORD();
    recentSentence = currentWord;
    ADVWORD();


    while (!EndWord) {
        int tempSentenceLength = recentSentence.Length;
        recentSentence.Length += (currentWord.Length + 1);
        recentSentence.TabWord[tempSentenceLength] = ' '; // add space to the sentence
        
        int i, j = 0;
        for (i = tempSentenceLength+1; i < recentSentence.Length; i++) {
            recentSentence.TabWord[i] = currentWord.TabWord[j];
            j++;
        }
        ADVWORD();
    }
    recentSentence.TabWord[recentSentence.Length] = '\n';
    arrSentence.TI[arrSentence.Neff] = recentSentence.TabWord;
    arrSentence.Neff++;

    save(filename, arrSentence);
    
    // print array
    
    // for (int k = 0; k < arrSentence.Neff; k++) {
    //     printf("%s", arrSentence.TI[k]);
    // }
    
    return 0;
}
*/