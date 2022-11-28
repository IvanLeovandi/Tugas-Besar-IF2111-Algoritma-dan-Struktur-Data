#ifndef map_H
#define map_H
#include <stdio.h>
#include "../../boolean.h"

/* MODUL Map
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1

#define NilMap 0
#define MaxElMap 10
#define Undefined -999
#define IdxMaxMap 100
#define IdxMinMap 1

// typedef int bool;
typedef char* keytype;
typedef int valuetype;

typedef struct {
	keytype Key;
	valuetype Value;
} infotype;

typedef struct {
	infotype ElementsMap[MaxElMap];
	int CountMap;
} Map;

typedef struct
	{
		Map TIMap [IdxMaxMap-IdxMinMap+1]; /* memori tempat penyimpan elemen (container) */
		int NeffMap; /* banyaknya elemen efektif */
	} ArrayMap;

/* Definisi Map M kosong : M.CountMap = Nil */
/* M.CountMap = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyMap(Map *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxElMap */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(Map M);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFullMap(Map M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxElMap */

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void InsertMap(Map *M, keytype k, valuetype v);
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void DeleteMap(Map *M, keytype k);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMemberMap(Map M, keytype k);
/* Mengembalikan true jika k adalah member dari M */

void MakeEmptyArrMap (ArrayMap *T);
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMaxMap-IdxMinMap+1 */

int NbElmtArrMap (ArrayMap T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */

void SetElArrMap (ArrayMap *T, int i, Map v);
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen array yang ke-i dengan set v*/

void SetNeffArrMap (ArrayMap *T, int N);
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

void DelArrMap (ArrayMap *T, int i);
/* I.S. T Terdefinisi, sembarang*/
/* F.S. Set T pada index i akan dihapus*/

#endif
