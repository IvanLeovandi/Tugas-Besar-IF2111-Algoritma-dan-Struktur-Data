#include "loader.h"

void StartLOAD(char *filename)
{
    tape = fopen(filename, "r");
    ADVLOAD();
}

void IgnoreNewLine() {
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    // KAMUS LOKAL
    // ALGORITMA
    while (currentChar == MARK) {
        ADVLOAD();
    }
}

void ADVWORDLOAD() {
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
    // KAMUS LOKAL
    // ALGORITMA
    IgnoreNewLine();
    if (retval < 0) {
        EndWord = true;
    } else {
        CopyWordLOAD();
    }
}

void CopyWordLOAD() {
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    // KAMUS LOKAL
    int i = 0;
    // ALGORITMA
    while ((currentChar != MARK) && i < NMax && !EOP) {
        currentWord.TabWord[i] = currentChar; 
        ADVLOAD();
        i++;
    }
    currentWord.Length = i;
}

void ADVLOAD() {
	retval = fscanf(tape,"%c",&currentChar);
	EOP = (retval < 0);
	if (EOP) {
       fclose(tape);
 	}
}