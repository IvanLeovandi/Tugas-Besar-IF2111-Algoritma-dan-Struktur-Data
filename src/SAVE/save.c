/* File save.c */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "save.h"

void save(char* filename, Array arrGame) {
/*
I.S.: file *.txt kosong atau sudah terisi
F.S.: State game dan history pemain tersave ke file *.txt
*/
    FILE *txt;
    char *savename = (char *)malloc((str_len(filename)*2) * sizeof(char));
    if(savename == NULL)
    {
        printf("Save gagal dilakukan. Silahkan coba kembali.\n");
    } else
    {
        if(compareSTR(filename, "\0"))
        {
            printf("Save gagal dilakukan, tolong masukkan nama file terlebih dahulu.\n");
        } else
        {
            savename = concatSTR("../data/", filename);
            txt = fopen(savename, "w+");
            char *numgame = (char *)malloc(5 * sizeof(char));
            int i;
            sprintf(numgame, "%d", arrGame.Neff);
            fprintf(txt, "%s\n", numgame);

            for (i = 0; i < NbElmt(arrGame) - 1; i++)
            {
                fprintf(txt, "%s\n", arrGame.TI[i]);
            }
            fprintf(txt, "%s", arrGame.TI[NbElmt(arrGame) - 1]);

            fclose(txt);
            printf("Save berhasil dilakukan.\n");
            free(savename);
            free(numgame);
        }
    }
}