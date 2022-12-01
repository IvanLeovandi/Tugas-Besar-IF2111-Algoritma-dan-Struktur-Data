#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./adt/Array/array.h"
#include "./adt/Mesin/mesinkarakter.h"
#include "./adt/Mesin/mesinkata.h"
#include "./adt/Queue/queue.h"
#include "./adt/List/linkedlist.h"
#include "./STARTGAME/start.h"
#include "./SAVE/save.h"
#include "./LOAD/load.h"
#include "./CREATEGAME/creategame.h"
#include "./LISTGAME/listgame.h"
#include "./DELETEGAME/deletegame.h"
#include "./QUEUEGAME/queuegame.h"
#include "./PLAYGAME/playgame.h"
#include "./SKIPGAME/skipgame.h"
#include "./SCOREBOARD/scoreboard.h"
#include "./HISTORY/history.h"
#include "./QUITGAME/quitgame.h"
#include "./HELP/help.h"
#include "./COMMANDLAIN/commandlain.h"
#include "../src/clear.h"
#include "../src/delay.h"
#include "../src/color.h"

int main()
{
    // inisialisasi variabel
    boolean end = false, loaded = false;
    char *command, *secondCommand;
    Array array_game; MakeEmpty(&array_game);
    Queue queue_game; CreateQueue(&queue_game);
    StackHis history; CreateEmptyStackHis(&history);
    ArraySet list_name; MakeEmptyArrSet(&list_name);
    ArrayMap scoreboard; MakeEmptyArrMap(&scoreboard); 

    srand(time(NULL));

    // Memulai program
    ClearScreen();
    RESET;
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
        HITAM;
        BACKGROUND_PUTIH;
        printf("\nENTER COMMAND: ");
        command = Input();
        RESET;
        ClearScreen();

        printf("ENTER COMMAND: %s\n", command);
        printf("--------------------------\n");
        if(count_space(command) == 0)
        {
            if (compareSTR(command, "START"))
            {
                STARTGAME(&array_game, &history, &list_name, &scoreboard, true);
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
                load(&array_game, &history, &list_name, &scoreboard, secSTR, false);
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
        BACKGROUND_PUTIH;
        HITAM;
        printf("\nENTER COMMAND: ");
        command = Input();
        RESET;

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
                creategame(&array_game,&scoreboard,&list_name);
            }
            else if(compareSTR(command, "LIST GAME"))
            {
                listgame(array_game);
            } else if(compareSTR(command, "DELETE GAME"))
            {
                deletegame(&array_game, queue_game,&list_name,&scoreboard);
            } else if(compareSTR(command, "QUEUE GAME"))
            {
                queuegame(&queue_game, array_game);
            } else if(compareSTR(command, "PLAY GAME"))
            {
                playgame(&queue_game, array_game, &list_name, &scoreboard, &history);
            } 
            else if(compareSTR(command, "RESET SCOREBOARD"))
            {
                DeleteScoreboard(&scoreboard, &list_name, array_game);
            }
            else if(compareSTR(command, "RESET HISTORY"))
            {
                if(IsEmptyStackHis(history))
                {
                    printf("History masih kosong, reset gagal dilakukan.\n");
                }
                else
                {
                    reset_hist(&history);
                }
            }
            else if(count_space(command) == 1)
            {
                char *firstSTR = FirstSTR(command);
                char *secSTR = SecSTR(command);
                if(compareSTR(firstSTR,"SKIPGAME"))
                {
                    if(validInt(secSTR))
                    {
                        int skip_num = StrToInt(secSTR);
                        skipgame(&queue_game, array_game, &list_name, &scoreboard, &history, skip_num);
                    }
                    else
                    {
                        printf("Masukkan angka tidak valid.\n");
                    }
                } else if(compareSTR(firstSTR, "SAVE"))
                {
                    save(secSTR, array_game, history, scoreboard);
                } 
                else if(compareSTR(firstSTR , "HISTORY"))
                {
                    int hist_num = StrToInt(secSTR);
                    if(!validInt(secSTR))
                    {
                        printf("Masukkan angka tidak valid.\n");
                    }
                    else
                    {
                        if(IsEmptyStackHis(history))
                        {
                            printf("Belum ada game yang telah dimainkan.\n");
                        } else if(validInt(secSTR))
                        {
                            show_hist(history, hist_num);
                        }
                    }
                }
                else
                {
                    command_lain();
                }
            }
            else if(compareSTR(command, "SCOREBOARD"))
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