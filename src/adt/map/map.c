#include "map.h"
#include <stdio.h>

/* *** Konstruktor/Kreator *** */
void CreateEmptyMap(Map *M)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */
{
	(*M).CountMap = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(Map M)
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */
{
	return M.CountMap == Nil;
}

boolean IsFullMap(Map M)
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */
{
	return M.CountMap == MaxElMap;
}

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k)
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */
{
	if (IsMemberMap(M,k))
	{
		int idx=0;
		while (M.ElementsMap[idx].Key != k)
		{
			idx++;
		}
		return M.ElementsMap[idx].Value;
	}
	else
	{
		return Undefined;
	}
}

void InsertMap(Map *M, keytype k, valuetype v)
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
{
	if (IsEmptyMap(*M))
	{
		(*M).CountMap = 1;
		(*M).ElementsMap[0].Key = k;
		(*M).ElementsMap[0].Value = v;
	}
	else
	{
		if (!IsMemberMap((*M),k))
		{
			int idx,i;
			idx = 0;
			while (v < (*M).ElementsMap[idx].Value)
			{
				idx++;
			}
			(*M).CountMap++;
			for (i=idx;i<(*M).CountMap-1;i++)
			{
				(*M).ElementsMap[i+1].Key = (*M).ElementsMap[i].Key;
				(*M).ElementsMap[i+1].Value = (*M).ElementsMap[i].Value; 
			}
			(*M).ElementsMap[idx].Key = k;
			(*M).ElementsMap[idx].Value = v;
		}
	}
}

void DeleteMap(Map *M, keytype k)
/* Menghapus Elmt dari Map M. */
{
	int idx;
	idx = 0;
	if (IsMemberMap((*M),k))
	{
		while ((*M).ElementsMap[idx].Key != k)
		{
			idx++;
		}
		for (idx;idx<(*M).CountMap-1;idx++)
		{
			(*M).ElementsMap[idx] = (*M).ElementsMap[idx+1];
		}
		(*M).CountMap--;
	}
}

boolean IsMemberMap(Map M, keytype k)
/* Mengembalikan true jika k adalah member dari M */
{
	int i;
	i = 0;
	boolean ada;
	ada = false;
	while (i < M.CountMap && ada == false)
	{
		if (M.ElementsMap[i].Key == k)
		{
			ada = true;
		}
		i++;
	}
	return ada;
}


void MakeEmptyArrMap (ArrayMap *T) {
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
    // KAMUS LOKAL
    // ALGORITMA
    T->NeffMap = 0;
}

int NbElmtArrMap (ArrayMap T) {
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
    // KAMUS LOKAL
    // ALGORITMA
    return T.NeffMap;
}

void SetElArrMap (ArrayMap *T, int i, Map v) {
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
    // KAMUS LOKAL
    // ALGORITMA
    T->TIMap[i] = v;
    if (i > T->NeffMap) {
        T->NeffMap = i;
    }
}

void SetNeffMapArrMap (ArrayMap *T, int N) {
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
    // KAMUS LOKAL
    // ALGORITMA
    T->NeffMap = N;
}

void DelArrMap (ArrayMap *T, int i) {
/* I.S. T Terdefinisi, sembarang*/
/* F.S. Set T pada index i akan dihapus*/
	for (i;i<(*T).NeffMap;i++)
	{
		(*T).TIMap[i] = (*T).TIMap[i+1];
	}
	(*T).NeffMap--;
}
