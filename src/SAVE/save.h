/* File save.h */
#include "../boolean.h"
#include "../adt/Mesin/mesinkata.h"
#include "../adt/Array/array.h"

#ifndef SAVE_H
#define SAVE_H

#define InitialSize 10

void save(char* filename, Array arrGame);
/*
I.S.: file *.txt kosong atau sudah terisi
F.S.: State game tersave ke file *.txt
*/

void makeMallocEmpty(char* temp, int len);
/*
I.S.: temp hasil malloc berisi karakter-karakter sampah
F.S.: temp menjadi kosong
*/

#endif