#include "main.h"
#include "adt/array.h"
#include "adt/mesinkarakter.h"
#include "adt/mesinkata.h"
#include "adt/queue.h"
#include "start.h"
#include "listgame.h"
#include "help.h"


#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Selamat datang di BNMO.\n");
    printf("Silahkan pilih menu START atau LOAD untuk memulai program\n");
    printf("ENTER COMMAND: ");
    // STARTWORD();
    // char *command = KataToSTR(currentWord);
    char *command = STARTINPUT();
    boolean end = false;
    boolean loaded = false;
    Array array_game;
    MakeEmpty(&array_game);
    Queue queue_game;
    if(compareSTR(command, "START"))
    {
        STARTGAME(&array_game);
        int i;
        for(i = 0; i < array_game.Neff; i++)
        printf("%s\n", array_game.TI[i]);
        loaded = true;
    } // load --> ADVWORD buat ngambil nama file
    
    while(loaded && !end)
    {
        printf("ENTER COMMAND: ");
        command = STARTINPUT();
        if(compareSTR(command, "LISTGAME"))
        {
            listgame(array_game);
        }
        else if(compareSTR(command, "HELP"))
        {
            help();
        } else if(compareSTR(command, "QUIT"))
        {
            printf("Terima kasih");
            end = true;
        } 
        else
        {
            printf("Command tidak dikenali, silahkan masukkan command yang valid.");
            printf("ENTER COMMAND: ");
        }
    }
    return 0;
}