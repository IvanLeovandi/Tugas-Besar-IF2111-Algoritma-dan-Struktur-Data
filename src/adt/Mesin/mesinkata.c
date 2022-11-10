/* File mesinkata.c */

#include "mesinkata.h"
#include <stdio.h>
#include <stdlib.h>

boolean EndWord;
Word currentWord;

void IgnoreBlanks() {
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    // KAMUS LOKAL
    // ALGORITMA
    while (currentChar == BLANK) {
        ADV();
    }
}

void STARTWORD() {
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
    // KAMUS LOKAL
    // ALGORITMA
    START();
    // IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    } else {
        EndWord = false;
    }
    CopyWord();
}

void ADVWORD() {
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
    // KAMUS LOKAL
    // ALGORITMA
    // IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    } else {
        CopyWord();
        // IgnoreBlanks();
    }
}

void CopyWord() {
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    // KAMUS LOKAL
    int i = 0;
    // ALGORITMA
    while ((i < NMax) && (currentChar != MARK)) { // currentChar != BLANK
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    currentWord.Length = i;
}

char* KataToSTR(Word currentWord)
/* Menerima masukan bertipe Word lalu mengkonversikannya menjadi sebuah nilai string yang dikembalikan.*/
{
    char *str;
    str = (char*) malloc((currentWord.Length*2)*sizeof(char));
    int i, strlength;
    strlength = currentWord.Length; 
    for(i = 0; i < strlength; i++)
    {
        *(str + i) = currentWord.TabWord[i];
    }
    *(str + strlength) = '\0';
    return str;
}

char* Input()
/* Menerima input dari terminal dengan membaca pita = stdin yang bertipe Word lalu mengembalikan nilai dalam bentuk string. String yang diterima mengikutsertakan spasi*/
{
    char *command;
    STARTWORD();
    command = KataToSTR(currentWord);
    return command;
}

int InputInt()
/* Menerima masukan seperti fungsi input, namun mengubahnya dari tipe string menjadi tipe integer.*/
{
    char *str = Input();
    int integer = StrToInt(str);
    return integer;
}

int count_space(char *str)
/* Sebuah fungsi yang mengembalikan nilai banyaknya nilai spasi.*/
{
    int count = 0;
    while(*str != '\0')
    {
        if(*str == ' ')
        {
            count++;
        }
        str++;
    }
    return count;
}

int str_len(char *str)
/* Sebuah fungsi yang mengembalikan nilai panjangnya string.*/
{
    int count = 0;
    while (*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}

char *FirstSTR(char *command)
/* Sebuah fungsi yang memisahkan sebuah string yang memiliki spasi sebanyak 1. String yang diakuisisi adalah kata pertama sebelum spasi.*/
{
    int i = 0;
    char *firstSTR;
    firstSTR = (char*) malloc(50*sizeof(char));
    while(command[i] != BLANK && command[i]!= '\0')
    {
        *(firstSTR + i) = command[i];
        i++;
    }
    *(firstSTR + i) = '\0';
    return firstSTR;
}

char *SecSTR(char *command)
/* Sebuah fungsi yang memisahkan sebuah string yang memiliki spasi sebanyak 1. String yang diakuisisi adalah kata kedua setelah spasi.*/
{
    int i = 0;
    int j = 0;
    char *secSTR;
    secSTR = (char*) malloc(50*sizeof(char));
    while(command[i] != BLANK && command[i] != '\0')
    {
        i++;
    }
    while(command[i] == BLANK) {i++;}

    while(command[i] != '\0')
    {
        secSTR[j] = command[i];
        i++;
        j++;
    }
    *(secSTR + j) = '\0';
    return secSTR;
}

char *concatSTR(char *awal, char *akhir)
/* Sebuah fungsi yang menggabungkan dua buah string dan mengembalikan string baru hasil gabungan kedua string.*/
{
    char *result;
    result = (char *)malloc(50 * sizeof(char));
    int i, j;
    for(i = 0; i < str_len(awal); i++)
    {
        *(result + i) = awal[i];
    }
    int idx = 0;
    for(j = i; j < str_len(awal) + str_len(akhir); j++)
    {
        *(result + j) = akhir[idx];
        idx++;
    }
    *(result + j) = '\0';
    return result;
}

boolean compareSTR(char* input_command, char* command_comp)
/* Sebuah fungsi yang membandingkan string dan mengembalikan nilai bertipe boolean.*/
{
    int i = 0;
    while(input_command[i] == command_comp[i])
    {
        if(input_command[i] == '\0' || command_comp[i] == '\0')
        {
            break;
        }
        i++;
    }
    if(input_command[i] == '\0' && command_comp[i] == '\0')
    {
        return true;
    } else
    {
        return false;
    }
}

boolean isInt(char *str_int)
/* Sebuah fungsi yang digunakan untuk mengecek apakah sebuah string dapat dikonversi menjadi nilai integer dengan memerhatikan jumlah spasi pada string tersebut.*/
{
    if(count_space(str_int) == 0)
    {
        return true;
    } else
    {
        false;
    }
}

int StrToInt(char *str)
/* Sebuah fungsi yang mengkonversi tipe data string menjadi integer.*/
{
    int i = 0, result = 0;
    if(isInt(str))
    {
        while(str[i] != '\0')
        {
            result = result * 10 + str[i] - '0';
            i++;
        }
        return result;
    }
    else
    {
        result = -9999;
        return result;
    }
}
