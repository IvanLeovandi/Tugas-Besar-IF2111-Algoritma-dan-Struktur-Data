#include "loader.h"
#include <stdio.h>
#include <stdlib.h>

boolean StartLOAD(char *filename)
{
    tape = fopen(filename, "r");
    if(tape != NULL)
    {
        ADVWORDLOAD();
        return true;
    } else
    {
        return false;
    }
}

void IgnoreNewLine() {
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    // KAMUS LOKAL
    // ALGORITMA
    while (currentChar == MARK || currentChar == 13) { /* ascii 13 == \r (carriage return) */
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
    while ((currentChar != MARK && currentChar != 13) && i < NMax && !EOP) { /* ascii 13 == \r (carriage return) */
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