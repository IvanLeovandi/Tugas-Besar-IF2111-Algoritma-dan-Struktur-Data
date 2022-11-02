#include <stdio.h>
#include "help.h"

void help(){
    /* Prosedur melakukan print perintah-perintah yang dapat dilakukan. */

    printf("^.^ Anda sedang menggunakan game console BNMO ^.^\n\n");
    printf("Berikut daftar command yang dapat Anda gunakan serta fungsinya!\n");
    printf("START          : Melakukan set up game console BNMO\n");
    printf("LOAD <filename>: Membaca list dan histori dari file masukan\n");
    printf("SAVE <filename>: Menyimpan keadaan game ke dalam file\n");
    printf("CREATEGAME     : Menambahkan game baru pada daftar game\n");
    printf("DELETEGAME     : Menghapus sebuah game dari daftar game\n");
    printf("                 Game yang dapat dihapus hanyalah game yang sedang tidak ada di queue \n");
    printf("                 dan bukan merupakan 5 game pertama pada file konfigurasi.\n");
    printf("QUEUE GAME     : Menambahkan permainan pilihan ke dalam daftar antrian game\n");
    printf("PLAY GAME      : Memainkan game pertama dalam daftar antrian game\n");
    printf("SKIP GAME <n>  : Menghapus n buah game dari daftar antrian dan memainkan game ke-(n+1)\n");
    printf("QUIT           : Keluar dari game console\n");
    printf("HELP           : Menampilkan daftar command\n\n");
    printf("Ketik command yang ingin Anda jalankan. Kemudian ketik enter untuk menjalankannya.\n");
    printf("Selamat bermain!~~\n");
}
