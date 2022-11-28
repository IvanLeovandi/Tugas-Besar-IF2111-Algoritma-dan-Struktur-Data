#include "../adt/map/map.h"
#include "../adt/set/set.h"
#include "../adt/Array/array.h"
#include "../adt/Mesin/mesinkata.h"
#include "../boolean.h"

#ifndef scoreboard_H
#define scoreboard_H

void AddSet(ArraySet *nama_user);
/*I.S. Array Set Terdefinisi, ArraySet Mungkin Kosong*/
/*F.S. Array Set bertambah 1 Set pada elemen belakang array*/

void AddScoreboard (ArrayMap *scoreboard_game);
/*I.S. Array Map Terdefinisi, ArrayMap Mungkin Kosong*/
/*F.S. Array Map bertambah 1 Map pada elemen belakang array*/

void CreateScoreboard(ArraySet *nama_user, ArrayMap *scoreboard_game, Array array_game);
/*I.S. Sembarang*/
/*F.S. Terbentuk sebuah scoreboard yang terdiri dari jumlah array_game*/

boolean check_nama (char *nama, Set nama_pemain);
/*I.S. Set nama_pemain terdefinisi, string nama terdefinisi*/
/*F.S. Mengembalikan true jika nama tidak terdapat dalam nama_pemain*/

void add_to_scoreboard(Map *scoreboard, Set *list_name, char* nama,int score);
/*I.S. Map scoreboard terdefinisi, Set list_name terdefinisi, nama dan score terdefinisi*/
/*     scoreboard dan list_name mungkin kosong*/
/*F.S Scoreboard bertambah 1 elemen dengan Key Nama dan Value Score*/
/*    list_name bertambah 1 elemen nama*/

int len_name (char* nama);
/*I.S. nama terdefinisi*/
/*F.S. Mengembalikan panjang dari nama*/

int len_score (int score);
/*I.S. score terdefinisi*/
/*F.S. Mengembalikan jumlah digit score*/

int longest_score(Map scoreboard_game);
/*I.S. Map scoreboard_game terdefinisi*/
/*F.S. Mengembalikan jumlah digit score tertinggi yang terdapat dalam scoreboard_game*/

int longest_name(Map scoreboard_game);
/*I.S. Map scoreboard_game terdefinisi*/
/*F.S. Mengembalikan jumla huruf nama terpanjang yang terdapat dalam scoreboard_game*/

void PrintSpace (int n);
/*I.S. n terdefinisi*/
/*F.S. " " dicetak ke layar sejumlah n*/

void DisplayScoreboard(ArrayMap scoreboard_game, Array arraygame);
/*I.S. ArrayMap scoreboard game terdefinisi, Array arraygame terdefinisi*/
/*F.S. Scoreboard setiap game tercetak ke layar*/

void DeleteScoreboard(ArrayMap *scoreboard_game, ArraySet *nama_pemain, Array array_game);
/*I.S. ArrayMap scoreboard game terdefinisi, Array array_game terdefinisi, ArraySet nama pemain terdefinisi*/
/*F.S.  Scoreboard game yang terpilih akan dibuat menjadi kosong*/

#endif