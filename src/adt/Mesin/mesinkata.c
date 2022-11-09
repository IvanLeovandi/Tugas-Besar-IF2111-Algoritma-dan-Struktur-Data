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
{
    char *str;
    str = (char*) malloc((currentWord.Length)*sizeof(char));
    int i, strlength;
    strlength = currentWord.Length; 
    for(i = 0; i < strlength; i++)
    {
        *(str + i) = currentWord.TabWord[i];
    }
    *(str + strlength) = '\0';
    return str;
}

char* Input() // with no space
{
    char *command;
    // command = (char*) malloc (10 *sizeof(char));
    // int i, cmdlength;
    STARTWORD();
    command = KataToSTR(currentWord);
    // cmdlength = currentWord.Length;
    // for (i = 0; i < cmdlength; i++)
    // {
    //     *(command + i) = currentWord.TabWord[i];
    // }
    // command[cmdlength] = '\0';
    // // *(command + cmdlength) = '\0';
    // return command;
    return command;
}

int InputInt()
{
    char *str = Input();
    int integer = StrToInt(str);
    return integer;
}

int count_space(char *str)
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

boolean compareSTR(char* input_command, char* command_comp)
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