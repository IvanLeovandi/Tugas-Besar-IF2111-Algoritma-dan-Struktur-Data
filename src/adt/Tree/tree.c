/* File tree.c */
#include "tree.h"

/* *** Konstruktor/Kreator *** */
BinTree NewTree(ElTypeTree X, BinTree L, BinTree R) {
/* Menghasilkan sebuah pohon biner dari X, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (NIL) jika alokasi gagal. */
    /* KAMUS LOKAL */
    BinTree p;
    /* ALGORITMA */
    p = newTreeNode(X);
    if (p != Nil) {
        LEFT(p) = L;
        RIGHT(p) = R;
    }
    return p;
}

void MakeTree(ElTypeTree X, BinTree L, BinTree R, BinTree *p) {
/* I.S. Sembarang */
/* F.S. Menghasilkan sebuah pohon p */
/* Menghasilkan sebuah pohon biner p dari akar, l, dan r, jika alokasi berhasil */
/* Menghasilkan pohon p yang kosong (NIL) jika alokasi gagal */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    *p = newTreeNode(X);
    if (*p != Nil) {
        LEFT(*p) = L;
        RIGHT(*p) = R;
    }
}

/* *** Memory Management *** */
BinTree newTreeNode(ElTypeTree X) {
/* Mengirimkan address hasil alokasi sebuah elemen bernilai x */
/* Jika alokasi berhasil, maka address tidak NIL, dan misalnya menghasilkan p, 
maka ROOT(p)=x, LEFT(p)=NIL, RIGHT(p)=NIL */
/* Jika alokasi gagal, mengirimkan NIL */
    /* KAMUS LOKAL */
    BinTree p;
    /* ALGORITMA*/
    p = (BinTree) malloc (sizeof(TreeNode));
    if (p != Nil) {
        ROOT(p) = X;
        LEFT(p) = Nil;
        RIGHT(p) = Nil;
    }
    return p;
}

void deallocTreeNode(BinTree p) {
/* I.S. p terdefinisi */
/* F.S. p dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address p */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    deallocTreeNode(LEFT(p));
    deallocTreeNode(RIGHT(p));
    free(p);
}

/* *** Predikat *** */
boolean isTreeEmpty(BinTree p) {
/* Mengirimkan true jika p adalah pohon biner yang kosong */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return p == Nil;
}

boolean isTreeOneElmt(BinTree p) {
/* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (!isTreeEmpty(p)) return LEFT(p) == Nil && RIGHT(p) == Nil;
    else return false;
}

boolean isUnerLeft(BinTree p) {
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerleft: hanya mempunyai subpohon kiri */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (!isTreeEmpty(p)) return LEFT(p) != Nil && RIGHT(p) == Nil;
    else return false;
}

boolean isUnerRight(BinTree p) {
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerright: hanya mempunyai subpohon kanan */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (!isTreeEmpty(p)) return LEFT(p) == Nil && RIGHT(p) != Nil;
    else return false;
}

boolean isBiner(BinTree p) {
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (!isTreeEmpty(p)) return LEFT(p) != Nil && RIGHT(p) != Nil;
    else return false;
}

void printPreOrder(BinTree p) {
/* I.S. Pohon p terdefinisi */
/* F.S. Semua node pohon p sudah dicetak secara pre-order: akar, kiri, kanan */
/* Basis: Pohon kosong tidak ada yang diproses */
/* Rekurens: */
/* Cetak akar p */
/* Cetak subpohon kiri p secara pre-order */
/* Cetak subpohon kanan p secara pre-order */
    RecursivePrint(p, 0);
}

