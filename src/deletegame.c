/* File deletegame.c */
#include <stdio.h>
#include "deletegame.h"

/* File ADT*/
#include "queue.h"

void deletegame(array* game);
/* 
I.S.: input list game yang akan dihapus dan nomor dari list tersebut
F.S.: Program menghapus nama game dengan nomor padalist tersebut
*/
{
    printf("Berikut adalah daftar game yang tersedia\n");
    int i;
    for(i = 0; i < game->Neff; i++){
        printf("%d. %s\n",i+1,game->TI[i]);
    }
    int number;
    printf("Masukkan nomor game yang akan dihapus:");
    scanf("%d",&number);
    if (number < 6){
        printf("Game gagal dihapus");
    }else{
        int j;
        for(j = number; j<game->Neff -1; j++){
            game->TI[j] = game->TI[j+1];
        }
        printf("Game berhasil dihapus");
    }

}