/* File dinerdash.c */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "dinerdash.h"

int main() {
    /* KAMUS LOKAL */
    QueueDiner pesanan, masak, saji;
    int saldo = 0;
    ElType id;
    ElType **val;
    int i, idx;
    int lb_durasi = 1, up_durasi = 5, lb_harga = 10000, up_harga = 50000;
    int durasi, ketahanan, harga;
    char* perintah, *makanan, *command;
    /* ALGORITMA */
    CreateQueue(&pesanan);
    CreateQueue(&masak);
    CreateQueue(&saji);

    printf("Selamat Datang di Diner Dash!\n\n");
    printf("SALDO: %d\n\nDaftar Pesanan\n", saldo);
    printf("Makanan | Durasi memasak | Ketahanan | Harga\n");
    printf("----------------------------------------------\n");

    for (i = 0; i < 3; i++) {
        id = i;
        durasi = (int)randomNumberMinMax(lb_durasi, up_durasi);
        ketahanan = (int)randomNumberMinMax(lb_durasi, up_durasi);
        harga = (int)randomNumberMinMax(lb_harga, up_harga);

        enqueue4(&pesanan, id, durasi, ketahanan, harga);
    }
    displayQueue4(pesanan);

    printf("\nDaftar Makanan yang sedang dimasak\n");
    printf("Makanan | Sisa durasi memasak\n");
    printf("------------------------------\n");
    displayQueue2(masak);

    printf("\nDaftar Makanan yang dapat disajikan\n");
    printf("Makanan | Sisa ketahanan makanan\n");
    printf("------------------------------\n");
    displayQueue2(saji);
    
    printf("MASUKKAN COMMAND: ");

    command = Input();
    perintah = FirstSTR(command);
    makanan = SecSTR(command);
    char m[2] = "M";
    if (compareSTR(perintah, "COOK")) {
        idx = pesanan.buffer[IDX_HEAD(pesanan)][0];
        m[1] = idx + '0';
        
        if (compareSTR(makanan, m)) {
            enqueue2(&masak, idx, pesanan.buffer[idx][1]);
            printf("\nBerhasil memasak %s\n", m);
        }
        else printf("%s belum dapat dimasak karena %s belum selesai\n", makanan, m);

    } else if (compareSTR(perintah, "SERVE")) {
        idx = IDX_HEAD(saji);
        m[1] = idx + '0';

        if (compareSTR(makanan, m)) {
            dequeue(&saji, val);
            dequeue(&pesanan, val);
            printf("\nBerhasil mengantar %s\n", m);

            // Belum selesai
            idx = pesanan.buffer[IDX_HEAD(pesanan)][0];
            enqueue2(&masak, idx, pesanan.buffer[idx][1]);
            m[1] = pesanan.buffer[IDX_HEAD(pesanan)][0] + '0';
            printf("Berhasil memasak %s\n", m);
        }
    }

    printf("==========================================================\n\n");

    // /* Hanya buat cek isi queue */
    // for (i = 0; i <= IDX_TAIL(pesanan); i++) {
    //     for (int j = 0; j < 4; j++) {
    //         printf("%d ", pesanan.buffer[i][j]);
    //     }
    // }

    return 0;
}