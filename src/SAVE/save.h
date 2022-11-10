/* File save.h */
#include "../boolean.h"
#include "../adt/Mesin/mesinkata.h"
#include "../adt/Array/array.h"

#ifndef SAVE_H
#define SAVE_H

#define InitialSize 1000

void save(char* filename, Array arrGame);
/*
I.S.: file *.txt kosong atau sudah terisi
F.S.: State game tersave ke file *.txt
*/

#endif