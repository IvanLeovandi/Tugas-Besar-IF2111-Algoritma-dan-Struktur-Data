#include <stdio.h>
#include "start.h"

void STARTGAME(Array *array_game, StackHis *history, ArraySet *list_name, ArrayMap *scoreboard, boolean isStart)
{

/*
I.S. Array array_game terdefinisi, Array array_game kosong;
F.S. Array array_game terisi dengan game yang berada pada file config.txt
*/
    load(array_game, history, list_name, scoreboard, "../data/config.txt", isStart);
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
}