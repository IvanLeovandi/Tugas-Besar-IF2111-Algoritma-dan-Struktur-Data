/* File dinerdash.c */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "dinerdash.h"
#include <math.h>
#include <time.h>


void TulisAntrian(int saldo, QueueDiner pesanan, QueueDiner masak, QueueDiner saji){
    printf("SALDO: %d\n\nDaftar Pesanan\n", saldo);
    printf("Makanan | Durasi memasak | Ketahanan | Harga\n");
    printf("----------------------------------------------\n");
    displayQueue4(pesanan);

    printf("\nDaftar Makanan yang sedang dimasak\n");
    printf("Makanan | Sisa durasi memasak\n");
    printf("------------------------------\n");
    displayQueue2(masak);

    printf("\nDaftar Makanan yang dapat disajikan\n");
    printf("Makanan | Sisa ketahanan makanan\n");
    printf("------------------------------\n");
    displayQueue2(saji);
}

void putaran(int *countid, QueueDiner *pesanan, QueueDiner *masak, QueueDiner *saji){
    int durasi, ketahanan, harga;

    durasi = rand()%5 +1;
    ketahanan = rand()%5 +1;
    harga = (rand()%50 +1)*1000;

    enqueue4(pesanan, *countid, durasi, ketahanan, harga);
    (*countid)++;

    for (int i=0; i<length(*masak); i++){
        masak->buffer[i][1] --;
    }

    for (int i=0; i<length(*saji); i++){
        saji->buffer[i][1] --;
    }

}

int main() {
    /* KAMUS LOKAL */
    QueueDiner pesanan, masak, saji;
    int saldo = 0;
    ElType id;
    ElType *val;
    int i, idx;
    int lb_durasi = 1, up_durasi = 5, lb_harga = 10000, up_harga = 50000;
    int durasi, ketahanan, harga;
    char* perintah, *makanan, *command;
    int served = 0;
    int countid = 3;
    /* ALGORITMA */

    srand(time(NULL));
   
    CreateQueue(&pesanan);
    CreateQueue(&masak);
    CreateQueue(&saji);

    printf("Selamat Datang di Diner Dash!\n\n");

    for (i = 0; i < 3; i++) {
        id = i;
        durasi = rand()%5 +1;
        ketahanan = rand()%5 +1;
        harga = (rand()%40 +10)*1000;

        enqueue4(&pesanan, id, durasi, ketahanan, harga);
    }

    TulisAntrian(saldo, pesanan, masak, saji);
    
    
    while (length(pesanan) <= 7 && served<15){
        printf("MASUKKAN COMMAND: ");

        command = Input();
        perintah = FirstSTR(command);
        makanan = SecSTR(command);
        char m[2] = "M";

        while ((!compareSTR(perintah, "COOK") && !compareSTR(perintah, "SERVE") && !compareSTR (perintah, "SKIP"))){
            printf("COMMAND TIDAK SESUAI\n");
            printf("MASUKKAN COMMAND: ");

            command = Input();
            perintah = FirstSTR(command);
            makanan = SecSTR(command);
        }

        putaran(&countid, &pesanan, &masak, &saji);

        if (compareSTR(perintah, "COOK")) {
            idx = makanan[1]-'0';
            m[1] = idx + '0';
            
            if (length(masak)<5) {
                enqueue2(&masak, idx, pesanan.buffer[idx][1]);
                printf("\nBerhasil memasak %s\n", m);

            }
            else printf("%s belum dapat dimasak karena masakan penuh", makanan);

        } else if (compareSTR(perintah, "SERVE")) {
            idx = HEAD(saji)[0];
            m[1] = idx + '0';

            // if (makanan == HEAD(pesanan)[0]){

            // if (compareSTR(makanan, m)) {
                dequeue(&saji, &val);
                dequeue(&pesanan, &val);
                printf("\nBerhasil mengantar %s\n", makanan);

                // Belum selesai
                idx = pesanan.buffer[IDX_HEAD(pesanan)][0];
                enqueue2(&masak, idx, pesanan.buffer[idx][1]);
                m[1] = pesanan.buffer[IDX_HEAD(pesanan)][0] + '0';
                printf("Berhasil memasak %s\n", m);
            // }
        }

        TulisAntrian(saldo, pesanan, masak, saji);
        printf("==========================================================\n\n");
    }

    // /* Hanya buat cek isi queue */
    // for (i = 0; i <= IDX_TAIL(pesanan); i++) {
    //     for (int j = 0; j < 4; j++) {
    //         printf("%d ", pesanan.buffer[i][j]);
    //     }
    // }

    return 0;
}