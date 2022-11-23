/* File : Snakelinier.h */
/* contoh ADT Snake berkait dengan representasi fisik pointer  */
/* Representasi adrSnake dengan pointer */
/* int adalah integer */

#include <stdio.h>
#include <stdlib.h>
#include "../../boolean.h"

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

/* PROTOTYPE */
/****************** TEST Snake KOSONG ******************/
boolean IsEmpty (snakeList L);
/* Mengirim true jika Snake kosong */

/****************** PEMBUATAN Snake KOSONG ******************/
void CreateEmpty (snakeList *L);

void CreatePeta (snakeList *L, point* food);

void InsertSnake (snakeList*L);

/* I.S. sembarang             */
/* F.S. Terbentuk Snake kosong */

/****************** Manajemen Memori ******************/
adrSnake AlokasiSnake (int X, int Y, char prev);

point NewPoint (snakeList L);

/* Mengirimkan adrSnake hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka adrSnake tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void DealokasiSnake (adrSnake *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian adrSnake P */

/****************** PENCARIAN SEBUAH ELEMEN Snake ******************/
adrSnake Search (snakeList L, int X, int Y);
/* Mencari apakah ada elemen Snake dengan info(P)= X */
/* Jika ada, mengirimkan adrSnake elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */


/****************** PROSES SEMUA ELEMEN Snake ******************/

/* I.S. Snake mungkin kosong */
/* F.S. Jika Snake tidak kosong, iai Snake dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Snake kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int SnakeScore (snakeList L);
/* Mengirimkan banyaknya elemen Snake mengirimkan 0 jika Snake kosong */

void PrintSnake(snakeList L, point food, point meteor);

void PrintGaris();

#endif