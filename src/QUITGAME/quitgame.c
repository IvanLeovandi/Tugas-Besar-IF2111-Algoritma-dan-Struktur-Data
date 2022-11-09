#include <stdio.h>
#include "quitgame.h"

void quitgame(Queue *queue_game)
/*
I.S : Queue queue_game terdefinisi
F.S : Queue queue_game menjadi kosong dan keluar dari program
*/
{
    printf("Anda keluar dari game BNMO\n");
    printf("Bye bye ...\n");
    CreateQueue(queue_game);
}