/* File towerofhanoi.c */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "towerofhanoi.h"
#include "../color.h"

void towerOfHanoi(int *score_game) {
/*
Spesifikasi game: seluruh piringan harus dipindahkan ke tiang C dengan
posisi yang sama (piringan paling bawah merupakan piringan yang paling besar
dan piringan paling atas merupakan piringan yang paling kecil), dengan
peraturannya adalah piringan yang di bawah tidak boleh lebih kecil daripada
piringan yang ada di atasnya.
*/
    /* KAMUS LOKAL */
    Stack StackA, StackB, StackC;
    int i, score, score_optimal, langkah = 0, piringan, optimal;
    char asal, tujuan;
    boolean win = false;
    char* inputan;
    /* ALGORITMA */
    printf("Selamat datang di Tower of Hanoi!\n\n");
    printf("Permainan dimulai.\n\n");

    CreateEmptyStack(&StackA);
    CreateEmptyStack(&StackB);
    CreateEmptyStack(&StackC);

    printf("Masukkan jumlah piringan yang diinginkan: ");
    inputan = (char*) malloc (sizeof(char));
    inputan = Input();

    while (!validInt(inputan)) {
        ClearScreen();
        printf("Masukan salah, silakan input kembali jumlah piringan: ");
        inputan = Input();
    }
    
    piringan = StrToInt(inputan);
    printf("\n");

    while (piringan > 31 || piringan < 2) {
        ClearScreen();
        printf("Masukan yang valid hanyalah antara 2..31, silakan input kembali jumlah piringan: ");
        inputan = Input();
        while (!validInt(inputan)) {
            ClearScreen();
            printf("Masukan salah, silakan input kembali jumlah piringan: ");
            inputan = Input();
        }
        
        piringan = StrToInt(inputan);
        printf("\n");
    }

    optimal = pow(2, piringan)-1;
    score_optimal = optimal/3;
    printf("Langkah optimal untuk memenangkan game adalah %d.\n\n", optimal);
    printf("Skor maksimal: %d\n\n", optimal/3);

    for (i = 1; i <= piringan; i++) {
        Push(&StackA, 2*i-1);
    }

    InversStack(&StackA);
    Tulis3Stack(&StackA, &StackB, &StackC, piringan);

    while (!win) {
        printf("TIANG ASAL: ");
        asal = StrToInt(Input()) + '0';
        printf("TIANG TUJUAN: ");
        tujuan = StrToInt(Input()) + '0';
        ClearScreen();
        printf("\nMemindahkan piringan ke %c. . .", tujuan);
        printf("\n\n");

        if (asal == 'A' && tujuan == 'B') MoveTop(&StackA, &StackB, &langkah);
        else if (asal == 'A' && tujuan == 'C') MoveTop(&StackA, &StackC, &langkah);
        else if (asal == 'B' && tujuan == 'A') MoveTop(&StackB, &StackA, &langkah);
        else if (asal == 'B' && tujuan == 'C') MoveTop(&StackB, &StackC, &langkah);
        else if (asal == 'C' && tujuan == 'A') MoveTop(&StackC, &StackA, &langkah);
        else if (asal == 'C' && tujuan == 'B') MoveTop(&StackC, &StackB, &langkah);
        else {
            printf("Langkah tidak valid, tidak dapat melakukan pemindahan. Silakan input kembali...\n\n");
            langkah--;
        }

        langkah++;
        printf("Kamu telah melakukan %d langkah.\n\n", langkah);

        if (langkah == optimal) score = score_optimal;
        else if (langkah > optimal) score--;

        Tulis3Stack(&StackA, &StackB, &StackC, piringan);
        win = Win(StackC, piringan);

        if (score == 0) win = true;
    }

    if (score > 0) printf("Kamu berhasil!\n\n");
    else printf("Kamu gagal :(\n\n");

    printf("Skor didapatkan: %d\n", score);
    *score_game = score;
}

