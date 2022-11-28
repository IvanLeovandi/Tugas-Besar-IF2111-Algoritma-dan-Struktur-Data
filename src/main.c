#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // inisialisasi variabel
    boolean end = false, loaded = false;
    char *command, *secondCommand;
    Array array_game; MakeEmpty(&array_game);
    Queue queue_game; CreateQueue(&queue_game);
    StackHis history; CreateEmptyStackHis(&history);
    ArraySet list_name; MakeEmptyArrSet(&list_name);
    ArrayMap scoreboard; MakeEmptyArrMap(&scoreboard); CreateScoreboard(&list_name, &scoreboard, array_game);

    srand(time(NULL));

    // Memulai program
    ClearScreen();
    printf("  _______   ___   __    ___ __ __   ______      \n");
    printf("/_______/\\ /__/\\ /__/\\ /__//_//_/\\ /_____/\\     \n");
    printf("\\::: _  \\ \\\\::\\_\\\\  \\ \\\\::\\| \\| \\ \\\\:::_ \\ \\    \n");
    printf(" \\::(_)  \\/_\\:. `-\\  \\ \\\\:.      \\ \\\\:\\ \\ \\ \\   \n");
    printf("  \\::  _  \\ \\\\:. _    \\ \\\\:.\\-/\\  \\ \\\\:\\ \\ \\ \\  \n");
    printf("   \\::(_)  \\ \\\\. \\`-\\  \\ \\\\. \\  \\  \\ \\\\:\\_\\ \\ \\ \n");
    printf("    \\_______\\/ \\__\\/ \\__\\/ \\__\\/ \\__\\/ \\_____\\/ \n\n\n");

    printf("____ _  _     ____ _  _ ___ ____ _____ \n");
    printf("(  _ ( \\/ ()  (_  _( \\( / __( ___(  _  )\n");
    printf(" ) _ <\\  /     _)(_ )  ( (_-.)__) )(_)( \n");
    printf("(____/(__)()  (____(_)\\_\\___(__) (_____)\n\n");

    for (int i = 0; i < 48; i++) {
        printf("-");
    }
    printf("\n\n");

    printf("Selamat datang di BNMO.\n");
    printf("Silahkan pilih menu START atau LOAD untuk memulai program.\n");
    while(!loaded && !end)
    {
        printf("\nENTER COMMAND: ");
        command = Input();
        ClearScreen();

        printf("ENTER COMMAND: %s\n", command);
        printf("--------------------------\n");
        if(count_space(command) == 0)
        {
            if (compareSTR(command, "START"))
            {
                STARTGAME(&array_game, &history, &list_name, &scoreboard);
                loaded = true;
            } else if (compareSTR(command, "QUIT"))
            {
                quitgame(&queue_game);
                end = true;
            } else if(compareSTR(command, "HELP"))
            {
                help(loaded);
            } else
            {
                command_lain();
            }
        } else if(count_space(command) == 1)
        {
            char *firstSTR = FirstSTR(command);
            char *secSTR = SecSTR(command);
            if(compareSTR(firstSTR,"LOAD"))
            {
                load(&array_game, &history, &list_name, &scoreboard, secSTR);
                if(array_game.Neff != 0)
                {
                    loaded = true;
                }
            } else
            {
                command_lain();
            }
        } else
        {
            command_lain();
        }
    }

    while(loaded && !end)
    {
        printf("\nENTER COMMAND: ");
        command = Input();
        
        ClearScreen();

        printf("ENTER COMMAND: %s\n", command);
        printf("--------------------------\n");
        if(count_space(command) > 1)
        {
            command_lain();
        } else
        {
            if(compareSTR(command, "CREATE GAME"))
            {
                creategame(&array_game);
            }
            else if(compareSTR(command, "LIST GAME"))
            {
                listgame(array_game);
            } else if(compareSTR(command, "DELETE GAME"))
            {
                deletegame(&array_game, queue_game);
            } else if(compareSTR(command, "QUEUE GAME"))
            {
                queuegame(&queue_game, array_game);
            } else if(compareSTR(command, "PLAY GAME"))
            {
                playgame(&queue_game, array_game, &list_name, &scoreboard);
            } else if(count_space(command) == 1)
            {
                char *firstSTR = FirstSTR(command);
                char *secSTR = SecSTR(command);
                if(compareSTR(firstSTR,"SKIPGAME"))
                {
                    int skip_num = StrToInt(secSTR);
                    skipgame(&queue_game, array_game, &list_name, &scoreboard,skip_num);
                } else if(compareSTR(firstSTR, "SAVE"))
                {
                    save(secSTR, array_game, history, scoreboard);
                }
                else
                {
                    command_lain();
                }
            }
            else if(compareSTR(command, "HISTORY"))
            {
                if(IsEmptyStackHis)
                {
                    printf("Tidak ada history.\n");
                } else
                {
                    TulisStackHis(&history);
                }
            }
            else if(compareSTR(command, "SCORE"))
            {
                DisplayScoreboard(scoreboard, array_game);
            }
            else if(compareSTR(command, "HELP"))
            {
                help(loaded);
            } else if(compareSTR(command, "QUIT"))
            {
                quitgame(&queue_game);
                end = true;
            } else
            {
                command_lain();
            }
        }
    }
    return 0;
}
