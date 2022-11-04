#include <stdio.h>
#include "adt/array.h"
#include "start.h"


void STARTGAME(Array *array_game)
{
    load(array_game, "../data/config.txt");
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.");
}