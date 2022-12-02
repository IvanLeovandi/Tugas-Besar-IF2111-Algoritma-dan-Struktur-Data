#include <stdio.h>
#include "linkedlist.h"
#include "../mesin/mesinkata.h"

int main()
{
    snakeList L;
    CreateEmptySnake(&L);
    printf("ini adalah jumlah elemen List : %d\n", nbSnake(L));
    printf("beri satu input integer untuk dimasukkan kedalam List: ");
    int X = StrToInt(Input());
    printf("beri input berikutnya: ");
    int Y = StrToInt(Input());
    adrSnake P = AlokasiSnake(X, Y, 'a');
    InsertLastSnake(&L, P);
    int testX = Point(Head(L)).x;
    int testY = Point(Head(L)).y;
    printf("ini isi point pertama List: %d %d\n", testX, testY);
    printf("ini jumlah element array : %d\n", nbSnake(L));
    boolean found;
    if (SearchSnake(L, 1, 1) != Nil){
        found = true;
    } else {found = false;}
    printf("Cek apakah terdapat point (1,1): %d\n", found);
    return 0;
}