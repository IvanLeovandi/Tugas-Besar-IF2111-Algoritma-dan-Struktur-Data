/* File playgame.c */
#include <stdio.h>
#include "playgame.h"

void playgame(Queue *game, Array array_game, ArraySet *nama_pemain, ArrayMap *scoreboard_game, StackHis *history)
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
            printf("Loading %s ", val);
            loadingDelay();
            printf("\n");
            rng(&score);
            PushHis(history, val);
        } else if(compareSTR(val, "Diner DASH"))
        {
            printf("Loading %s ", val);
            loadingDelay();
            printf("\n");
            DinerDash(&score);
            PushHis(history, val);
        } 
        // else if(compareSTR(val, "DINOSAUR IN EARTH") || compareSTR(val, "RISEWOMAN") || compareSTR(val, "EIFFEL TOWER"))
        // {
        //     printf("Game %s masih dalam maintenance, belum dapat dimainkan.\n", val);
        //     printf("Silahkan pilih game lain.\n");
        // } 
        else if(compareSTR(val, "RPS"))
        {
            printf("Loading %s ", val);
            loadingDelay();
            printf("\n");
            Start_RPS(&score);
            PushHis(history, val);
        } else if(compareSTR(val, "HANGMAN"))
        {
            printf("Loading %s ", val);
            loadingDelay();
            printf("\n");
            Hangman(&score);
            PushHis(history, val);
        } else if(compareSTR(val, "TOWER OF HANOI"))
        {
            printf("Loading %s ", val);
            loadingDelay();
            printf("\n");
            towerOfHanoi(&score);
            PushHis(history, val);
        } else if(compareSTR(val, "SNAKE ON METEOR"))
        {
            printf("Loading %s ", val);
            loadingDelay();
            printf("\n");
            SnakeOnMeteor(&score);
            PushHis(history, val);
        } else if(compareSTR(val, "GUESSING NUMBER"))
        {
            printf("Loading %s ", val);
            loadingDelay();
            printf("\n");
            guess_number(&score);
            PushHis(history, val);
        }
        else
        {
            game_buatan(val,&score);
            PushHis(history, val);
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
        printf("Masukkan nama kamu: ");
        nama = Input();
        while (check_nama(nama,(*nama_pemain).TISet[idx]))
        {
            printf("Nama telah dipakai, mohon masukan nama yang lain.\n");
            printf("Masukkan nama kamu: ");
            nama = Input();
        }
        add_to_scoreboard(&((*scoreboard_game).TIMap[idx]),&((*nama_pemain).TISet[idx]),nama,score);
    }
}