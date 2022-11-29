#include "scoreboard.h"
#include "../adt/Array/array.h"
#include "../adt/Mesin/mesinkarakter.h"
#include "../adt/Mesin/mesinkata.h"
#include <stdio.h>

void AddSet(ArraySet *nama_user)
/*I.S. Array Set Terdefinisi, ArraySet Mungkin Kosong*/
/*F.S. Array Set bertambah 1 Set pada elemen belakang array*/
{
    Set new_set;
    CreateEmptySet(&new_set); 
    SetElArrSet(nama_user,NbElmtArrSet(*nama_user),new_set);
    SetNeffArrSet(nama_user,NbElmtArrSet(*nama_user)+1);
}

void AddScoreboard (ArrayMap *scoreboard_game)
{
/*I.S. Array Map Terdefinisi, ArrayMap Mungkin Kosong*/
/*F.S. Array Map bertambah 1 Map pada elemen belakang array*/
    Map new_map;
    CreateEmptyMap(&new_map);
    SetElArrMap(scoreboard_game,NbElmtArrMap((*scoreboard_game)),new_map);
    SetNeffArrMap(scoreboard_game,NbElmtArrMap((*scoreboard_game))+1);
}

void CreateScoreboard(ArraySet *nama_user,ArrayMap *scoreboard_game, Array array_game)
{
/*I.S. Sembarang*/
/*F.S. Terbentuk sebuah scoreboard yang terdiri dari jumlah array_game*/
    int i;
    for (i=0;i<array_game.Neff;i++)
    {
        AddSet(nama_user);
        AddScoreboard(scoreboard_game);
    }
}

boolean check_nama (char *nama, Set nama_pemain)
/*I.S. Set nama_pemain terdefinisi, string nama terdefinisi*/
/*F.S. Mengembalikan true jika nama tidak terdapat dalam nama_pemain*/
{
    int i;
    boolean valid;
    i=0;
    valid = false;
    while (i<nama_pemain.CountSet && !valid)
    {
        valid = compareSTR(nama,nama_pemain.Elements[i]);
        i++;
    }
    return valid;
}

void add_to_scoreboard(Map *scoreboard, Set *list_name, char* nama,int score)
/*I.S. Map scoreboard terdefinisi, Set list_name terdefinisi, nama dan score terdefinisi*/
/*     scoreboard dan list_name mungkin kosong*/
/*F.S Scoreboard bertambah 1 elemen dengan Key Nama dan Value Score*/
/*    list_name bertambah 1 elemen nama*/

{
    InsertMap(scoreboard,nama,score);
    InsertSet(list_name,nama);
}

int len_name (char* nama)
/*I.S. nama terdefinisi*/
/*F.S. Mengembalikan panjang dari nama*/
{
    int i;
    i = 0;
    while (nama[i] != '\0')
    {
        i++;
    }
    return i;
}

int len_score (int score)
/*I.S. score terdefinisi*/
/*F.S. Mengembalikan jumlah digit score*/
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
/*I.S. Map scoreboard_game terdefinisi*/
/*F.S. Mengembalikan jumlah digit score tertinggi yang terdapat dalam scoreboard_game*/
{
    int score_terpanjang, i;
    score_terpanjang = 5;
    for (i=0;i<scoreboard_game.CountMap;i++)
    {
        int panjang_score;
        panjang_score = len_score(scoreboard_game.ElementsMap[i].Value);
        if (panjang_score > score_terpanjang)
        {
            score_terpanjang = panjang_score;
        }
    }
    return score_terpanjang+1;
}


int longest_name(Map scoreboard_game)
/*I.S. Map scoreboard_game terdefinisi*/
/*F.S. Mengembalikan jumla huruf nama terpanjang yang terdapat dalam scoreboard_game*/
{
    int nama_terpanjang, i;
    nama_terpanjang = 4;
    for (i=0;i<scoreboard_game.CountMap;i++)
    {
        int panjang_nama;
        panjang_nama = len_name(scoreboard_game.ElementsMap[i].Key);
        if (panjang_nama > nama_terpanjang)
        {
            nama_terpanjang = panjang_nama;
        }
    }
    return nama_terpanjang+1;
}

void PrintSpace (int n)
/*I.S. n terdefinisi*/
/*F.S. " " dicetak ke layar sejumlah n*/
{
    int i;
    i = 0;
    for (i;i<n;i++)
    {
        printf(" ");
    }
}

