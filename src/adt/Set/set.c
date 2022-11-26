#include "set.h"
#include "../Mesin/mesinkarakter.h"
#include "../Mesin/mesinkata.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptySet(Set *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */
{
	(*S).Count = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySet(Set S)
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */
{
	return S.Count == Nil;
}

boolean IsFullSet(Set S)
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */
{
	return S.Count == MaxEl;
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
		(*S).Count++;
		(*S).Elements[0] = Elmt;
	}
	else
	{
		if (!IsMemberSet((*S),Elmt))
		{
			(*S).Count++;
			(*S).Elements[(*S).Count-1] = Elmt;
		}
	}
}

void DeleteSet(Set *S,infotype Elmt)
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
		for (idx;idx<(*S).Count-1;idx++)
		{
			(*S).Elements[idx] = (*S).Elements[idx+1];
		}
		(*S).Count--;
	}
}

boolean IsMemberSet(Set S, infotype Elmt)
/* Mengembalikan true jika Elmt adalah member dari S */
{
	int i;
	i = 0;
	boolean ada;
	ada = false;
	while (i < S.Count && ada == false)
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
    T->Neff = 0;
}

int NbElmtArrSet (ArraySet T) {
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
    // KAMUS LOKAL
    // ALGORITMA
    return T.Neff;
}

void SetElArrSet (ArraySet *T, IdxType i, ElType v) {
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

void SetNeffArrSet (ArraySet *T, IdxType N) {
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
    // KAMUS LOKAL
    // ALGORITMA
    T->Neff = N;
}

void DelArrSet (ArraySet *T, IdxType i) {
/* I.S. T Terdefinisi, sembarang*/
/* F.S. Set T pada index i akan dihapus*/
	for (i;i<(*T).Neff;i++)
	{
		(*T).TI[i] = (*T).TI[i+1];
	}
	(*T).Neff--;
}