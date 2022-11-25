/* File tictactoe.h */
#include "../adt/Tree/tree.h"

#ifndef TICTACTOE_H
#define TICTACTOE_H

int tictactoe();
/* Memainkan game Tic Tac Toe */

void playerMove(int board[9]);
/* Menerima masukan gerakan pemain */

char convertToXO(int num);
/* Mengembalikan hasil konversi num ke dalam bentuk X atau O */

void drawPeta(int board[9]);
/* Menampilkan peta ke layar */

void drawLine();
/* Menampilkan garis ke layar*/

boolean Win(int board[9], int player);
/* Mengembalikan true jika kondisi board merupakan kondisi menang */

#endif