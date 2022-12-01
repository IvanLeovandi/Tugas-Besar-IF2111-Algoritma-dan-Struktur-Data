#include "set.h"
#include <stdio.h>

int main()
{
    Set s;
    CreateEmptySet(&s);
    if (IsEmptySet(s))
    {
        printf("KOSONG\n");
    }
    InsertSet(&s,"HALO");
    if (!IsEmptySet(s))
    {
        printf("Ada Isi!\n");
    }
    if (IsMemberSet(s,"HALO"))
    {
        printf("SAMA\n");
    }
    DeleteSet(&s,"HALO");
    if (IsEmptySet(s))
    {
        printf("Berhasil Dihapus\n");
    }
    return 0;
}