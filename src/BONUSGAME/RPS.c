#include <stdio.h>
#include <time.h>
#include "RPS.h"

void Start_RPS(int *score_game)
{
    int n,i, score,angka_bot;
    char *gerakan_pemain;
    char *gerakan_bot;
    boolean valid;
    score = 0;
    i = 1;
    printf("Selamat datang di game Rock Paper Scissor!\n");
    printf("Game akan dimainkan selama 5 ronde\n");
    printf("Score akan diperoleh dengan cara :\n");
    printf("Menang : 20\nSeri : 10\nKalah : 0\n");
    printf("Pemain memberikan masukan 'rock' / 'paper' / 'scissor'\n");
    printf("Input bersifat case sensitive!\n");
    while (i <= 5)
    {
        srand(time(NULL));
        printf("Round %d!\n",i);
        printf("Pilih 'rock' / 'paper' / 'scissor' : ");    
        gerakan_pemain = Input();
        valid = CheckValidInput(gerakan_pemain);
        angka_bot = randomNumberMinMax(1,3); //Untuk menentukan gerakan bot
        if (angka_bot == 1)
        {
            gerakan_bot = "paper";
        }
        else if (angka_bot == 2)
        {
            gerakan_bot = "rock";
        }
        else if (angka_bot == 3)
        {
            gerakan_bot = "scissor";
        }
        if (valid)
        {
            int hasil;
            hasil = CheckHasil(gerakan_pemain,gerakan_bot);
            printf("Bot mengeluarkan %s\n",gerakan_bot);
            if (hasil == 1)
            {
                printf("Ronde %d seri!\n",i);
                score += 10;
            }
            else if (hasil == 2)
            {
                printf("Ronde %d dimenangkan oleh pemain!\n",i);
                score += 20;
            }
            else if (hasil == 0)
            {
                printf("Ronde %d dimenangkan oleh bot!\n",i);
                printf("\n");
            }
            i++;
            printf("\n");
        }
        else
        {
            printf("Tolong berikan input yang valid!\n");
            printf("\n");
        }
    }
    printf("Score anda : %d", score);
    *score_game = score;
}

boolean CheckValidInput(char *gerakan)
{
    return (compareSTR(gerakan,"scissor") || compareSTR(gerakan,"rock") || compareSTR(gerakan,"paper"));
}

int CheckHasil (char* gerakan_pemain, char*gerakan_bot)
{
    if (compareSTR(gerakan_pemain,"scissor"))
    {
        if (compareSTR(gerakan_bot,"rock"))
        {
            return 0;
        }
        else if (compareSTR(gerakan_bot,"scissor"))
        {
            return 1;
        }
        else if (compareSTR(gerakan_bot,"paper"))
        {
            return 2;
        }
    }
    else if (compareSTR(gerakan_pemain,"paper"))
    {
        if (compareSTR(gerakan_bot,"rock"))
        {
            return 2;
        }
        else if (compareSTR(gerakan_bot,"scissor"))
        {
            return 0;
        }
        else if (compareSTR(gerakan_bot,"paper"))
        {
            return 1;
        }   
    }
    else if (compareSTR(gerakan_pemain,"rock"))
    {
        if (compareSTR(gerakan_bot,"rock"))
        {
            return 1;
        }
        else if (compareSTR(gerakan_bot,"scissor"))
        {
            return 2;
        }
        else if (compareSTR(gerakan_bot,"paper"))
        {
            return 0;
        }   
    }
}

void reset_gerakan(char *gerakan)
{  
    gerakan = (char *) malloc (str_len(gerakan) * sizeof (char));
    int i=0;
    for (i;i<str_len(gerakan);i++)
    {
        gerakan[i] = '\0';
    }
}
