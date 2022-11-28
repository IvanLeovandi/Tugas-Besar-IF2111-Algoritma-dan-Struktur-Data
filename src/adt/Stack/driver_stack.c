#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    /* KAMUS LOKAL */
    Stack S;
    int X;
    /* ALGORITMA */
    CreateEmptyStack(&S);
    Push(&S, 1);
    Push(&S, 2);
    Push(&S, 3);
    Push(&S, 4);
    printf("S sebelum di pop:\n");
    TulisStack(&S);

    Pop(&S, &X);
    printf("\nS setelah di pop:\n");
    TulisStack(&S);

    InversStack(&S);
    printf("\nInvers S:\n");
    TulisStack(&S);
    return 0;
}