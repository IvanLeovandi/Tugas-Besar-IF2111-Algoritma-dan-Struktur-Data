/* File dinerdash.c */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "dinerdash.h"

void displayQueueDiner(QueueDiner pesanan, ArrayDiner masak, QueueDiner saji, int* saldo) {
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
    if (IsEmptyDiner(masak)) printf("        |\n");
    else {
        for (i = 0; i <= masak.Neff; i++) {
            printf("M%d     | %d\n", masak.TI[i].id_makanan, masak.TI[i].durasi);
        }
    }

    printf("\nDaftar Makanan yang dapat disajikan\n");
    printf("Makanan | Sisa ketahanan makanan\n");
    printf("------------------------------\n");
    if (isEmptyDiner(saji)) printf("        |\n");
    else {
        for (i = 0; i <= IDX_TAIL(saji); i++) {
            printf("M%d     | %d\n", saji.buffer[i].id_makanan, saji.buffer[i].ketahanan);
        }
    }
}

int main() {
    /* KAMUS LOKAL */
    QueueDiner pesanan, saji;
    /* pesanan nanti akan diganti jadi ArrayDiner :D rasanya bukan QueueDiner */
    ArrayDiner masak;
    int saldo = 0, serve = 0, id = 0;
    ElType val;
    int i, j, idx;
    int lb_durasi = 1, up_durasi = 5, lb_harga = 10, up_harga = 50;
    int durasi, ketahanan, harga;
    char* perintah, *makanan, *command;

    boolean cook;
    /* ALGORITMA */
    CreateQueueDiner(&pesanan);
    MakeEmptyDiner(&masak);
    CreateQueueDiner(&saji);

    printf("Selamat Datang di Diner Dash!\n\n");
    

    for (i = 0; i < 3; i++) {
        val.id_makanan = i;
        val.durasi = (int)randomNumberMinMax(lb_durasi, up_durasi);
        val.ketahanan = (int)randomNumberMinMax(lb_durasi, up_durasi);
        val.harga = (int)randomNumberMinMax(lb_harga, up_harga) * 1000;

        enqueueDiner(&pesanan, val);
        id++;
    }

    while (IDX_TAIL(pesanan) <= 7 && serve != 15) {
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
                    masak.Neff++;
                    masak.TI[NbElmtDiner(masak)].id_makanan = pesanan.buffer[idx].id_makanan;
                    masak.TI[NbElmtDiner(masak)].durasi = pesanan.buffer[idx].durasi;
                    masak.TI[NbElmtDiner(masak)].ketahanan = pesanan.buffer[idx].ketahanan;
                    masak.TI[NbElmtDiner(masak)].harga = pesanan.buffer[idx].harga;
                    
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
                if (idx <= masak.TI[0].id_makanan) {
                    dequeueDiner(&saji, &val);
                    dequeueDiner(&pesanan, &val);
                    printf("\nBerhasil mengantar %s\n", makanan);
                    serve++;
                    saldo += val.harga;
                }
                else printf("%s belum dapat disajikan karena %s belum selesai\n", makanan);
            }
        } else if (compareSTR(command, "SKIP")) continue;

        printf("==========================================================\n\n");
        
        val.id_makanan = id;
        val.durasi = (int)randomNumberMinMax(lb_durasi, up_durasi);
        val.ketahanan = (int)randomNumberMinMax(lb_durasi, up_durasi);
        val.harga = (int)randomNumberMinMax(lb_harga, up_harga) * 1000;
        id++;
        enqueueDiner(&pesanan, val);

        for (i = 0; i <= IDX_TAIL(saji); i++) {
            saji.buffer[i].ketahanan--;
            if (saji.buffer[i].ketahanan == 0) {
                dequeueDiner(&saji, &val);
                dequeueDiner(&pesanan, &val);
            }
        }

        for (i = 0; i <= masak.Neff; i++) {
            if (masak.TI[i].id_makanan != m[1] - '0') {
                masak.TI[i].durasi--;
            }
            if (masak.TI[i].durasi == 0) {
                /* Delete from array masak */
                val.id_makanan = masak.TI[i].id_makanan;
                val.durasi = masak.TI[i].durasi;
                val.ketahanan = masak.TI[i].ketahanan;
                val.harga = masak.TI[i].harga;
                for (j = i; j <= masak.Neff; j++) {
                    masak.TI[j] = masak.TI[j+1];
                }
                masak.Neff--;
                enqueueDiner(&saji, val);
                m[1] = val.id_makanan + '0';
                printf("Makanan %s telah selesai dimasak\n\n", m);
            }
        }

    }

    printf("GAME OVER!!!\n\nSkor akhir: %d\n\n", saldo);

    return 0;
}