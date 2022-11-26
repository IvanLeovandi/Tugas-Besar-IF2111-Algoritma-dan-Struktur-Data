#include "set.h"
#include "../Mesin/mesinkarakter.h"
#include "../Mesin/mesinkata.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptySet(Set *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */
{
	(*S).CountSet = NilSet;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySet(Set S)
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */
{
	return S.CountSet == NilSet;
}

boolean IsFullSet(Set S)
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */
{
	return S.CountSet == MaxElSet;
}

/* ********** Operator Dasar Set ********* */
void InsertSet(Set *S,char* Elmt)
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
{
	if (IsEmptySet(*S))
	{
		(*S).CountSet++;
		(*S).Elements[0] = Elmt;
	}
	else
	{
		if (!IsMemberSet((*S),Elmt))
		{
			(*S).CountSet++;
			(*S).Elements[(*S).CountSet-1] = Elmt;
		}
	}
}

void DeleteSet(Set *S,char* Elmt)
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */
{
	int idx;
	idx = 0;
	if (IsMemberSet((*S),Elmt))
	{
		while ((*S).Elements[idx] != Elmt)
		{
			idx++;
		}
		for (idx;idx<(*S).CountSet-1;idx++)
		{
			(*S).Elements[idx] = (*S).Elements[idx+1];
		}
		(*S).CountSet--;
	}
}

boolean IsMemberSet(Set S, char* Elmt)
/* Mengembalikan true jika Elmt adalah member dari S */
{
	int i;
	i = 0;
	boolean ada;
	ada = false;
	while (i < S.CountSet && ada == false)
	{
		if (S.Elements[i] == Elmt)
		{
			ada = true;
		}
		i++;
	}
	return ada;
}

void MakeEmptyArrSet (ArraySet *T) {
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
    // KAMUS LOKAL
    // ALGORITMA
    T->NeffSet = 0;
}

int NbElmtArrSet (ArraySet T) {
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
    // KAMUS LOKAL
    // ALGORITMA
    return T.NeffSet;
}

void SetElArrSet (ArraySet *T, int i, Set v) {
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
    // KAMUS LOKAL
    // ALGORITMA
    T->TISet[i] = v;
    if (i > T->NeffSet) {
        T->NeffSet = i;
    }
}

void SetNeffSetArrSet (ArraySet *T, int N) {
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
    // KAMUS LOKAL
    // ALGORITMA
    T->NeffSet = N;
}

void DelArrSet (ArraySet *T, int i) {
/* I.S. T Terdefinisi, sembarang*/
/* F.S. Set T pada index i akan dihapus*/
	for (i;i<(*T).NeffSet;i++)
	{
		(*T).TISet[i] = (*T).TISet[i+1];
	}
	(*T).NeffSet--;
}