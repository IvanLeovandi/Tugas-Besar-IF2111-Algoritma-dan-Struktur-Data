/* File playgame.c */
#include <stdio.h>
#include "playgame.h"
#include "../LISTGAME/listgame.h"
#include "../RNG/rng.h"
#include "../DINERDASH/dinerdash.h"
#include "../GAMEBUATAN/game.h"
#include "../BONUSGAME/RPS.h"

void playgame(Queue *game)
/* 
I.S.: menerima input queue game 
F.S.: melakukan dequeue dan menyimpan hasil elemen yang baru dihapus di dalam name
*/
{
    ElType val;
    printf("Berikut adalah daftar Game-mu\n");
    displayQueue(*game);
    if(isEmpty(*game))
    {
        printf("Silahkan tambahkan game ke antrian terlebih dahulu.\n");
    }
    else 
    {
        dequeue(game, &val);
        if(compareSTR(val, "RNG"))
        {
            printf("Loading... %s\n", val);
            rng();
        } else if(compareSTR(val, "Diner DASH"))
        {
            printf("Loading... %s\n", val);
            DinerDash();
        } 
        else if(compareSTR(val, "DINOSAUR IN EARTH") || compareSTR(val, "RISEWOMAN") || compareSTR(val, "EIFFEL TOWER"))
        {
            printf("Game %s masih dalam maintenance, belum dapat dimainkan.\n", val);
            printf("Silahkan pilih game lain.\n");
        } else if(compareSTR(val, "RPS"))
        {
            printf("Loading... %s\n", val);
            Start_RPS();
        }
        else
        {
            game_buatan(val);
        }
    }
}