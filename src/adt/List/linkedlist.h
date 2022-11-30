/* File : linkedlist.h */
/* contoh ADT snakeList berkait dengan representasi fisik pointer  */
/* Representasi adrSnake dengan pointer */
/* int adalah integer */

#include "../../boolean.h"
#include "../../RNG/random_number.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#define Nil NULL

typedef struct tSnake *adrSnake;

typedef struct
{
	int x;
	int y;
} point;

typedef struct
{
	char prec;
	char succ;
} direction;

typedef struct tSnake
{
	point p;
	direction dir;
	adrSnake next;
} Snake;

typedef struct
{
	adrSnake Head;
	adrSnake Tail;
} snakeList;

/* Definisi Snake : */
#define Point(P) (P)->p
#define Next(P) (P)->next
#define Dir(P) (P)->dir
#define Head(L) ((L).Head)
#define Tail(L) ((L).Tail)

#include "linkedlist.h"

boolean IsSnakeEmpty (snakeList L);
/* Mengirim true jika Snake kosong */

void CreateEmptySnake (snakeList *L);
/* Membuat snake kosong */

adrSnake AlokasiSnake (int X, int Y, char prev);
/* Mengirimkan address hasil alokasi sebuah point bernilai (x, y) */
/* Jika alokasi berhasil, maka address tidak NIL */
/* Jika alokasi gagal, mengirimkan NIL */

point NewPoint (snakeList L, point obstacle);
/* Mengirimkan posisi baru dalam bentuk point (x, y) */

void DealokasiSnake (adrSnake *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */

adrSnake SearchSnake (snakeList L, int X, int Y);
/* Mencari apakah ada elemen Snake dengan info(P)= X */
/* Jika ada, mengirimkan adrSnake elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

int nbSnake (snakeList L);
/* Mengirimkan banyaknya elemen Snake mengirimkan 0 jika Snake kosong */

/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstSnake (snakeList *L, adrSnake P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-adrSnake P sebagai elemen pertama */
void InsertAfterSnake (snakeList *L, adrSnake P, adrSnake Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLastSnake (snakeList *L, adrSnake P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstSnake (snakeList *L, adrSnake *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelPSnake (snakeList *L, point X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beradrSnake P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLastSnake (snakeList *L, adrSnake *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfterSnake (snakeList *L, adrSnake *Pdel, adrSnake Prec);
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

#endif