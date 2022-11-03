/* File load.c */
#include "adt/array.h"
#include "adt/mesinkarakter.h"
#include "adt/mesinkata.h"
#include "load.h"

#include <stdio.h>
#include <stdlib.h>

static FILE *tape;
static int retval;

void load(Array *array_game, char *filename) {
/* Membaca isi file "filename" dan memasukkannya ke dalam array_game */
    /* KAMUS LOKAL */
    int i, j, n;
    /* ALGORITMA */
    /* Buka file */
    tape = fopen(filename, "r");

    ADVLOAD();
    n = currentChar - '0';
    ADVLOAD();

    for (i = 0; i < n; i++) {
        ADVWORDLOAD();
        array_game->TI[i] = currentWord.TabWord;
        /* !!!IMPORTANT
        setiap currentWord.TabWord berubah, array_game->TI nya berubah semua. Masih belum solved
        */

        array_game->Neff++;
        
        /* Membuat currenWord.TabWord menjadi string kosong agar saat dibaca selanjutnya, 
        tidak tertimpa oleh karakter pada currentWord.TabWord sebelumnya
        */
        for (j = 0; j < currentWord.Length; j++) {
            currentWord.TabWord[j] = '\0';
        }
    }

    /* Menutup file */    
    fclose(tape);
}

/* Akan dibuat ADTnya oleh bang Owen. Sementara gini dulu */
void IgnoreBlanksLOAD() {
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    // KAMUS LOKAL
    // ALGORITMA
    while (currentChar == BLANK) {
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
    IgnoreBlanksLOAD();
    if (currentChar == MARK) {
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
    boolean end = false;
    // ALGORITMA
    while ((currentChar != BLANK) && (i < NMax)) {
        currentWord.TabWord[i] = currentChar;
        ADVLOAD();
        i++;
    }
    currentWord.Length = i;
}

void ADVLOAD() {
	retval = fscanf(tape,"%c",&currentChar);
	EOP = (currentChar == MARK);
	if (EOP) {
       fclose(tape);
 	}
}

// int main()
// {
//     Array a;
//     MakeEmpty(&a);
//     load(&a, "../data/config.txt");

//     // printf("Neff: %d\n", a.Neff);
//     // printf("%s\n", a.TI[0]);

//     // TulisIsi(a);

//     return 0;

// }