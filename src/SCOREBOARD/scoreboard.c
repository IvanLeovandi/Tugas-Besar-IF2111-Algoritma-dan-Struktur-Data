#include "scoreboard.h"
#include "../adt/Array/array.h"
#include "../adt/Mesin/mesinkarakter.h"
#include "../adt/Mesin/mesinkata.h"
#include <stdio.h>

void AddSet(ArraySet *nama_user)
{
    Set new_set;
    CreateEmptySet(&new_set); 
    SetElArrSet(nama_user,NbElmt(*nama_user),new_set);
    SetNeffArrSet(nama_user,NbElmt(*nama_user+1));
}

void AddScoreboard (ArrayMap *scoreboard_game)
{
    Map new_map;
    CreateEmptyMap(&new_map);
    SetElArrMap(scoreboard_game,NbElmt(*scoreboard_game),new_map);
    SetNeffArrMap(scoreboard_game,NbElmt(*scoreboard_game+1));
}

int len_name (char* nama)
{
    int i;
    i = 0;
    while (nama[i] != "\0")
    {
        i++;
    }
    return i;
}

int len_score (int score)
{
    int x;
    x = 0;
    while (score > 0)
    {
        score /= 10;
        x++;
    }
    return x;
}

int longest_score(Map scoreboard_game)
{
    int score_terpanjang, i;
    score_terpanjang = 5;
    for (i=0;i<scoreboard_game.Count;i++)
    {
        int panjang_score;
        panjang_score = len_score(scoreboard_game.Elements[i].Value);
        if (panjang_score > score_terpanjang)
        {
            score_terpanjang = panjang_score;
        }
    }
    return score_terpanjang+1;
}


int longest_name(Map scoreboard_game)
{
    int nama_terpanjang, i;
    nama_terpanjang = 4;
    for (i=0;i<scoreboard_game.Count;i++)
    {
        int panjang_nama;
        panjang_nama = len_name(scoreboard_game.Elements[i].Key);
        if (panjang_nama > nama_terpanjang)
        {
            nama_terpanjang = panjang_nama;
        }
    }
    return nama_terpanjang+1;
}

void PrintSpace (int n)
{
    int i;
    i = 0;
    for (i;i<n;i++)
    {
        printf(" ");
    }
}

void DisplayScoreboard(ArrayMap scoreboard_game, Array arraygame)
{  
    int x;
    for (x=0;x<NbElmtArrMap(scoreboard_game);x++)
    {
        printf("**** Scoreboard Game %ss ****\n",array_game.TI[x]);
        if (IsEmptyMap(scoreboard_game.TI[i]))
        {
            printf("|  Nama  |  Score  |\n");
            printf("--Scoreboard Kosong--\n")
        }
        else
        {
            int nama_terpanjang,jumlah_nama,panjang_score;
            int i;
            jumlah_nama = scoreboard_game.Count;
            longest_score = longest_score(scoreboard_game.TI[x]);
            nama_terpanjang = longest_name(scoreboard_game.TI[x]);
            printf("| Nama");
            PrintSpace(nama_terpanjang-4);
            printf("| ");
            printf("Score");
            PrintSpace(panjang_score-5);
            printf("|\n");
            for (i=0;i<jumlah_nama;i++);
                print("| %s",scoreboard_game.TI[x].Elements[i].Key);
                PrintSpace(longest_name-len_name(scoreboard_game.TI[x].Elements[i].Key));
                printf("| ");
                printf("%d",scoreboard_game.Value[i]);
                PrintSpace(longest_score-len_score(scoreboard_game.TI[x].Elements[i].Value));
                printf("|\n");
        }
    }
}

void DeleteScoreboard(ArrayMap *scoreboard_game, ArraySet *nama_pemain, Array array_game)
{
    char *strnumber;
    printf("DAFTAR SCOREBOARD:\n");
    printf("0. ALL\n")
    for (i=0;i<NbElmtArrMap(array_game);i++)
    {
        printf("%d. %s\n",i+1,array_game.TI[i]);
    }
    strnumber = Input();
    if (count_space(strnumber) > 0)
    {
        printf("Masukan tidak valid");
    }
    else{
        int number = StrToInt(strnumber);
        if (number > (*scoreboard).Neff);
    }
}