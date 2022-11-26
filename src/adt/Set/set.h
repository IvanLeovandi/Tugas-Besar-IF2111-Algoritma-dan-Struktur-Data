#ifndef set_H
#define set_H
#include <stdio.h>
#include "../../boolean.h"

/* MODUL Set
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

#define NilSet 0
#define MaxElSet 100
#define IdxMaxSet 100
#define IdxMinSet 1

typedef int address;

typedef struct
{
    char* Elements[MaxElSet];
    address CountSet;
} Set;

typedef struct
{
        Set TISet [IdxMaxSet-IdxMinSet+1]; /* memori tempat penyimpan elemen (container) */
	int NeffSet; /* banyaknya elemen efektif */
} ArraySet;

/* Definisi Set S kosong : S.Count = Nil */
/* S.Count = jumlah element Set */
/* S.Elements = tempat penyimpanan element Set */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptySet(Set *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySet(Set S);
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsFullSet(Set S);
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

/* ********** Operator Dasar Set ********* */
void InsertSet(Set *S, char* Elmt);
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void DeleteSet(Set *S, char* Elmt);
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMemberSet(Set S, char* Elmt);
/* Mengembalikan true jika Elmt adalah member dari S */

void MakeEmptyArrSet (ArraySet *T);
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

int NbElmtArrSet (ArraySet T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */

void SetElArrSet (ArraySet *T, int i, Set v);
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen array yang ke-i dengan set v*/

void SetNeffArrSet (ArraySet *T, int N);
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

void DelArrSet (ArraySet *T, int i);
/* I.S. T Terdefinisi, sembarang*/
/* F.S. Set T pada index i akan dihapus*/



#endif