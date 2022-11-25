#ifndef scoreboard_H
#define scoreboard_H

#include "../adt/map/map.h"
#include "../adt/set/set.h"

void AddSet(ArraySet *nama_user);


void AddScoreboard (ArrayMap *scoreboard_game);

int len_name (char* nama);

int longest_name(Map scoreboard_game);

void PrintSpace (int n);

void DisplayScoreboard(ArrayMap scoreboard_game, Array arraygame);

void DeleteScoreboard(ArrayMap *scoreboard_game, ArraySet *nama_pemain, Array array_game);