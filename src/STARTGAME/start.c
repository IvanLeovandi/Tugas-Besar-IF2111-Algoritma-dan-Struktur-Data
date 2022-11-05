#include <stdio.h>
#include "../adt/Array/array.h"
#include "start.h"
#include "../LOAD/load.h"


void STARTGAME(Array *array_game)
{

/*
I.S. Array array_game terdefinisi, Array array_game kosong;
F.S. Array array_game terisi dengan game yang berada pada file config.txt
*/
    load(array_game, "../data/config.txt");
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
}