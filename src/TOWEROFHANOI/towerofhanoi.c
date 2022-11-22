/* File towerofhanoi.c */
#include "towerofhanoi.h"

void towerOfHanoi() {
    /* KAMUS LOKAL */
    Stack S, CopyS, InversS;
    int i, j;
    char *X;
    char star[10] = "";
    /* ALGORITMA */
    printf("Selamat datang di Tower of Hanoi!\n\n");
    printf("Permainan dimulai.\n\n");
    
    CreateEmpty(&S);
    CreateEmpty(&CopyS);
    CreateEmpty(&InversS);
    for (i = 1; i <= 5; i++) {
        for (j = 0; j < 2*i-1; j++) {
            star[j] = '*';
        }
        
        char *CopyStar;
        CopyStar = (char*) malloc (10 *sizeof(char));
        
        makeStringEmpty(CopyStar);

        for (int k = 0; k < 5-i; k++) {
            CopyStar[k] = ' ';
        }

        for (int k = 0; k < 2*i-1; k++) {
            CopyStar[5-i+k] = star[k];
        }

        Push(&S, CopyStar);
    }
    InversStack(&S);
    TulisStack(S);
    // printf(" -------\n    A\n");
}

int main() {
    towerOfHanoi();
    return 0;
}