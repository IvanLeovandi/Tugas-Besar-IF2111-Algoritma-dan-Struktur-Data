/* File dinerdash.c */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "dinerdash.h"

int fromStr(char *x){
    if (x[0]=='M'){
        if (x[1]!='\0'){
        int i=1;
        int hitung = 0;
        while (x[i]!= '\0'){
            hitung *= 10;
            hitung += x[i] - '0';
            i++;
        }
        return hitung;}
    }
    return IdxUndefDiner;
}

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

    for (int i=0; i< NbElmtDiner(*saji); i++){
        saji->TI[i].ketahanan --;
        if (saji->TI[i].ketahanan == 0) {
            DelEl(saji, &val, i);
            i--; 
            }
    }


    for (int i=0; i< NbElmtDiner(*masak); i++){
        masak->TI[i].durasi --;
        if (masak->TI[i].durasi == 0) {

                AddEl(saji, masak->TI[i]);
                DelEl(masak, &val, i);

                i--;

                int m = val.id_makanan;
                printf("Makanan M%d telah selesai dimasak\n\n", m);

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
        int j = pesanan.idxHead+i % CAPACITY;
        printf("M%d     | %d             | %d        | %d\n", pesanan.buffer[j].id_makanan, pesanan.buffer[j].durasi, pesanan.buffer[j].ketahanan, pesanan.buffer[j].harga);
    }

    printf("\nDaftar Makanan yang sedang dimasak\n");
    printf("Makanan | Sisa durasi memasak\n");
    printf("------------------------------\n");
    
    if (IsEmptyDiner(masak)) printf("        |\n");
    else {
        for (i = 0; i < NbElmtDiner(masak); i++) {
            printf("M%d     | %d\n", masak.TI[i].id_makanan, masak.TI[i].durasi);
        }
    }

    printf("\nDaftar Makanan yang dapat disajikan\n");
    printf("Makanan | Sisa ketahanan makanan\n");
    printf("------------------------------\n");
    if (IsEmptyDiner(saji)){ printf("        |\n");}
    else {
        for (i = 0; i < NbElmtDiner(saji); i++) {
            printf("M%d     | %d\n", saji.TI[i].id_makanan, saji.TI[i].ketahanan);
        }
    }
}

void DinerDash() {
    /* KAMUS LOKAL */
    QueueDiner pesanan;
    ArrayDiner masak, saji;
    int saldo = 0, serve = 0, idpesanan = 0;
    ElTypeDiner val;
    int i, j, idx;
    int lb_durasi = 1, up_durasi = 5, lb_harga = 10, up_harga = 50;
    int durasi, ketahanan, harga;
    char* perintah, *makanan, *command;

    boolean cook;
    /* ALGORITMA */
    CreateQueueDiner(&pesanan);
    MakeEmptyDiner(&masak);
    MakeEmptyDiner(&saji);

    printf("Selamat Datang di Diner Dash!\n\n");
    

    for (i = 0; i < 3; i++) {
        idpesanan = i;
        val.id_makanan = i;
        val.durasi = rand()%5 +1;
        val.ketahanan = rand()%5 +1;
        val.harga = (rand()%50 +1)*1000;

        enqueueDiner(&pesanan, val);
    }

    while (lengthDiner(pesanan) <= 7 && serve < 15) {
        displayQueueDiner(pesanan, masak, saji, &saldo);
        
        printf("MASUKKAN COMMAND: ");

        command = Input();
        perintah = FirstSTR(command);
        makanan = SecSTR(command);

        int idx = fromStr(makanan);

        while ((!compareSTR(perintah, "COOK") || SearchIdIn(pesanan, idx)==IdxUndefDiner) && (!compareSTR(perintah, "SERVE") || SearchIdArray(saji, idx)==IdxUndefDiner || idx!=pesanan.buffer[pesanan.idxHead].id_makanan) && (!compareSTR(perintah, "SKIP"))){
            if (compareSTR(perintah, "SERVE") && idx!=pesanan.buffer[pesanan.idxHead].id_makanan){
                printf("%s belum dapat disajikan karena M%d belum selesai\n", makanan, pesanan.buffer[pesanan.idxHead].id_makanan);}

            else{
            printf("\nMasukan tidak valid. Silahkan coba lagi.\n");}
            printf("MASUKKAN COMMAND: ");


            command = Input();
            perintah = FirstSTR(command);
            makanan = SecSTR(command);

            int idx = fromStr(makanan);

        }

        putaran(&idpesanan, &pesanan, &masak, &saji);

        system("CLS");


        if (compareSTR(perintah, "COOK")) {
                AddEl(&masak, pesanan.buffer[SearchIdIn(pesanan, idx)]);
                    
                printf("\nBerhasil memasak %s\n", makanan);              
            
        }


        else if (compareSTR(perintah, "SERVE")) {

            DelEl(&saji, &val, SearchIdArray(saji, idx));
            printf("\nBerhasil mengantar %s\n", makanan);
            serve++;
            saldo += val.harga;
            dequeueDiner(&pesanan, &val);
            
        }

        else if (compareSTR(perintah, "SKIP")){
            printf("\nSkip berhasil\n");
        }

        printf("==========================================================\n\n");
  
    }

    printf("GAME OVER!!!\n\nSkor akhir: %d\n\n", saldo);
}