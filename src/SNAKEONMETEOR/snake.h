#include "../adt/Mesin/mesinkata.h"
#include "../adt/Mesin/mesinkarakter.h"
#include "../adt/List/linkedlist.h"
#include "../RNG/random_number.h"
#include "../clear.h"
#include "../delay.h"
#include "../color.h"

#ifndef SNAKE_H
#define SNAKE_H

void SnakeOnMeteor(int *score);
void Move (char command, snakeList *L, point* food, boolean* game, point* meteor, point obstacle, int* turn);
void Food (snakeList *L, point *food, point obstacle);
void Meteor (snakeList *L, boolean *game, point* meteor, point food, point obstacle);
void CreatePeta (snakeList *L, point* food, point* obstacle);
void InsertSnake (snakeList*L);
void SetNext (snakeList *L, int X, int Y, char prev);
void PrintSnake(snakeList L, point food, point meteor, point obstacle);
void PrintGaris();

#endif