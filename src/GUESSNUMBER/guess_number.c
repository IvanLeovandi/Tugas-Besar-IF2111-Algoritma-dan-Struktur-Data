/* File guess_number.c */
#include "guess_number.h"
#include <stdio.h>
#include <time.h>

int guess_number() {
    /* KAMUS LOKAL */
    BinTree soal, loc;
    // int cnt = randomNumberMinMax(3, 10), idx;
    int cnt = 5;
    int node[cnt-1], X, Y, idx;
    int len_node = 0;
    boolean win = false, Left;
    /* ALGORITMA */
    printf("Selamat datang di Guess Number!\n\n");
    printf("Permainan dimulai.\n\n");
    
    X = randomNumberWithMaxDigit(2);
    MakeTree(X, Nil, Nil, &soal);
    node[len_node] = X;
    len_node++;
    
    while (cnt > 0) {
        idx = randomNumberMinMax(0, len_node-1);
        while (isBiner(treeLocation(soal, node[idx]))) {
            idx = randomNumberMinMax(0, len_node-1);
        }
        X = node[idx];
        loc = treeLocation(soal, X);
        printf("Info: %d\n", ROOT(loc));
        Y = randomNumberWithMaxDigit(2);

        if (isTreeOneElmt(loc)) {
            Left = randomNumberMinMax(0, 1);
            if (Left) {
                while (!(Y < X)) {
                    Y = randomNumberWithMaxDigit(2);  
                }
            } else {
                while (!(Y > X)) {
                    Y = randomNumberWithMaxDigit(2);  
                }
            }
            addLeaf(&soal, X, Y, Left);
        } else if (isUnerLeft(loc)) {
            while (!(Y > X)) {
                Y = randomNumberWithMaxDigit(2);
            }
            RIGHT(soal) = newTreeNode(Y);
        } else {
            while (!(Y < X)) {
                Y = randomNumberWithMaxDigit(2);
            }
            LEFT(soal) = newTreeNode(Y);
        }
        node[len_node] = Y;
        len_node++;
        cnt--;
        printPreOrder(soal);
        printf("\n");
    }

    printPreOrder(soal);
    printf("\n");
}

int main() {
    guess_number();
    return 0;
}