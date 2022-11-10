#include <stdio.h>
#include "queue.h"
#include "../mesin/mesinkata.h"

int main()
{
    Queue q;
    CreateQueue(&q);
    if(isEmpty)
    {
        printf("Queue ini baru dibuat, jadi masih kosong :D\n");
        printf("Panjang queuenya : %d\n", length(q));
    }
    printf("Masukin sesuatu yuk ke dalam queuenya : ");
    char *input = Input();
    enqueue(&q, input);
    displayQueue(q);
    printf("Apakah %s ada di dalam queue?\n", input);
    if(SearchElmtQueue(q, input))
    {
        printf("ada donk!\n");
    }
    printf("mari kita coba hapus %s\n", input);
    dequeue(&q, &input);
    printf("Mari kita cari lagi %s di queue\n", input);
    if(SearchElmtQueue(q, input))
    {
        printf("ada donk!\n");
    } else
    {
        printf("udah gada nih :(\n");
    }
    return 0;
}

// how to run : gcc queue.c ../mesin/mesinkarakter.c ../mesin/mesinkata.c driver_queue.c -o driver_queue