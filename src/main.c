#include "main.h"
#include "./adt/Array/array.h"
#include "./adt/Mesin/mesinkarakter.h"
#include "./adt/Mesin/mesinkata.h"
#include "./adt/Queue/queue.h"
#include "./STARTGAME/start.h"
#include "./LISTGAME/listgame.h"
#include "./HELP/help.h"
#include "./COMMANDLAIN/commandlain.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // inisialisasi variabel
    boolean end = false, loaded = false;
    char *command, *secondCommand;
    Array array_game; MakeEmpty(&array_game);
    Queue queue_game;

    // Memulai program
    printf("Selamat datang di BNMO.\n");
    printf("Silahkan pilih menu START atau LOAD untuk memulai program\n\n");
    while(!loaded)
    {
        printf("ENTER COMMAND: ");
        command = Input();
        printf("--------------------------\n");
        if(count_space(command) == 0)
        {
            if (compareSTR(command, "START"))
            {
                STARTGAME(&array_game);
                int i;
                for(i = 0; i < array_game.Neff; i++)
                {
                    printf("%s\n", array_game.TI[i]);
                }
                loaded = true;
            } else
            {
                command_lain();
            }
        } else if(count_space(command) == 1)
        {
            char *firstSTR = FirstSTR(command);
            char *secSTR = SecSTR(command);
            printf("%s\n", secSTR);
            if(compareSTR(firstSTR,"LOAD"))
            {
                load(&array_game, secSTR);
                int i;
                printf("%d", array_game.Neff);
                for(i = 0; i < array_game.Neff; i++)
                {
                    printf("%s\n", array_game.TI[i]);
                }
                loaded = true;
            } else
            {
                command_lain;
            }
        } else
        {
            command_lain();
        }
    }
    // else if(count_space(command) == 1)
    // {
    //     if(compareSTR(command,))
    // }
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
        if(count_space(command) > 1)
        {
            command_lain();
        } else
        {
            if(compareSTR(command, "LIST GAME"))
            {
                listgame(array_game);
            } else if(compareSTR(command, "HELP"))
            {
                help();
            } else if(compareSTR(command, "QUIT"))
            {
                printf("Terima kasih");
                end = true;
            } else
            {
                command_lain();
            }
        }
    }
    return 0;
}