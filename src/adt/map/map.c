#include "map.h"
#include <stdio.h>

/* *** Konstruktor/Kreator *** */
void CreateEmptyMap(Map *M)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */
{
	(*M).Count = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(Map M)
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */
{
	return M.Count == Nil;
}

boolean IsFullMap(Map M)
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */
{
	return M.Count == MaxEl;
}

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k)
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */
{
	if (IsMember(M,k))
	{
		int idx=0;
		while (M.Elements[idx].Key != k)
		{
			idx++;
		}
		return M.Elements[idx].Value;
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
	if (IsEmpty(*M))
	{
		(*M).Count = 1;
		(*M).Elements[0].Key = k;
		(*M).Elements[0].Value = v;
	}
	else
	{
		if (! IsMember((*M),k))
		{
			(*M).Elements[(*M).Count].Key = k;
			(*M).Elements[(*M).Count].Value = v;
			(*M).Count++;
		}
	}
}

void DeleteMap(Map *M, keytype k)
/* Menghapus Elmt dari Map M. */
{
	int idx;
	idx = 0;
	if (IsMember((*M),k))
	{
		while ((*M).Elements[idx].Key != k)
		{
			idx++;
		}
		for (idx;idx<(*M).Count-1;idx++)
		{
			(*M).Elements[idx] = (*M).Elements[idx+1];
		}
		(*M).Count--;
	}
}

boolean IsMemberMap(Map M, keytype k)
/* Mengembalikan true jika k adalah member dari M */
{
	int i;
	i = 0;
	boolean ada;
	ada = false;
	while (i < M.Count && ada == false)
	{
		if (M.Elements[i].Key == k)
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
    T->Neff = 0;
}

int NbElmtArrMap (ArrayMap T) {
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
    // KAMUS LOKAL
    // ALGORITMA
    return T.Neff;
}

void SetElArrMap (ArrayMap *T, IdxType i, ElType v) {
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
    // KAMUS LOKAL
    // ALGORITMA
    T->TI[i] = v;
    if (i > T->Neff) {
        T->Neff = i;
    }
}

void SetNeffArrMap (Array *T, IdxType N) {
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
    // KAMUS LOKAL
    // ALGORITMA
    T->Neff = N;
}

void DelArrMap (ArrayMap *T, IdxType i) {
/* I.S. T Terdefinisi, sembarang*/
/* F.S. Set T pada index i akan dihapus*/
	for (i;i<(*T).Neff;i++)
	{
		(*T).TI[i] = (*T).TI[i+1];
	}
	(*T).Neff--;
}
