#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    /* KAMUS LOKAL */
    Stack S;
    char *X;
    /* ALGORITMA */
    X = (char*) malloc (10 *sizeof(char));
    /* Make X empty */
    for (int k = 0; k < 10; k++) {
        X[k] = '\0';
    }

    CreateEmpty(&S);
    Push(&S, "stack1");
    Push(&S, "stack2");
    Push(&S, "stack3");
    Push(&S, "stack4");
    printf("S sebelum di pop:\n");
    TulisStack(S);

    Pop(&S, &X);
    printf("\nS setelah di pop:\n");
    TulisStack(S);

    InversStack(&S);
    printf("\nInvers S:\n");
    TulisStack(S);
    return 0;
}