/* File dinerdash.c */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "dinerdash.h"

void displayQueueDiner(QueueDiner pesanan, QueueDiner masak, QueueDiner saji, int* saldo) {
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    printf("SALDO: %d\n\nDaftar Pesanan\n", *saldo);
    printf("Makanan | Durasi memasak | Ketahanan | Harga\n");
    printf("----------------------------------------------\n");
    for (i = 0; i <= IDX_TAIL(pesanan); i++) {
        printf("M%d     | %d             | %d        | %d\n", pesanan.buffer[i].id_makanan, pesanan.buffer[i].durasi, pesanan.buffer[i].ketahanan, pesanan.buffer[i].harga);
    }

    printf("\nDaftar Makanan yang sedang dimasak\n");
    printf("Makanan | Sisa durasi memasak\n");
    printf("------------------------------\n");
    if (isEmpty(masak)) printf("        |\n");
    else {
        for (i = 0; i <= IDX_TAIL(masak); i++) {
            printf("M%d     | %d\n", masak.buffer[i].id_makanan, masak.buffer[i].durasi);
        }
    }

    printf("\nDaftar Makanan yang dapat disajikan\n");
    printf("Makanan | Sisa ketahanan makanan\n");
    printf("------------------------------\n");
    if (isEmpty(saji)) printf("        |\n");
    else {
        for (i = 0; i <= IDX_TAIL(saji); i++) {
            printf("M%d     | %d\n", saji.buffer[i].id_makanan, saji.buffer[i].ketahanan);
        }
    }
}

int main() {
    /* KAMUS LOKAL */
    QueueDiner pesanan, masak, saji;
    int saldo = 0, serve = 0, id = 0;
    ElType val;
    int i, idx;
    int lb_durasi = 1, up_durasi = 5, lb_harga = 10, up_harga = 50;
    int durasi, ketahanan, harga;
    char* perintah, *makanan, *command;

    boolean cook;
    /* ALGORITMA */
    CreateQueue(&pesanan);
    CreateQueue(&masak);
    CreateQueue(&saji);

    printf("Selamat Datang di Diner Dash!\n\n");
    

    for (i = 0; i < 3; i++) {
        val.id_makanan = i;
        val.durasi = (int)randomNumberMinMax(lb_durasi, up_durasi);
        val.ketahanan = (int)randomNumberMinMax(lb_durasi, up_durasi);
        val.harga = (int)randomNumberMinMax(lb_harga, up_harga) * 1000;

        enqueue(&pesanan, val);
        id++;
    }

    while (IDX_TAIL(pesanan) < 7 && serve != 15) {
        displayQueueDiner(pesanan, masak, saji, &saldo);
        printf("MASUKKAN COMMAND: ");

        command = Input();
        perintah = FirstSTR(command);
        makanan = SecSTR(command);
        char m[3] = "M";
        m[2] = '\0';
        if (compareSTR(perintah, "COOK")) {
            idx = 0;
            cook = false;
            while (idx < IDX_TAIL(pesanan) && !cook) {
                m[1] = idx + '0';

                if (compareSTR(makanan, m)) {
                    enqueue(&masak, pesanan.buffer[idx]);
                    printf("\nBerhasil memasak %s\n", m);
                    cook = true;
                }

                idx++;
            }
        }

        // displayQueueDiner(pesanan, masak, saji, &saldo);

        else if (compareSTR(perintah, "SERVE")) {
            idx = saji.buffer[IDX_HEAD(saji)].id_makanan;
            m[1] = idx + '0';

            if (compareSTR(makanan, m)) {
                if (idx < masak.buffer[IDX_HEAD(masak)].id_makanan) {
                    dequeue(&saji, &val);
                    dequeue(&pesanan, &val);
                    printf("\nBerhasil mengantar %s\n", makanan);
                    serve++;
                    saldo += val.harga;
                }
                else printf("%s belum dapat disajikan karena %s belum selesai\n", makanan);
            }
        }

        printf("==========================================================\n\n");
        
        val.id_makanan = id;
        val.durasi = (int)randomNumberMinMax(lb_durasi, up_durasi);
        val.ketahanan = (int)randomNumberMinMax(lb_durasi, up_durasi);
        val.harga = (int)randomNumberMinMax(lb_harga, up_harga) * 1000;
        id++;
        enqueue(&pesanan, val);

        for (i = 0; i <= IDX_TAIL(saji); i++) {
            saji.buffer[i].ketahanan--;
            if (saji.buffer[i].ketahanan == 0) dequeue(&saji, &val);
        }

        for (i = 0; i <= IDX_TAIL(masak); i++) {
            masak.buffer[i].durasi--;
            if (masak.buffer[i].durasi == 0) {
                dequeue(&masak, &val);
                enqueue(&saji, val);
                m[1] = val.id_makanan + '0';
                printf("Makanan %s telah selesai dimasak\n\n", m);
            }
        }

    }

    printf("GAME OVER!!!\n\nSkor akhir: %d\n\n", saldo);

    return 0;
}