void RecursivePrint(BinTree p, int depth) {
/* Menampilkan pohon biner p ke layar */
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    if (isTreeEmpty(p)) {
        for (i = 0; i <= depth; i++) {
            if (depth - i > 1) printf("   ");
            else if (depth - i == 1) {
                #ifdef _WIN32
                    printf("%c%c ", 192, 196);
                #else
                    printf("%s ", "\u2514\u2500");
                #endif
            }
        }
        printf("\n\n");
    } else {
        for (i = 0; i <= depth; i++) {
            if (depth - i > 1) printf("   ");
            else if (depth - i == 1) {
                #ifdef _WIN32
                    printf("%c%c ", 192, 196);
                #else
                    printf("%s ", "\u2514\u2500");
                #endif
            }
            else printf("%d", ROOT(p)); /* depth - i == 0 */
        }
        printf("\n\n");
        RecursivePrint(LEFT(p), depth+1);
        RecursivePrint(RIGHT(p), depth+1);
    }
}

/* *** Fungsi Lain *** */
int NbElmtTree(BinTree p) {
/* Pohon Biner mungkin kosong. */
/* Mengembalikan jumlah elemen dari pohon */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (isTreeEmpty(p)) return 0;
    else return 1 + NbElmtTree(LEFT(p)) + NbElmtTree(RIGHT(p));
}

int level(BinTree p, ElTypeTree X) {
/* Mengirimkan level dari node X yang merupakan salah satu node dari pohon biner P */
/* Akar(P) level-nya adalah 0. Pohon P tidak kosong dan elemen-elemennya unik.*/
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (ROOT(p) == X) return 1;
    else {
        if (searchTreeNode(LEFT(p), X)) return 1 + level(LEFT(p), X);
        else return 1 + level(RIGHT(p), X);
    }
}

int depth(BinTree p) {
/* Mengirimkan maksimum level suatu pohon biner p */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (isTreeEmpty(p)) return 0;
    else return 1 + Max(depth(LEFT(p)), depth(RIGHT(p)));
}

int Max(int a, int b) {
/* Mengembalikan nilai terbesar antara a dan b */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (a > b) return a;
    else return b;
}

boolean searchTreeNode(BinTree p, ElTypeTree X) {
/* Mengirimkan true jika ada node dari P yang bernilai X */
/* Basis 0 */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (isTreeEmpty(p)) return false;
    else return searchBaseOne(p, X);
}

boolean searchBaseOne(BinTree p, ElTypeTree X) {
/* Mengirimkan true jika ada node dari P yang bernilai X */
/* Basis 1 */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (ROOT(p) == X) return true;
    else if (!isTreeOneElmt(p)) {
        if (searchTreeNode(LEFT(p), X)) return true;
        else return searchTreeNode(RIGHT(p), X);
    } else {
        return false;
    }
}

boolean isLeaf(BinTree p, ElTypeTree X) {
/* Mengembalikan true jika X adalah daun dari pohon biner p */
/* X pasti ada di pohon biner P */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (ROOT(p) == X) {
        return isTreeOneElmt(p);
    } else {
        if (searchTreeNode(LEFT(p), X)) isLeaf(LEFT(p), X);
        else isLeaf(RIGHT(p), X);
    }
}

void addLeaf(BinTree *p, ElTypeTree X, ElTypeTree Y, boolean Left) {
/* I.S. P tidak kosong, X adalah daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri), atau
sebagai anak Kanan X (jika not Kiri). Jika ada lebih dari satu daun bernilai
X, Y ditambahkan pada daun paling kiri. */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (isTreeOneElmt(*p)) {
        if (Left) LEFT(*p) = newTreeNode(Y);
        else RIGHT(*p) = newTreeNode(Y);
    } else {
        if (searchTreeNode(LEFT(*p), X)) addLeaf(&LEFT(*p), X, Y, Left);
        else addLeaf(&RIGHT(*p), X, Y, Left);
    }
}

BinTree treeLocation(BinTree p, ElTypeTree X) {
/* Mengembalikan address dari elemen node yang bernilai X */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (ROOT(p) == X) return p;
    else {
        if (searchTreeNode(LEFT(p), X)) return treeLocation(LEFT(p), X);
        else return treeLocation(RIGHT(p), X);
    }
}