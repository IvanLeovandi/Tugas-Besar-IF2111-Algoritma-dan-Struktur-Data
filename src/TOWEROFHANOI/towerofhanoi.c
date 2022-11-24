/* File towerofhanoi.c */
#include "towerofhanoi.h"

void towerOfHanoi() {
/*
Spesifikasi game: seluruh piringan harus dipindahkan ke tiang C dengan
posisi yang sama (piringan paling bawah merupakan piringan yang paling besar
dan piringan paling atas merupakan piringan yang paling kecil), dengan
peraturannya adalah piringan yang di bawah tidak boleh lebih kecil daripada
piringan yang ada di atasnya.
*/
    /* KAMUS LOKAL */
    Stack StackA, StackB, StackC;
    int i, score, langkah = 0, opsi, piringan, optimal;
    char asal, tujuan;
    boolean win = false, valid = false;
    /* ALGORITMA */
    printf("Selamat datang di Tower of Hanoi!\n\n");
    printf("Permainan dimulai.\n\n");

    CreateEmpty(&StackA);
    CreateEmpty(&StackB);
    CreateEmpty(&StackC);

    while (!valid) {
        printf("Terdapat 4 pilihan opsi:\n");
        printf("1. Jumlah piringan ada 4.\n2. Jumlah piringan ada 5.\n3. Jumlah piringan ada 6.\n4. Jumlah piringan custom.\n\n");
        printf("Masukkan nomor opsi: ");
        opsi = StrToInt(Input());
        printf("\n");

        if (opsi == 1 || opsi == 2 || opsi == 3 || opsi == 4) valid = true;
        else printf("Masukkan tidak valid, silakan input kembali...\n\n");   
    }

    if (opsi == 1) piringan = 4;
    else if (opsi == 2) piringan = 5;
    else if (opsi == 3) piringan = 6;
    else if (opsi == 4) {
        printf("Masukkan jumlah piringan yang diinginkan: ");
        piringan = StrToInt(Input());
        printf("\n");
    }

    optimal = langkahTower(piringan, 'A', 'C', 'B');
    printf("Langkah optimal untuk memenangkan game adalah %d.\n\n", optimal);
    printf("Skor maksimal: %d\n\n", optimal/3);

    for (i = 1; i <= piringan; i++) {
        Push(&StackA, 2*i-1);
    }

    InversStack(&StackA);
    Tulis3Stack(StackA, StackB, StackC, piringan);

    while (!win) {
        printf("TIANG ASAL: ");
        asal = StrToInt(Input()) + '0';
        printf("TIANG TUJUAN: ");
        tujuan = StrToInt(Input()) + '0';
        ClearScreen();
        printf("\nMemindahkan piringan ke %c...\n\n", tujuan);

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

        if (langkah == optimal) score = optimal/3;
        else if (langkah > optimal) score--;

        Tulis3Stack(StackA, StackB, StackC, piringan);
        win = Win(StackC, piringan);

        if (score == 0) win = true;
    }

    if (score > 0) printf("Kamu berhasil!\n\n");
    else printf("Kamu gagal :(\n\n");

    printf("Skor didapatkan: %d\n", score);
}

void Tulis3Stack(Stack StackA, Stack StackB, Stack StackC, int piringan) {
/* Menulis StackA, StackB, dan StackC ke layar */
    /* KAMUS LOKAL */
    int i, j;
    long long int max;
    /* ALGORITMA */
    max = 2*piringan - 1;
    for (i = piringan-1; i >= 0; i--) {
        if (i > Top(StackA)) {
            for (j = 0; j < piringan-1; j++) {
                printf(" ");
            }
            printf("|");
            for (j = 0; j < piringan-1; j++) {
                printf(" ");
            }
        }
        else printf("%s", ConvertToStar(StackA.T[i], max));
        printf("%c", '\t');

        if (i > Top(StackB)) {
            for (j = 0; j < piringan-1; j++) {
                printf(" ");
            }
            printf("|");
            for (j = 0; j < piringan-1; j++) {
                printf(" ");
            }
        }
        else printf("%s", ConvertToStar(StackB.T[i], max));
        printf("%c", '\t');

        if (i > Top(StackC)) {
            for (j = 0; j < piringan-1; j++) {
                printf(" ");
            }
            printf("|");
            for (j = 0; j < piringan-1; j++) {
                printf(" ");
            }
            printf("\n");
        }
        else printf("%s\n", ConvertToStar(StackC.T[i], max));
    }

    TulisBase(StackA, max);
    TulisBase(StackB, max);
    TulisBase(StackC, max);
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

char* ConvertToStar(int num, int max) {
/* Mengonversi num ke dalam bentuk star */
    /* KAMUS LOKAL */
    int i;
    char* star;
    /* ALGORITMA */
    star = (char*) malloc ((max+1) *sizeof(star));
    for (i = 0; i < max+1; i++) {
        star[i] = ' ';
    }
    for (i = 0; i < num; i++) {
        star[(max-num)/2 + i] = 176;
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
    boolean win = false;
    int i = 0;
    /* ALGORITMA */
    if (!IsEmptyStack(S)) {
        win = true;
        while (win && i < piringan && i <= Top(S)) {
            if (S.T[i] != 2*piringan-(2*(i+1)-1)) win = false;
            else {
                i++;
            }
        }
        if (i != piringan) win = false;
    }
    return win;
}

int langkahTower(int piringan, char awal, char tujuan, char additional) {
/* Menghitung langkah optimal dari permainan Tower of Hanoi */
	/* KAMUS LOKAL */
    /* ALGORITMA */
    if (piringan == 1) {
        return 1;
    } else {
        return 1 + langkahTower(piringan-1, awal, additional, tujuan) + langkahTower(piringan-1, additional, tujuan, awal);
    }
}

void TulisBase(Stack S, long long int max) {
    /* KAMUS LOKAL */
    int i, j;
    /* ALGORITMA */
    if (IsEmptyStack(S)) {
        for (i = 0; i < max/2-1; i++) {
            printf(" ");
        }
        for (i = 0; i < 3; i++) {
            printf("%c", 205);
        }
        for (i = 0; i < max/2-1; i++) {
            printf(" ");
        }
    } else {
        printf(" ");
        for (i = 0; i < max-2; i++) {
            printf("%c", 205);
        }
        printf(" ");
    }
    printf("%c", '\t');
}