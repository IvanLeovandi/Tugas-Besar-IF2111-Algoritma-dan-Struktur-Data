/* File towerofhanoi.h */
#include "../adt/Stack/stack.h"
#include "../adt/Mesin/mesinkata.h"
#include "../clear.h"
#include "../delay.h"

#ifndef TOWER_OF_HANOI_H
#define TOWER_OF_HANOI_H

void towerOfHanoi(int *score_game);
/*
Spesifikasi game: seluruh piringan harus dipindahkan ke tiang C dengan
posisi yang sama (piringan paling bawah merupakan piringan yang paling besar
dan piringan paling atas merupakan piringan yang paling kecil), dengan
peraturannya adalah piringan yang di bawah tidak boleh lebih kecil daripada
piringan yang ada di atasnya.
*/

void Tulis3Stack(Stack *StackA, Stack *StackB, Stack *StackC, int piringan);
/* Menulis StackA, StackB, dan StackC ke layar */

char* ConvertToBrick(int num, int max);
/* Mengonversi num ke dalam bentuk bata */

void MoveTop(Stack *awal, Stack *tujuan, int *langkah);
/*
Memindahkan top stack awal ke tujuan
I.S.: Stack awal dan tujuan terdefinisi
F.S.: Top awal berkurang 1, top tujuan bertambah 1
*/

boolean Win(Stack S, int piringan);
/* Mengembalikan true jika kondisi S sudah sesuai dengan kondisi menang */

void TulisBase(Stack S, int max);
/* Menuliskan base ke layar */

void ChangeStackColor(int X);
/* Mengganti warna stack pada Tower of Hanoi */

#endif