/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../../boolean.h"
#include "mesinkarakter.h"

#define NMax 100
#define BLANK ' '

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Kata */
extern boolean EndWord;
extern Word currentWord;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

char* KataToSTR(Word currentWord);
/* Menerima masukan bertipe Word lalu mengkonversikannya menjadi sebuah nilai string yang dikembalikan.*/

char* Input();
/* Menerima input dari terminal dengan membaca pita = stdin yang bertipe Word lalu mengembalikan nilai dalam bentuk string. String yang diterima mengikutsertakan spasi*/

int InputInt();
/* Menerima masukan seperti fungsi input, namun mengubahnya dari tipe string menjadi tipe integer.*/

int count_space(char *str);
/* Sebuah fungsi yang mengembalikan nilai banyaknya nilai spasi.*/

int str_len(char *str);
/* Sebuah fungsi yang mengembalikan nilai panjangnya string.*/

char *FirstSTR(char *command);
/* Sebuah fungsi yang memisahkan sebuah string yang memiliki spasi sebanyak 1. String yang diakuisisi adalah kata pertama sebelum spasi.*/

char *SecSTR(char *command);
/* Sebuah fungsi yang memisahkan sebuah string yang memiliki spasi sebanyak 1. String yang diakuisisi adalah kata kedua setelah spasi.*/

char *concatSTR(char *awal, char *akhir);
/* Sebuah fungsi yang menggabungkan dua buah string dan mengembalikan string baru hasil gabungan kedua string.*/

boolean compareSTR(char* input_command, char* command_comp);
/* Sebuah fungsi yang membandingkan string dan mengembalikan nilai bertipe boolean.*/

boolean isInt(char *str_int);
/* Sebuah fungsi yang digunakan untuk mengecek apakah sebuah string dapat dikonversi menjadi nilai integer dengan memerhatikan jumlah spasi pada string tersebut.*/

int StrToInt(char *str);
/* Sebuah fungsi yang mengkonversi tipe data string menjadi integer.*/

#endif