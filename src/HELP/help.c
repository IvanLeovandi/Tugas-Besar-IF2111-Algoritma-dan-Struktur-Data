#include <stdio.h>
#include "help.h"

void help(boolean loaded){
    /* Prosedur melakukan print perintah-perintah yang dapat dilakukan. */
    printf("\n^.^ Anda sedang menggunakan game console BNMO ^.^\n\n");
    printf("Berikut daftar command yang dapat Anda gunakan serta fungsinya!\n");
    if(loaded == false)
    {
        printf("===================  PERINTAH  ===================\n");
        printf("START          : Melakukan set up game console BNMO\n");
        printf("LOAD <filename>: Melakukan set up game dari file masukan\n");
        printf("QUIT           : Keluar dari game console\n");
        printf("HELP           : Menampilkan daftar command\n\n");
    } else
    {
        printf("===================  PERINTAH  ===================\n");
        printf("SAVE <filename> : Menyimpan keadaan game ke dalam file\n");
        printf("CREATE GAME     : Menambahkan game baru pada daftar game\n");
        printf("LIST GAME       : Menampilkan daftar game yang ada\n");
        printf("DELETE GAME     : Menghapus sebuah game dari daftar game\n");
        printf("                  Game yang dapat dihapus hanyalah game yang sedang tidak ada di queue \n");
        printf("                  dan bukan merupakan 5 game pertama pada file konfigurasi.\n");
        printf("HISTORY <n>     : Menampilkan n buah permainan yang terakhir dimainkan.\n");
        printf("RESET HISTORY   : Menghapus seluruh history.\n");
        printf("SCOREBOARD      : Menampilkan daftar skor dan pemain tiap game.\n");
        printf("RESET SCOREBOARD: Menghapus seluruh scoreboard.\n");        
        printf("QUEUE GAME      : Menambahkan permainan pilihan ke dalam daftar antrian game\n");
        printf("PLAY GAME       : Memainkan game pertama dalam daftar antrian game\n");
        printf("SKIPGAME <n>    : Menghapus n buah game dari daftar antrian dan memainkan game ke-(n+1)\n");
        printf("QUIT            : Keluar dari game console\n");
        printf("HELP            : Menampilkan daftar command\n\n");

        printf("=============  KETERANGAN PERMAINAN  =============\n");
        printf("RNG            : Permainan menebak angka.\n");
        printf("DINER DASH     : Permainan memasak dan menyajikan makanan.\n");
        printf("HANGMAN        : Permainan menebak huruf-huruf dari sebuah kata.\n");
        printf("TOWER OF HANOI : Permainan menggeser balok-balok dari tiang kiri ke tiang kanan.\n");
        printf("                 Balok yang lebih besar tidak boleh ditaruh di atas balok yang lebih kecil.\n");
        printf("SNAKE ON METEOR: Permainan menggerakkan ular untuk memakan makanan dan menghindari meteor dan obstacle.\n");
        printf("---------------------------------------------------------------------------------------\n\n");
    }
    printf("Ketik command yang ingin Anda jalankan. Kemudian ketik enter untuk menjalankannya.\n");
    printf("Selamat bermain!~~\n");
}
