/* File playgame.c */
#include <stdio.h>
#include "playgame.h"
#include "scoreboard.h"

void playgame(Queue *game, Array array_game, ArraySet *nama_pemain, ArrayMap *scoreboard_game)
/* 
I.S.: menerima input queue game 
F.S.: melakukan dequeue dan menyimpan hasil elemen yang baru dihapus di dalam name
*/
{
    ElType val;
    char* nama;
    int score;
    score = 0;
    if(isEmpty(*game))
    {
        printf("Silahkan tambahkan game ke antrian terlebih dahulu.\n");
    }
    else 
    {
        int idx;
        boolean ketemu; 
        idx = 0;
        ketemu= false;
        printf("Berikut adalah daftar Game-mu\n");
        displayQueue(*game);
        dequeue(game, &val);
        if(compareSTR(val, "RNG"))
        {
            printf("Loading %s ...\n", val);
            rng(&score);
        } else if(compareSTR(val, "Diner DASH"))
        {
            printf("Loading %s ...\n", val);
            DinerDash(&score);
        } 
        else if(compareSTR(val, "DINOSAUR IN EARTH") || compareSTR(val, "RISEWOMAN") || compareSTR(val, "EIFFEL TOWER"))
        {
            printf("Game %s masih dalam maintenance, belum dapat dimainkan.\n", val);
            printf("Silahkan pilih game lain.\n");
        } else if(compareSTR(val, "RPS"))
        {
            printf("Loading %s ...\n", val);
            Start_RPS(&score);
        } else if(compareSTR(val, "TOWER OF HANOI"))
        {
            printf("Loading %s ...\n", val);
            towerOfHanoi(&score);
        } else if(compareSTR(val, "SNAKE ON METEOR"))
        {
            printf("Loading %s ...\n", val);
            SnakeOnMeteor(&score);
        } else if(compareSTR(val, "GUESSING NUMBER"))
        {
            printf("Loading %s ...\n", val);
            guess_number(&score);
        }
        else
        {
            game_buatan(val,&score);
        }
        while (!ketemu)
        {
            if (val == array_game.TI[idx])
            {
                ketemu = true;
            }
            else
            {
                idx++;
            }
        }
        nama = Input();
        while (!check_nama(nama,(*nama_pemain).TISet[idx]))
        {
            nama = Input();
        }
        add_to_scoreboard(&((*scoreboard_game).TIMap[idx]),&((*nama_pemain).TISet[idx]),nama,score);
    }
}