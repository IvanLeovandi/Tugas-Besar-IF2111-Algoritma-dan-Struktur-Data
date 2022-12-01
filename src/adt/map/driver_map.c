#include "map.h"
#include <stdio.h>

int main()
{
    Map m;
    CreateEmptyMap(&m);
    if (IsEmptyMap(m))
    {
        printf("Kosong\n");
    }
    InsertMap(&m,"Owen",100);
    printf("%d\n",Value(m,"Owen"));
    if (!IsEmptyMap(m))
    {
        printf("Ada Isi!\n");
    }
    DeleteMap(&m,"Owen");
    if (IsEmptyMap(m))
    {
        printf("Berhasil Dihapus\n");
    }
}
