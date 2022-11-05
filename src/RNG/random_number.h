/* File random_number.h */
#ifndef RANDOM_NUMBER_H
#define RANDOM_NUMBER_H

unsigned long long int randomNumberWithDigit(int digit);
/* Mengembalikan random number */

unsigned long long int randomNumber();
/* Mengembalikan random number tanpa masukan jumlah digit */

unsigned long long int randm(int n);
/* Mengembalikan random number dari jumlah digit n yang diinginkan */

unsigned long long int von(unsigned long long int x, int n);
/* Mengembalikan random number dengan algoritma Von Neumann Middle Square */ 

#endif