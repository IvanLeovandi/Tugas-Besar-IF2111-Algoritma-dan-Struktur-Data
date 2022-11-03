#include "adt/array.h"
#include "adt/mesinkarakter.h"
#include "adt/mesinkata.h"
#include "load.h"
#include <stdio.h>
#include <stdlib.h>

static FILE * tape;

void load(Array *array_game, char *filename){
 
    boolean EndWord;
    Word currentWord;

    // Buka file
    tape = fopen(filename, "r");
 
    STARTWORD();

    int n = GetCC() - '0';

    for (int i=0; i<n; i++){
        ADVWORD();
        array_game->TI[i] = currentWord.TabWord;
        array_game->Neff++;
    }

    fclose(tape);
    
}

int main()
{
    Array a;
    MakeEmpty(&a);
    load(&a, "../data/config.txt");

    TulisIsi(a);

    return 0;

}