/* File towerofhanoi.c */
#include "towerofhanoi.h"

void towerOfHanoi() {
    /* KAMUS LOKAL */
    Stack StackA, StackB, StackC;
    int i, score;
    char asal, tujuan;
    boolean win = false;
    /* ALGORITMA */
    printf("Selamat datang di Tower of Hanoi!\n\n");
    printf("Permainan dimulai.\n\n");
    
    CreateEmpty(&StackA);
    CreateEmpty(&StackB);
    CreateEmpty(&StackC);

    for (i = 1; i <= 5; i++) {
        Push(&StackA, 2*i-1);
    }

    InversStack(&StackA);
    Tulis3Stack(StackA, StackB, StackC);

    while (!win) {
        printf("TIANG ASAL: ");
        scanf(" %c",&asal);
        printf("TIANG TUJUAN: ");
        scanf(" %c", &tujuan);
        printf("\nMemindahkan piringan ke %c...\n\n", tujuan);

        if (asal == 'A' && tujuan == 'B') MoveTop(&StackA, &StackB);
        else if (asal == 'A' && tujuan == 'C') MoveTop(&StackA, &StackC);
        else if (asal == 'B' && tujuan == 'A') MoveTop(&StackB, &StackA);
        else if (asal == 'B' && tujuan == 'C') MoveTop(&StackB, &StackC);
        else if (asal == 'C' && tujuan == 'A') MoveTop(&StackC, &StackA);
        else if (asal == 'C' && tujuan == 'B') MoveTop(&StackC, &StackB);

        Tulis3Stack(StackA, StackB, StackC);
        win = Win(StackC);
    }

    if (win) {
        printf("Kamu berhasil!\n\n");
    }

    printf("Skor didapatkan: %d\n", score);

}

void Tulis3Stack(Stack StackA, Stack StackB, Stack StackC) {
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    for (i = 4; i >= 0; i--) {
        if (i > Top(StackA)) printf("    |    ");
        else printf("%s", ConvertToStar(StackA.T[i]));

        if (i > Top(StackB)) printf("    |    ");
        else printf("%s", ConvertToStar(StackB.T[i]));

        if (i > Top(StackC)) printf("    |    \n");
        else printf("%s\n", ConvertToStar(StackC.T[i]));
    }
    printf(" -------  -------  ------- \n    A        B        C    \n\n");
}

char* ConvertToStar(int num) {
    /* KAMUS LOKAL */
    int i;
    char* star;
    /* ALGORITMA */
    star = (char*) malloc (10 *sizeof(star));
    for (i = 0; i < 10; i++) {
        star[i] = ' ';
    }
    for (i = 0; i < num; i++) {
        star[(9-num)/2 + i] = '*';
    }
    star[9] = '\0';
    return star;
}

int main() {
    towerOfHanoi();
    return 0;
}

void MoveTop(Stack *awal, Stack *tujuan) {
    /* KAMUS LOKAL */
    int X, top;
    /* ALGORITMA */
    Pop(awal, &X);
    if (IsEmptyStack(*tujuan)) Push(tujuan, X);
    else {
        top = InfoTop(*tujuan);        
        if (X < top) Push(tujuan, X);
        else {
            Push(awal, X);
            printf("Tidak dapat melakukan pemindahan...\n\n");
        }
    }
}

boolean Win(Stack S) {
    /* KAMUS LOKAL */
    boolean win = false;
    int i = 0;
    /* ALGORITMA */
    if (!IsEmptyStack(S)) {
        win = true;
        while (win && i < 5 && i <= Top(S)) {
            if (S.T[i] != 10-(2*(i+1)-1)) win = false;
            else i++;
        }
        if (i != 5) win = false;
    }
    return win;
}