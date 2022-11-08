#include "../RNG/random_number.h"
#include "../adt/Mesin/mesinkata.h"

#ifndef RPS_H
#define RPS_H

boolean CheckValidInput(char *gerakan);
//I.S. Menerima input berupa gerakan pemain yang didapatkan dari stdin
//F.S. Mengembalikan true apabila gerakan yang diinput pemain berupa valid

int CheckHasil (char* gerakan_pemain, char*gerakan_bot);
//I.S Menerima 2 input gerakan pemain dan gerakan bot
//F.S Mengembalikan 2 jika Menang, 1 jika Seri, 0 jika Kalah

int Start_RPS();
//I.S Game Rock Paper Scissor dimulai
//F.S Mengemabalikan score yang diperoleh pemain

#endif