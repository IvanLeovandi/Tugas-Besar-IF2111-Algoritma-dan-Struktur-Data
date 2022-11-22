/* File clear.c */
#include "clear.h"

void ClearScreen() {
/* Menghapus tulisan pada command line */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}