#include <stdio.h>
#include "history.h"

void show_hist(StackHis history, int n)
{
    int i, j;
    j = 1;
    if(n <= 0)
    {
        printf("Masukkan angka tidak tepat. Mohon masukkan angka yang valid.\n");
    } else
    {
        if(n > Top(history) + 1)
        {
            for (i = Top(history); i >= 0; i--)
            {
                printf("%d. %s\n", j, history.T[i]);
                j++;
            }
        }
        else
        {
            for (i = Top(history); i > Top(history) - n; i--)
            {
                printf("%d. %s\n", j, history.T[i]);
                j++;
            }
        }
    }
}

void reset_hist(StackHis *history)
{
    char *yakin; boolean valid = false;
    printf("\nAPAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY? ");
    while (!valid)
    {
        yakin = Input();
        if (compareSTR(yakin,"YA"))
        {
            CreateEmptyStackHis(history);
            printf("\nHistory berhasil di-reset.\n");
            valid = true;
        } else if (compareSTR(yakin, "TIDAK"))
        {
            printf("\nHistory tidak jadi di-reset. Berikut adalah daftar Game yang telah dimainkan\n");
            TulisStackHis(*history);
            valid = true;
        } else
        {
            printf("\nMasukkan tidak valid, mohon masukkan YA / TIDAK. ");
        }
    }
}