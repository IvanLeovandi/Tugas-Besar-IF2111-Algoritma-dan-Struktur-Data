/* File guess_number.c */
#include "guess_number.h"
#include "../clear.h"

int guess_number() {
/*
Game tebak angka dengan menggunakan konsep binary tree.
Konsep binary tree: 
- Nilai LEFT(tree) selalu lebih kecil dari nilai ROOT(tree).
- Nilai RIGHT(tree) selalu lebih besar dari nilai ROOT(tree).
*/
    /* KAMUS LOKAL */
    BinTree soal, loc;
    int cnt = 17;
    // int cnt = randomNumberMinMax(3, 20);
    int node[cnt-1], X, Y, idx;
    int len_node = 0;
    int nomor, ans, tebakan, score = 0, nyawa = 10;
    int upper = 50, lower = 0;
    boolean win = false, Left;
    /* ALGORITMA */
    printf("Selamat datang di Guess Number!\n\n");
    printf("Permainan dimulai.\n\n");
    
    X = randomNumberMinMax(lower, upper);
    MakeTree(X, Nil, Nil, &soal);
    node[len_node] = X;
    len_node++;
    cnt--;
    
    while (cnt > 0) {
        idx = randomNumberMinMax(0, len_node-1);
        while (isBiner(treeLocation(soal, node[idx])) || node[idx] == lower) {
            idx = randomNumberMinMax(0, len_node-1);
        }
        X = node[idx];
        loc = treeLocation(soal, X);
        Y = randomNumberMinMax(lower, upper);
        if (isTreeOneElmt(loc)) {
            Left = randomNumberMinMax(0, 1);
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
                Y = randomNumberMinMax(lower, upper);
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
        printf("Jawaban kamu salah.\n");
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
}