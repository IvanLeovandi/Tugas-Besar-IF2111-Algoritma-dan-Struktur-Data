#include <stdio.h>
#include "array.h"
#include "../mesin/mesinkata.h"

int main()
{
    Array arr;
    MakeEmpty(&arr);
    printf("ini adalah nilai dari Neff array : %d\n", NbElmt(arr));
    if(IsEmpty(arr))
    {
        printf("array ini kosong.\n");
    }
    printf("beri input untuk dimasukkan kedalam array : ");
    char *input = Input();
    SetEl(&arr, 0, input);
    SetNeff(&arr, 1);
    char *test = GetElmt(arr, 0);
    printf("ini isi array: %s\n", test);
    printf("ini jumlah element array : %d\n", NbElmt(arr));
    boolean found = IsElmt(arr, "halo");
    printf("ini hasil boolean: %d", found);
    return 0;
}

// how to run : gcc array.c ../mesin/mesinkarakter.c ../mesin/mesinkata.c driver_array.c -o driver_array