void Tulis3Stack(Stack *StackA, Stack *StackB, Stack *StackC, int piringan) {
/* Menulis StackA, StackB, dan StackC ke layar */
    /* KAMUS LOKAL */
    int i, j, k, z, X;
    Stack tempA, tempB, tempC;
    int max;
    /* ALGORITMA */
    CreateEmptyStack(&tempA);
    CreateEmptyStack(&tempB);
    CreateEmptyStack(&tempC);
    max = 2*piringan - 1;
    for (i = piringan-1; i >= 0; i--) {
        if (i > Top(*StackA)) {
            for (j = 0; j < piringan-1; j++) {
                printf(" ");
            }
            printf("|");
            for (j = 0; j < piringan-1; j++) {
                printf(" ");
            }
        }
        else {
            Pop(StackA, &X);
            Push(&tempA, X);
            ChangeStackColor(X);
            #ifdef _WIN32
                printf("%s", ConvertToBrick(X, max));
            #else
                for (z = 0; z < (max-X)/2; z++) {
                        printf(" ");
                }
                for (k = 0; k < X; k++) {
                    printf("%s", "\u2588");
                }
                for (z = 0; z < (max-X)/2; z++) {
                        printf(" ");
                }
            #endif
            RESET;
        }
        printf("%c", '\t');

        if (i > Top(*StackB)) {
            for (j = 0; j < piringan-1; j++) {
                printf(" ");
            }
            printf("|");
            for (j = 0; j < piringan-1; j++) {
                printf(" ");
            }
        }
        else {
            Pop(StackB, &X);
            Push(&tempB, X);
            ChangeStackColor(X);
            #ifdef _WIN32
                printf("%s", ConvertToBrick(X, max));
            #else
                for (z = 0; z < (max-X)/2; z++) {
                        printf(" ");
                }
                for (k = 0; k < X; k++) {
                    printf("%s", "\u2588");
                }
                for (z = 0; z < (max-X)/2; z++) {
                        printf(" ");
                }
            #endif
            RESET;
        }
        printf("%c", '\t');

        if (i > Top(*StackC)) {
            for (j = 0; j < piringan-1; j++) {
                printf(" ");
            }
            printf("|");
            for (j = 0; j < piringan-1; j++) {
                printf(" ");
            }
            printf("\n");
        }
        else {
            Pop(StackC, &X);
            Push(&tempC, X);
            ChangeStackColor(X);
            #ifdef _WIN32
                printf("%s", ConvertToBrick(X, max));
            #else
                for (z = 0; z < (max-X)/2; z++) {
                        printf(" ");
                }
                for (k = 0; k < X; k++) {
                    printf("%s", "\u2588");
                }
                for (z = 0; z < (max-X)/2; z++) {
                        printf(" ");
                }
            #endif
            printf("\n");
            RESET;
        };
    }
    
    while (!IsEmptyStack(tempA)) {
        Pop(&tempA, &X);
        Push(StackA, X);
    }

    while (!IsEmptyStack(tempB)) {
        Pop(&tempB, &X);
        Push(StackB, X);
    }

    while (!IsEmptyStack(tempC)) {
        Pop(&tempC, &X);
        Push(StackC, X);
    }

    TulisBase(*StackA, max);
    TulisBase(*StackB, max);
    TulisBase(*StackC, max);
    printf("\n");

    for (j = 0; j < 3; j++) {
        for (i = 0; i < piringan-1; i++) {
            printf(" ");
        }

        if (j == 0) printf("A");
        else if (j == 1) printf("B");
        else printf("C");
    
        for (i = 0; i < piringan-1; i++) {
            printf(" ");
        }
        printf("%c", '\t');
    }
    printf("\n\n");
}

char* ConvertToBrick(int num, int max) {
/* Mengonversi num ke dalam bentuk bata */
    /* KAMUS LOKAL */
    int i;
    char* star;
    /* ALGORITMA */
    star = (char*) malloc ((max+1) *sizeof(star));
    for (i = 0; i < max+1; i++) {
        star[i] = ' ';
    }
    for (i = 0; i < num; i++) {
        star[(max-num)/2 + i] = 219;
    }
    star[max] = '\0';
    return star;
}

void MoveTop(Stack *awal, Stack *tujuan, int *langkah) {
/*
Memindahkan top stack awal ke tujuan
I.S.: Stack awal dan tujuan terdefinisi
F.S.: Top awal berkurang 1, top tujuan bertambah 1
*/
    /* KAMUS LOKAL */
    int X, top;
    /* ALGORITMA */
    if (IsEmptyStack(*awal)) {
        printf("Langkah tidak valid, tidak dapat melakukan pemindahan. Silakan input kembali...\n\n");
        (*langkah)--;
    }
    else if (IsEmptyStack(*tujuan)) {
        Pop(awal, &X);
        Push(tujuan, X);
    }
    else {
        Pop(awal, &X);
        top = InfoTop(*tujuan);        
        if (X < top) Push(tujuan, X);
        else {
            Push(awal, X);
            (*langkah)--;
            printf("Langkah tidak valid, tidak dapat melakukan pemindahan. Silakan input kembali...\n\n");
        }
    }
}

boolean Win(Stack S, int piringan) {
/* Mengembalikan true jika kondisi S sudah sesuai dengan kondisi menang */
    /* KAMUS LOKAL */
    int i = 0, X;
    Stack temp;
    /* ALGORITMA */
    CreateEmptyStack(&temp);
    temp = CopyStack(&S);
    while (!IsEmptyStack(temp)) {
        Pop(&temp, &X);
        if (X != 2*i + 1) return false;
        i++;
    }
    if (i == piringan) return true;
    else return false;
}

void TulisBase(Stack S, int max) {
/* Menuliskan base ke layar */
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    if (IsEmptyStack(S)) {
        for (i = 0; i < max/2-1; i++) {
            printf(" ");
        }

        #ifdef _WIN32
            for (i = 0; i < 3; i++) {
                printf("%c", 205);
            }
        #else
            for (i = 0; i < 3; i++) {
                printf("%s", "\u2550");
            }
        #endif

        for (i = 0; i < max/2-1; i++) {
            printf(" ");
        }
    } else {
        printf(" ");

        #ifdef _WIN32
            for (i = 0; i < max-2; i++) {
                printf("%c", 205);
            }
        #else
            for (i = 0; i < max-2; i++) {
                printf("%s", "\u2550");
            }
        #endif

        printf(" ");
    }
    printf("%c", '\t');
}

void ChangeStackColor(int X) {
/* Mengganti warna stack pada Tower of Hanoi */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (X % 3 == 0) KUNING;
    else if (X % 3 == 1) MERAH;
    else BIRU;
}