void DisplayScoreboard(ArrayMap scoreboard_game, Array arraygame)
/*I.S. ArrayMap scoreboard game terdefinisi, Array arraygame terdefinisi*/
/*F.S. Scoreboard setiap game tercetak ke layar*/
{  
    int x;
    for (x=0;x<NbElmtArrMap(scoreboard_game);x++)
    {
        printf("**** Scoreboard Game %s ****\n",arraygame.TI[x]);
        if (IsEmptyMap(scoreboard_game.TIMap[x]))
        {
            printf("|  Nama  |  Score  |\n");
            printf("--Scoreboard Kosong--\n");
        }
        else
        {
            int nama_terpanjang,jumlah_nama,score_terpanjang;
            int i;
            jumlah_nama = scoreboard_game.TIMap[x].CountMap;
            score_terpanjang = longest_score(scoreboard_game.TIMap[x]);
            nama_terpanjang = longest_name(scoreboard_game.TIMap[x]);
            printf("| Nama");
            PrintSpace(nama_terpanjang-4);
            printf("| ");
            printf("Score");
            PrintSpace(score_terpanjang-5);
            printf("|\n");
            for (i=0;i<jumlah_nama;i++)
            {
                printf("| %s",scoreboard_game.TIMap[x].ElementsMap[i].Key);
                PrintSpace(nama_terpanjang-len_name(scoreboard_game.TIMap[x].ElementsMap[i].Key));
                printf("| ");
                printf("%d",scoreboard_game.TIMap[x].ElementsMap[i].Value);
                PrintSpace(score_terpanjang-len_score(scoreboard_game.TIMap[x].ElementsMap[i].Value));
                printf("|\n");
            }
        }
    }
}

void DeleteScoreboard(ArrayMap *scoreboard_game, ArraySet *nama_pemain, Array array_game)
/*I.S. ArrayMap scoreboard game terdefinisi, Array array_game terdefinisi, ArraySet nama pemain terdefinisi*/
/*F.S.  Scoreboard game yang terpilih akan dibuat menjadi kosong*/
{
    char *strnumber; boolean valid;
    int i;
    printf("DAFTAR SCOREBOARD:\n");
    printf("0. ALL\n");
    for (i=0;i<array_game.Neff;i++)
    {
        printf("%d. %s\n",i+1,array_game.TI[i]);
    }
    printf("Scoreboard yang ingin dihapus: ");
    strnumber = Input();
    if (count_space(strnumber) > 0)
    {
        printf("Masukan tidak valid");
    }
    else
    {
        char* yakin;
        int number = StrToInt(strnumber);
        if (number > (*scoreboard_game).NeffMap || number < 0)
        {
            printf("Tidak ada scoreboard tersebut!");
        }
        else
        { 
            if (number == 0)
            {
                printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ALL?\n");
                printf("YA/TIDAK? ");
                valid = false;
                while (!valid)
                {
                    yakin = Input();
                    if (compareSTR(yakin,"YA"))
                    {
                        for (i=0;i<(*scoreboard_game).NeffMap;i++) 
                        {
                            CreateEmptyMap(&((*scoreboard_game).TIMap[i]));
                            CreateEmptySet(&((*nama_pemain).TISet[i]));
                        }
                        printf("Scoreboard berhasil di-reset.\n");
                        valid = true;
                    } else if (compareSTR(yakin, "TIDAK"))
                    {
                        printf("Scoreboard gagal di-reset\n");
                        valid = true;
                    } else
                    {
                        printf("Masukkan tidak valid, mohon masukkan YA / TIDAK. ");
                    }
                }
            }
            else
            {
                printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD GAME %s\n",array_game.TI[number-1]);
                printf("YA/TIDAK? ");
                valid = false;
                while (!valid)
                {
                    yakin = Input();
                    if (compareSTR(yakin,"YA"))
                    {
                        CreateEmptyMap(&((*scoreboard_game).TIMap[number-1]));
                        CreateEmptySet(&((*nama_pemain).TISet[number-1]));
                        printf("Scoreboard berhasil di-reset.\n");
                        valid = true;
                    } else if (compareSTR(yakin, "TIDAK"))
                    {
                        printf("Scoreboard gagal di-reset.\n");
                        valid = true;
                    } else
                    {
                        printf("Masukkan tidak valid, mohon masukkan YA / TIDAK. ");
                    }
                }
            }
        }
    }
}