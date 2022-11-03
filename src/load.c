#include "adt/array.h"
#include "adt/mesinkarakter.h"
#include "adt/mesinkata.h"
#include "load.h"

#include <stdio.h>
#include <stdlib.h>

static FILE *tape;
static int retval;

void load(Array *array_game, char *filename){
    // Buka file
    tape = fopen(filename, "r");
    
    // STARTWORD();
    ADVLOAD();
    // printf("cc= %c\n", currentChar);
    int n = currentChar - '0';
    printf("n= %d\n", n);
    ADVLOAD();
    for (int i=0; i<n; i++){

        ADVWORDLOAD();
        // printf("%s\n", currentWord.TabWord);

        array_game->TI[i] = currentWord.TabWord;
        // printf("%d: %s\n", i, array_game->TI[i]);
        array_game->Neff++;

        printf("currenWord.Length: %d\n", currentWord.Length);
        for (int j = 0; j < currentWord.Length; j++) {
            currentWord.TabWord[j] = '\0';
        } /* Ini masih harus pake MARK di config.txt nya, atau isi akhir file ga boleh kosong */
        
    }

    fclose(tape);
    
}

/*AAAAADDDDDTTTTTTT*/
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
        IgnoreBlanksLOAD();
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

int main()
{
    Array a;
    MakeEmpty(&a);
    load(&a, "../data/config.txt");

    // printf("%d\n", a.Neff);

    // TulisIsi(a);

    return 0;

}