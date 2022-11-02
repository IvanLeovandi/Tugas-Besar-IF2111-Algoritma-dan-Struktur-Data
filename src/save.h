/* File save.h */
#include "boolean.h"
#include "adt/mesinkata.h"
#include "adt/array.h"

#ifndef SAVE_H
#define SAVE_H

#define InitialSize 10

void save(char* filename, Array arrGame, Array arrHistory);
/*
I.S.: file *.txt kosong atau sudah terisi
F.S.: State game dan history pemain tersave ke file *.txt
*/

void makeMallocEmpty(char* temp, int len);
/*
I.S.: temp hasil malloc berisi karakter-karakter sampah
F.S.: temp menjadi kosong
*/

#endif