#include <stdio.h>
#include <stdlib.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;
static FILE *tape;
static int retval;

void START(){
    tape = stdin;
    ADV();
}
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void ADV(){
	retval = fscanf(tape,"%c",&currentChar);
}
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

char GetCC(){
    return(currentChar);
}
/* Mengirimkan currentChar */

boolean IsEOP(){
    return(currentChar==MARK);
}
/* Mengirimkan true jika currentChar = MARK */
