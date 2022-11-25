/* File tictactoe.c */
#include "tictactoe.h"
#include <stdio.h>
#include <stdlib.h>

int tictactoe() {
/* Memainkan game Tic Tac Toe */
    /* KAMUS LOKAL */
    int board[9] = {0};
    int player, turn;
    boolean win = false;
    /* ALGORITMA */
    printf("Selamat datang di TicTacToe!\n\n");
    printf("Permainan dimulai.\n\n");

    printf("Mau jadi Player 1 atau 2? (1/2): ");
    scanf("%d", &player);

    printf("\nKamu: X, Computer: O\n\n");
    if (player == 1) printf("Player 1: Kamu\nPlayer 2: Computer\n\n");
    else printf("Player 1: Computer\nPlayer 2: Kamu\n\n");

    for (turn = 0; turn < 9; turn++) {
        while (!win) {
            // if ((player + turn) % 2 == 0) computerMove();
            // else {
            //     drawPeta(board);
            //     playerMove(&board);
            // }
            drawPeta(board);
            playerMove(board);
            win = Win(board, player);
        }
    }
    drawPeta(board);

    if (win) printf("Kamu menang!\n");
    else printf("Kamu kalah :(\n");
}

void playerMove(int board[9]) {
/* Menerima masukan gerakan pemain */
    /* KAMUS LOKAL */
    int move;
    /* ALGORITMA */
    printf("Masukkan angka move (1..9): ");
    scanf("%d", &move);
    while (move < 1 && move > 9) {
        printf("Masukkan tidak valid. Silakan input kembali.\n\n");
        printf("Masukkan angka move (1..9): ");
        scanf("%d", &move);
    }
    board[move-1] = 1;
}

char convertToXO(int num) {
/* Mengembalikan hasil konversi num ke dalam bentuk X atau O */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (num == 1) return 'X';
    else if (num == -1) return 'O';
    else return ' ';
}

void drawPeta(int board[9]) {
/* Menampilkan peta ke layar */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    drawLine();
    printf("|   %c   |   %c   |   %c   |\n", convertToXO(board[0]), convertToXO(board[1]), convertToXO(board[2]));
    drawLine();
    printf("|   %c   |   %c   |   %c   |\n", convertToXO(board[3]), convertToXO(board[4]), convertToXO(board[5]));
    drawLine();
    printf("|   %c   |   %c   |   %c   |\n", convertToXO(board[6]), convertToXO(board[7]), convertToXO(board[8]));
    drawLine();
}

void drawLine() {
/* Menampilkan garis ke layar*/
    /* KAMUS LOKAL */
    int i, line = 196;
    /* ALGORITMA */
    for (i = 0; i < 25; i++) {
        printf("%c", line);
    }
    printf("\n");
}

boolean Win(int board[9], int player) {
/* Mengembalikan true jika kondisi board merupakan kondisi menang */
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    return ( 
        (board[0] == player && board[1] == player && board[2] == player) ||
        (board[3] == player && board[4] == player && board[5] == player) ||
        (board[6] == player && board[7] == player && board[8] == player) ||
        (board[0] == player && board[3] == player && board[6] == player) ||
        (board[1] == player && board[4] == player && board[7] == player) ||
        (board[2] == player && board[5] == player && board[8] == player) ||
        (board[0] == player && board[4] == player && board[8] == player) ||
        (board[2] == player && board[4] == player && board[6] == player)
    );
}

int main() {
    tictactoe();
    return 0;
}