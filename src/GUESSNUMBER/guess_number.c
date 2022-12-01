/* File guess_number.c */
#include <stdio.h>
#include "guess_number.h"

void guess_number(int *score_game) {
/*
Game tebak angka dengan menggunakan konsep binary tree.
Konsep binary tree: 
- Nilai LEFT(tree) selalu lebih kecil dari nilai ROOT(tree).
- Nilai RIGHT(tree) selalu lebih besar dari nilai ROOT(tree).
*/
    /* KAMUS LOKAL */
    BinTree soal, loc;
    int cnt;
    int X, Y, idx, level, nyawa;
    int len_node = 0;
    int nomor, ans, tebakan, score = 0;
    int upper = 50, lower = 0;
    boolean win = false, Left;
    /* ALGORITMA */
    printf("Selamat datang di Guess Number!\n\n");
    printf("Permainan dimulai.\n\n");

    printf("Mau level berapa? (1/2/3): ");
    level = StrToInt(Input());
    printf("\n");

    while (!(level >= 1 && level <= 3)) {
        ClearScreen();
        printf("Masukkan salah. Silakan input kembali.\n\n");
        printf("Mau level berapa? (1/2/3): ");
        level = StrToInt(Input());
        printf("\n");
    }

    if (level == 1) {
        cnt = randomNumberMinMax(3, 6);
        nyawa = 10;
    } else if (level == 2) {
        cnt = randomNumberMinMax(7, 10);
        nyawa = 15;
    } else {
        cnt = randomNumberMinMax(11, 13);
        nyawa = 20;
    }

    int node[cnt-1];
    
    X = randomNumberMinMax(lower+1, upper);
    MakeTree(X, Nil, Nil, &soal);
    node[len_node] = X;
    len_node++;
    cnt--;
    
    while (cnt > 0) {
        idx = randomNumberMinMax(0, len_node-1);
        while (isBiner(treeLocation(soal, node[idx])) || node[idx] == lower) {
            idx = randomNumberMinMax(0, len_node-1);
        }
        
        Left = randomNumberMinMax(0, 1);
        while (Left == 0 && node[idx] == upper) {
            idx = randomNumberMinMax(0, len_node-1);
        }
        X = node[idx];

        loc = treeLocation(soal, X);
        Y = randomNumberMinMax(lower, upper);
        
        if (isTreeOneElmt(loc)) {
            if (Left) {
                while (!(Y < X)) {
                    Y = randomNumberMinMax(lower, upper);
                }
            } else {
                while (!(Y > X)) {
                    Y = randomNumberMinMax(lower, upper);
                }
            }
            addLeaf(&loc, X, Y, Left);
        } else if (isUnerLeft(loc)) {
            while (!(Y > X)) { /* Y menjadi anak kanan dari X */
                if (X == upper) {
                    cnt++;
                    break;
                } else {
                    Y = randomNumberMinMax(lower, upper);
                }
            }
            RIGHT(loc) = newTreeNode(Y);
        } else {
            while (!(Y < X)) { /* Y menjadi anak kiri dari X */
                Y = randomNumberMinMax(lower, upper);
            }
            LEFT(loc) = newTreeNode(Y);
        }
        node[len_node] = Y;
        len_node++;
        cnt--;
    }    
    nomor = randomNumberMinMax(0, len_node-1);
    loc = treeLocation(soal, node[nomor]);
    ans = ROOT(loc);
    ROOT(loc) = -9999;

    printf("Berikut tampilan tree.\n\nTebak angka di balik -9999!\n\n");
    printPreOrder(soal);
    printf("\n\n");
    printf("Masukkan jawabanmu: ");
    tebakan = StrToInt(Input());
    printf("\n");

    if (tebakan != ans) nyawa--;

    while (tebakan != ans && nyawa > 0) {
        ClearScreen();
        printf("Jawaban kamu salah.\n\n");
        if (ans > tebakan) printf("Jawaban seharusnya lebih besar dari %d\n\n", tebakan);
        else printf("Jawaban seharusnya lebih kecil dari %d\n\n", tebakan);
        printf("Nyawa tersisa: %d\n\n", nyawa);
        printPreOrder(soal);
        printf("\n\n");
        printf("Masukkan kembali jawabanmu: ");
        tebakan = StrToInt(Input());
        printf("\n");
        nyawa--;
    }
    score = nyawa * 10;
    ClearScreen();
    if (nyawa > 0) {
        printf("\n");
        printf(" (`-').->              (`-')  (`-')  _ (`-')  _,---.,---.,---. \n");
        printf(" (OO )__      .->   <-.(OO )  ( OO).-/ ( OO).-/|   ||   ||   | \n");
        printf(",--. ,'-'(`-')----. ,------,)(,------.(,------.|   ||   ||   | \n");
        printf("|  | |  |( OO).-.  '|   /`. ' |  .---' |  .---'|   ||   ||   | \n");
        printf("|  `-'  |( _) | |  ||  |_.' |(|  '--. (|  '--. |  .'|  .'|  .' \n");
        printf("|  .-.  | \\|  |)|  ||  .   .' |  .--'  |  .--' `--' `--' `--'  \n");
        printf("|  | |  |  '  '-'  '|  |\\  \\  |  `---. |  `---..--. .--. .--.  \n");
        printf("`--' `--'   `-----' `--' '--' `------' `------'`--' `--' `--'  \n\n");
        printf("\nJawaban benar!\n\n");
    }
    else printf("Kamu gagal :(\n\nJawaban yang benar: %d\n\n", ans);

    printf("Tree yang benar:\n\n");
    ROOT(loc) = ans;
    printPreOrder(soal);

    printf("\nSkor akhir: %d\n", score);
    *score_game = score;
}