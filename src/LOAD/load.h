#include <stdio.h>
#include "../boolean.h"
#include "../adt/Array/array.h"
#include "../adt/Mesin/mesinkarakter.h"
#include "../adt/Mesin/mesinkata.h"
#include "../adt/Mesin/loader.h"
#include "../adt/Stack/stack.h"


#ifndef LOAD_H
#define LOAD_H

void load(Array *array_game, Stack *history, char *filename, boolean isStart);
/* Membaca isi file "filename" dan memasukkannya ke dalam array_game */

#endif