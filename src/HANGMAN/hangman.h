/* File hangman.h*/
#include <stdio.h>
#include <stdlib.h>
#include "../adt/Array/array.h"
#include "../adt/Mesin/mesinkarakter.h"
#include "../adt/Mesin/mesinkata.h"
#include "../RNG/random_number.h"
#include "queuehangman.h"

#ifndef HANGMAN
#define HANGMAN

void Hangman(Array *Kamus, int *score_game);
/* 
Spesifikasi game : Pemain menebak satu huruf yang terdapat pada kata tersebut. 
Apabila huruf tebakan terdapat dalam kata, maka huruf yang sudah tertebak akan 
ditampilkan pada layar. Apabila salah, maka pemain kehilangan satu kesempatan. 
Pemain tidak boleh menebak huruf yang sudah ditebak sebelumnya pada kata yang sama. 
Apabila pemain berhasil menebak suatu kata, maka pemain tersebut diberikan poin 
sesuai dengan panjang kata yang berhasil ditebak, kemudian program memberikan kata 
baru yang harus ditebak oleh pemain dengan jumlah kesempatan yang tersisa. Permainan 
akan berlanjut hingga pemain kehabisan kesempatan untuk menebak huruf yang salah
*/

void CreateArrayPenanda(char * Kata, Array* Penanda);
/* membuat array dengan elemen '0' dan '1' dengan jumlah elemen
   sama dengan jumlah elemen pada kata
   contoh : Kata : [M,A,K,A,N] maka dihasilkan array [0,0,0,0,0]
*/

void CetakHuruf(char* Kata, Array Penanda);
/* Menampilkan kata kata yang sudah ditebak
*/

boolean IsElement(ElType kata, char tebakan);
/* Menghasilkan True jika huruf pada tebakan terdapat dalam array kata
*/

boolean haveguess(Queue huruftebakan, char tebakan);
/* menghasilkan true jika huruf yang ditebak sudah pernah ditebak
*/

void ChangeArrayPenanda(ElType Kata, Array *Penanda, char tebakan);
/* Mengubah state pada Penanda.
   Kata : [M,A,K,A,N]
   tebakan : 'A'
   Penanda : [0,0,0,0,0] --> [0,1,0,1,0]
*/

boolean IsWin(Array Penanda);
/* Menghasilkan true jika semua elemen pada Penanda berelemen '1'
*/

#endif