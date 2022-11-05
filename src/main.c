#include "main.h"
#include "./adt/Array/array.h"
#include "./adt/Mesin/mesinkarakter.h"
#include "./adt/Mesin/mesinkata.h"
#include "./adt/Queue/queue.h"
#include "./STARTGAME/start.h"
#include "./LISTGAME/listgame.h"
#include "./HELP/help.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Selamat datang di BNMO.\n");
    printf("Silahkan pilih menu START atau LOAD untuk memulai program\n\n");
    printf("ENTER COMMAND: ");
    // STARTWORD();
    // char *command = KataToSTR(currentWord);
    char *command = Input();
    printf("--------------------------\n");
    boolean end = false;
    boolean loaded = false;
    Array array_game;
    MakeEmpty(&array_game);
    Queue queue_game;
    if (compareSTR(command, "START"))
    {
        STARTGAME(&array_game);
        int i;
        for(i = 0; i < array_game.Neff; i++)
        printf("%s\n", array_game.TI[i]);
        loaded = true;
    } 
    // else if(compareSTR(command, "LOAD")) // --> ADVWORD buat ngambil nama file
    // {
    //     ADVWORD();
    //     char *filename = KataToSTR(currentWord);
    //     load(&array_game, filename);
    //     loaded = true;
    // }
    while(loaded && !end)
    {
        printf("\nENTER COMMAND: ");
        command = Input();
        printf("--------------------------\n");
        // if(compareSTR(command, "CREATEGAME"))
        // {
            
        // }
        // else 
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
            printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
        }
    }
    return 0;
}