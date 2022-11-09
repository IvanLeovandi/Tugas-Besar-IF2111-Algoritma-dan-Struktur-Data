#include <stdio.h>
#include <stdlib.h>

/* File random_number.h */
#ifndef RANDOM_NUMBER_H
#define RANDOM_NUMBER_H

unsigned long long int randomNumberWithMaxDigit(int digit);
/* Mengembalikan random number */

unsigned long long int randomNumberMinMax(int min, int max);
/* Mengembalikan random number dengan masukan minimum dan maksimum angka */

unsigned long long int randomNumber();
/* Mengembalikan random number tanpa masukan jumlah digit */

unsigned long long int randm(int n);
/* Mengembalikan random number dari jumlah digit n yang diinginkan */

unsigned long long int von(unsigned long long int x, int n);
/* Mengembalikan random number dengan algoritma Von Neumann Middle Square */ 

#endif