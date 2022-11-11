#include <stdio.h>
#include "loader.h"
#include "mesinkarakter.h"
#include "mesinkata.h"

int main()
{
    // menjalankan fungsi input
    printf("input suatu karakter.\n");
    START();
    printf("ini adalah inputan kamu : %c\n", GetCC());
    printf("Input suatu kata : \n");
    //
    START();
    STARTWORD();
    printf("ini adalah panjang dari kata kamu : %d\n", currentWord.Length);
    printf("ini adalah kata yang kamu input : ");
    int i;
    for(i = 0; i < currentWord.Length; i++)
    {
        printf("%c", currentWord.TabWord[i]);
    }
    //
    printf("\ncoba input: ");
    char *test = Input();
    printf("ini adalah input yang kamu masukan dalam bentuk string: %s\n", test);
    return 0;
}

// how to run : gcc mesinkarakter.c mesinkata.c loader.c driver_mesin.c -o driver_mesin
// untuk ADT loader dapat dilihat implementasinya di fungsi load.