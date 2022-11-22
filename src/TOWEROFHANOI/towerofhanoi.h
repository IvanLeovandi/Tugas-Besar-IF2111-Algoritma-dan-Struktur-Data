/* File towerofhanoi.h */
#include <stdio.h>
#include <stdlib.h>
#include "../adt/Stack/stack.h"

#ifndef TOWER_OF_HANOI_H
#define TOWER_OF_HANOI_H

void towerOfHanoi();

void Tulis3Stack(Stack StackA, Stack StackB, Stack StackC);

char* ConvertToStar(int num);

void MoveTop(Stack *awal, Stack *tujuan);

boolean Win(Stack S);

#endif