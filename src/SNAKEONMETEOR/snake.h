#include <stdio.h>
#include <stdlib.h>

#include "../adt/Mesin/mesinkata.h"
#include "../adt/Mesin/mesinkarakter.h"
#include "../adt/List/linkedlist.h"
#include "../RNG/random_number.h"

#ifndef SNAKE_H
#define SNAKE_H

void SnakeOnMeteor();
void Move (char command, snakeList *L, point* food, boolean* game, point* meteor, int* turn);
void Food (snakeList *L, point *food);
void Meteor (snakeList *L, boolean *game, point* meteor, point food);

#endif