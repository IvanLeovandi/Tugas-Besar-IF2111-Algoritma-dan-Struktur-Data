/* File playgame.c */
#include <stdio.h>
#include "playgame.h"
#include "../LISTGAME/listgame.h"
#include "../RNG/rng.h"
#include "../DINERDASH/dinerdash.h"
#include "../GAMEBUATAN/game.h"

/* File ADT*/
#include "../adt/Queue/queue.h"
#include "../adt/Array/array.h"

void playgame(Queue *game, Array array_game)
/* 
I.S.: menerima input queue game 
F.S.: melakukan dequeue dan menyimpan hasil elemen yang baru dihapus di dalam name
*/
{
    ElType val;
    printf("Berikut adalah daftar Game-mu");
    displayQueue(*game);
    dequeue(game, &val);
    if(val == "RNG")
    {
        rng();
    } 
    // else if(val == "Diner DASH")
    // {
    //     main();
    // } 
    else if(val == "DINOSAUR IN EARTH" || val == "RISEWOMAN" || val == "EIFFEL TOWER")
    {
        printf("Game %s masih dalam maintenance, belum dapat dimainkan.\n", val);
        printf("Silahkan pilih game lain.");
    } else
    {
        game_buatan(val);
    }
}