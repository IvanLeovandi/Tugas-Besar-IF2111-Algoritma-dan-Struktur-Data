/* File dinerdash.c */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "dinerdash.h"

void putaran(int *id, QueueDiner *pesanan, ArrayDiner *masak, ArrayDiner *saji){
    int durasi, ketahanan, harga;
    int lb_durasi = 1, up_durasi = 5, lb_harga = 10, up_harga = 50;
    ElTypeDiner val;

    (*id)++;

    val.id_makanan = *id;
    val.durasi = rand()%5 +1;
    val.ketahanan = rand()%5 +1;
    val.harga = (rand()%50 +1)*1000;

    enqueueDiner(pesanan, val);

    for (int i=0; i< saji->Neff; i++){
        saji->TI[i].durasi --;
        if (saji->TI[i].durasi == 0) {
            for (int j = i; j < saji->Neff; j++) {
                    saji->TI[j] = saji->TI[j+1];
                }
                masak->Neff--;}
            }


    for (int i=0; i< masak->Neff; i++){
        masak->TI[i].durasi --;
        if (masak->TI[i].durasi == 0) {
            // if (masak.buffer[i].durasi == 0) {
                /* Delete from array masak */
                saji->Neff++;
                saji->TI[saji->Neff].id_makanan = masak->TI[i].id_makanan;
                saji->TI[saji->Neff].durasi = masak->TI[i].durasi;
                saji->TI[saji->Neff].ketahanan = masak->TI[i].ketahanan;
                saji->TI[saji->Neff].harga = masak->TI[i].harga;

                int m = masak->TI[i].id_makanan;
                printf("Makanan M%d telah selesai dimasak\n\n", m);

                for (int j = i; j < masak->Neff; j++) {
                    masak->TI[j] = masak->TI[j+1];
                }
                masak->Neff--;
                // dequeueDiner(&masak, &val);


            }
    }

}

void displayQueueDiner(QueueDiner pesanan, ArrayDiner masak, ArrayDiner saji, int* saldo) {
    /* KAMUS LOKAL */
    
    int i;
    /* ALGORITMA */
    printf("SALDO: %d\n\nDaftar Pesanan\n", *saldo);
    printf("Makanan | Durasi memasak | Ketahanan | Harga\n");
    printf("----------------------------------------------\n");
    for (i = 0; i < lengthDiner(pesanan); i++) {
        printf("M%d     | %d             | %d        | %d\n", pesanan.buffer[i].id_makanan, pesanan.buffer[i].durasi, pesanan.buffer[i].ketahanan, pesanan.buffer[i].harga);
    }

    printf("\nDaftar Makanan yang sedang dimasak\n");
    printf("Makanan | Sisa durasi memasak\n");
    printf("------------------------------\n");
    if (IsEmptyDiner(masak)) printf("        |\n");
    else {
        for (i = 0; i <= masak.Neff; i++) {
            printf("M%d     | %d\n", masak.TI[i].id_makanan, masak.TI[i].durasi);
        }
    }

    printf("\nDaftar Makanan yang dapat disajikan\n");
    printf("Makanan | Sisa ketahanan makanan\n");
    printf("------------------------------\n");
    if (IsEmptyDiner(saji)){ printf("        |\n");}
    else {
        for (i = 0; i <= NbElmtDiner(saji); i++) {
            printf("M%d     | %d\n", saji.TI[i].id_makanan, saji.TI[i].ketahanan);
        }
    }
}

int main() {
    /* KAMUS LOKAL */
    QueueDiner pesanan;
    ArrayDiner masak, saji;
    int saldo = 0, serve = 0, id = 0;
    ElTypeDiner val;
    int i, j, idx;
    int lb_durasi = 1, up_durasi = 5, lb_harga = 10, up_harga = 50;
    int durasi, ketahanan, harga;
    char* perintah, *makanan, *command;

    srand(time(NULL));

    boolean cook;
    /* ALGORITMA */
    CreateQueueDiner(&pesanan);
    MakeEmptyDiner(&masak);
    MakeEmptyDiner(&saji);

    printf("Selamat Datang di Diner Dash!\n\n");
    

    for (i = 0; i < 2; i++) {
        id = i;
        val.id_makanan = i;
        val.durasi = rand()%5 +1;
        val.ketahanan = rand()%5 +1;
        val.harga = (rand()%50 +1)*1000;

        enqueueDiner(&pesanan, val);
    }

    while (lengthDiner(pesanan) <= 7 && serve < 15) {
        putaran(&id, &pesanan, &masak, &saji);


        displayQueueDiner(pesanan, masak, saji, &saldo);
        printf("MASUKKAN COMMAND: ");



        command = Input();
        perintah = FirstSTR(command);
        makanan = SecSTR(command);

        char m[3] = "M";
        m[2] = '\0';
        if (compareSTR(perintah, "COOK")) {
            idx = makanan[1] - '0';
            cook = false;
            while (idx < lengthDiner(pesanan) && !cook) {
                m[1] = idx + '0';

                if (compareSTR(makanan, m)) {
                    masak.Neff++;
                    masak.TI[NbElmtDiner(masak)].id_makanan = pesanan.buffer[idx].id_makanan;
                    masak.TI[NbElmtDiner(masak)].durasi = pesanan.buffer[idx].durasi;
                    masak.TI[NbElmtDiner(masak)].ketahanan = pesanan.buffer[idx].ketahanan;
                    masak.TI[NbElmtDiner(masak)].harga = pesanan.buffer[idx].harga;
                    
                    // enqueueDiner(&masak, pesanan.buffer[idx]);
                    printf("\nBerhasil memasak M%d\n", idx);
                    cook = true;
                }

                idx++;
            }
        }

        // displayQueueDiner(pesanan, masak, saji, &saldo);

        else if (compareSTR(perintah, "SERVE")) {
            idx = makanan[1] - '0';
            printf("%d", idx);
            m[1] = idx + '0';

            if (compareSTR(makanan, m)) {
                if (idx == pesanan.buffer[0].id_makanan) {
                // if (idx < masak.buffer[IDX_HEAD(masak)].id_makanan) {
                    for (int i= 0; i < NbElmtDiner(saji); i++) {
                        if (saji.TI[i].id_makanan == idx){
                            for (int j=i; j<saji.Neff; j++){
                                saji.TI[j] = saji.TI[j+1];
                            }
                        }
                    }
                    saji.Neff--;
                    printf("\nBerhasil mengantar %s\n", makanan);
                    serve++;
                    saldo += val.harga;

                    dequeueDiner(&pesanan, &val);

                }
                else printf("%s belum dapat disajikan karena %s belum selesai\n", makanan);
            }
        }

        printf("==========================================================\n\n");
  

    }

    printf("GAME OVER!!!\n\nSkor akhir: %d\n\n", saldo);

    return 0;
}