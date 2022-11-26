/* File : stackhistory.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef STACKHIS_H
#define STACKHIS_H

#include "../../boolean.h"

#define NilHis -1
#define MaxHis 100
/* Nil adalah stack dengan elemen kosong . */

typedef char *infotypeHis;
typedef int address;   /* indeks tabel */

/* Contoh deklarasi variabel bertype StackHis dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct { 
  infotypeHis T[MaxHis]; /* tabel penyimpan elemen */
  address TOP;  /* alamat TOP: elemen puncak */
} StackHis;
/* Definisi StackHis S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai StackHis T[0]..T[MaxEl-1] */
/* Jika S adalah StackHis maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStackHis(StackHis *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah StackHis S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri StackHis kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStackHis(StackHis S);
/* Mengirim true jika StackHis kosong: lihat definisi di atas */
boolean IsFullStackHis(StackHis S);
/* Mengirim true jika tabel penampung nilai elemen StackHis penuh */

/* ************ Menambahkan sebuah elemen ke StackHis ************ */
void PushHis(StackHis * S, infotypeHis X);
/* Menambahkan X sebagai elemen StackHis S. */
/* I.S. S mungkin kosong, tabel penampung elemen StackHis TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen StackHis ************ */
void PopHis(StackHis * S, infotypeHis * X);
/* Menghapus X dari StackHis S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void InversStackHis(StackHis *S);
/* Membalikkan StackHis S */
/* I.S. S terdefinisi */
/* F.S. Urutan elemen pada S menjadi terbalik */

void TulisStackHis(StackHis S);
/* Menuliskan seluruh elemen StackHis S ke layar */

StackHis CopyStackHis(StackHis *S);
/* Mengembalikan hasil salinan S */

#endif