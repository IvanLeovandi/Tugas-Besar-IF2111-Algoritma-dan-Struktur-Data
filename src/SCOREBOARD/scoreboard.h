#include "../adt/map/map.h"
#include "../adt/set/set.h"
#include "../adt/Array/array.h"
#include "../boolean.h"

#ifndef scoreboard_H
#define scoreboard_H

void AddSet(ArraySet *nama_user);

void AddScoreboard (ArrayMap *scoreboard_game);

void CreateScoreboard(ArraySet *nama_user, ArrayMap *scoreboard_game, Array array);

boolean check_nama (char *nama, Set nama_pemain);

void add_to_scoreboard(Map *scoreboard, Set *list_name, char* nama,int score);

int len_name (char* nama);

int len_score (int score);

int longest_score(Map scoreboard_game);

int longest_name(Map scoreboard_game);

void PrintSpace (int n);

void DisplayScoreboard(ArrayMap scoreboard_game, Array arraygame);

void DeleteScoreboard(ArrayMap *scoreboard_game, ArraySet *nama_pemain, Array array_game);

#endif