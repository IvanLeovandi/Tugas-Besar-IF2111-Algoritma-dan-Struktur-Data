/* File tree.h */
#include <stdio.h>
#include <stdlib.h>
#include "../../boolean.h"

#ifndef TREE_H
#define TREE_H

#define Nil NULL

/* *** Selektor *** */
#define ROOT(p) p->info
#define LEFT(p) (p)->left
#define RIGHT(p) (p)->right

typedef int ElType;
typedef struct treeNode* Address;
typedef struct treeNode {
    ElType info;
    Address left;
    Address right;
} TreeNode;
/* Definisi PohonBiner */
/* Pohon Biner kosong: p = NIL */

typedef Address BinTree;

/* *** Konstruktor/Kreator *** */
BinTree NewTree(ElType X, BinTree L, BinTree R);
/* Menghasilkan sebuah pohon biner dari X, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (NIL) jika alokasi gagal. */

void MakeTree(ElType X, BinTree L, BinTree R, BinTree *p);
/* I.S. Sembarang */
/* F.S. Menghasilkan sebuah pohon p */
/* Menghasilkan sebuah pohon biner p dari akar, l, dan r, jika alokasi berhasil */
/* Menghasilkan pohon p yang kosong (NIL) jika alokasi gagal */

/* *** Memory Management *** */
BinTree newTreeNode(ElType X);
/* Mengirimkan address hasil alokasi sebuah elemen bernilai x */
/* Jika alokasi berhasil, maka address tidak NIL, dan misalnya menghasilkan p, 
maka ROOT(p)=x, LEFT(p)=NIL, RIGHT(p)=NIL */
/* Jika alokasi gagal, mengirimkan NIL */

void deallocTreeNode(BinTree p);
/* I.S. p terdefinisi */
/* F.S. p dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address p */

/* *** Predikat *** */
boolean isTreeEmpty(BinTree p);
/* Mengirimkan true jika p adalah pohon biner yang kosong */

boolean isTreeOneElmt(BinTree p);
/* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */

boolean isUnerLeft(BinTree p);
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerleft: hanya mempunyai subpohon kiri */

boolean isUnerRight(BinTree p);
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerright: hanya mempunyai subpohon kanan */

boolean isBiner(BinTree p);
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan */

/* *** Input/Output *** */
void printPreOrder(BinTree p);
/* I.S. Pohon p terdefinisi */
/* F.S. Semua node pohon p sudah dicetak secara pre-order: akar, kiri, kanan */
/* Basis: Pohon kosong tidak ada yang diproses */
/* Rekurens: */
/* Cetak akar p */
/* Cetak subpohon kiri p secara pre-order */
/* Cetak subpohon kanan p secara pre-order */

/* *** Fungsi Lain *** */
int NbElmtTree(BinTree p);
/* Pohon Biner mungkin kosong. */
/* Mengembalikan jumlah elemen dari pohon */

int level(BinTree p, ElType X);
/* Mengirimkan level dari node X yang merupakan salah satu node dari pohon biner P */
/* Akar(P) level-nya adalah 1. Pohon P tidak kosong dan elemen-elemennya unik.*/

int depth(BinTree p);
/* Mengirimkan maksimum level suatu pohon biner p */

int Max(int a, int b);
/* Mengembalikan nilai terbesar antara a dan b */

boolean searchTreeNode(BinTree p, ElType X);
/* Mengirimkan true jika ada node dari P yang bernilai X */
/* Basis 0 */

boolean searchBaseOne(BinTree p, ElType X);
/* Mengirimkan true jika ada node dari P yang bernilai X */
/* Basis 1 */

boolean isLeaf(BinTree p, ElType X);
/* Mengembalikan true jika X adalah daun dari pohon biner p */
/* X pasti ada di pohon biner P */

void addLeaf(BinTree *p, ElType X, ElType Y, boolean Left);
/* I.S. P tidak kosong, X adalah daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri), atau
sebagai anak Kanan X (jika not Kiri). Jika ada lebih dari satu daun bernilai
X, Y ditambahkan pada daun paling kiri. */

BinTree treeLocation(BinTree p, ElType X);

#endif