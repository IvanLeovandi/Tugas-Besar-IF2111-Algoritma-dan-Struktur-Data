/* File hangman.c */
#include "hangman.h"

void Hangman(Array *Kamus, int *score_game){
/* 
Spesifikasi game : Pemain menebak satu huruf yang terdapat pada kata tersebut. 
Apabila huruf tebakan terdapat dalam kata, maka huruf yang sudah tertebak akan 
ditampilkan pada layar. Apabila salah, maka pemain kehilangan satu kesempatan. 
Pemain tidak boleh menebak huruf yang sudah ditebak sebelumnya pada kata yang sama. 
Apabila pemain berhasil menebak suatu kata, maka pemain tersebut diberikan poin 
sesuai dengan panjang kata yang berhasil ditebak, kemudian program memberikan kata 
baru yang harus ditebak oleh pemain dengan jumlah kesempatan yang tersisa. Permainan 
akan berlanjut hingga pemain kehabisan kesempatan untuk menebak huruf yang salah
*/
    /*KAMUS LOKAL*/
    Array Penanda;
    Queue huruftebakan;
    int score, percobaan;
    char* InputTebakan;
    char tebakan;
    ElType Kata, KataBaru;
    int index_kamus;
    int opsi;
    boolean win;
    boolean valid;
    /*ALGORITMA*/
    printf("Selamat datang di Hangman!\n\n");
    printf("Menu.\n\n");

    MakeEmpty(&Penanda);
    CreateQueue(&huruftebakan);
    valid = false;

    while (valid == false){
        printf("1. Mulai Game\n");
        printf("2. Tambah Kata Baru\n");
        printf("Masukkkan nomor opsi: ");
        opsi = StrToInt(Input());
        if (opsi == 1 || opsi == 2){
            valid == true;
            printf("\nLoading..\n");
            break;
        }else{
            printf("Masukkan tidak valid, silahkan input ulang!\n\n");
        }
    }

    if (opsi == 1){
        percobaan = 10;
        score = 0;
        while (percobaan > 0){
            printf("Kata yang harus ditebak: \n");
            srand(time(NULL));
            index_kamus = rand()% (Kamus->Neff -1);
            Kata = Kamus->TI[index_kamus];
            CreateArrayPenanda(Kata, &Penanda);
            while (percobaan >0 && IsWin(Penanda) == false){
                CetakHuruf(Kata,Penanda);
                printf("\nSisa Percobaan : %d\n",percobaan);
                printf("Masukkan Tebakan :");
                InputTebakan = Input();
                printf("\n");
                while (str_len(InputTebakan) != 1 ){
                    printf("\nTebakan Harus 1 Huruf\n");
                    printf("Masukkan Tebakan :");
                    InputTebakan = Input();
                }
                while ((InputTebakan[0]<'A' || (InputTebakan[0] > 'Z' && InputTebakan[0] < 'a') || InputTebakan[0] > 'z')){
                    printf("\nTebakan Harus berupa Huruf\n");
                    printf("Masukkan Tebakan :");
                    InputTebakan = Input();
                }
                tebakan = *InputTebakan;
                while (haveguess(huruftebakan, tebakan)){
                    printf("\nHuruf yang ditebak sudah ditebak sebelumnya!\n");
                    printf("Masukkan Tebakan :");
                    InputTebakan = Input();
                    tebakan = *InputTebakan;
                    printf("\n");
                }
                enqueue(&huruftebakan, tebakan);
                if (IsElement(Kata, tebakan) == false){
                    percobaan = percobaan - 1;
                }

                ChangeArrayPenanda(Kata, &Penanda, tebakan);
                if (percobaan > 0 && IsWin(Penanda) == false){
                    printf("\nHuruf yang anda tebak sebelumnya :\n");
                    displayQueue(huruftebakan);
                }
                if(IsWin(Penanda)){
                    score += str_len(Kata);
                    printf("\nWow Bagus, Lanjut Kata Selanjutnya!!!\n");
                    printf("\nScore sementara anda adalah %d\n", score);
                    CreateQueue(&huruftebakan);
                }
            }
        }
        printf("\nYey, Score akhir anda adalah %d\n", score);
        *score_game = score;
    }else{
        printf("\nMasukkan Kata Baru :");
        KataBaru = Input();
        if (IsElmt(*Kamus, KataBaru) == false && IsFull(*Kamus) == false ){
            Kamus->TI[Kamus->Neff] = KataBaru;
            Kamus->Neff += 1;
        }else if (IsElmt(*Kamus, KataBaru)){
            printf("Kata sudah ada dalam kamus\n");
        }else if (IsFull(*Kamus)){
            printf("Kamus telah penuh\n");
        }
    }
}
void CreateArrayPenanda(char * Kata, Array* Penanda){
/* membuat array dengan elemen '0' dan '1' dengan jumlah elemen
   sama dengan jumlah elemen pada kata
   contoh : Kata : [M,A,K,A,N] maka dihasilkan array [0,0,0,0,0]
*/  
    /*KAMUS LOKAL*/
    MakeEmpty(Penanda);
    int i;
    /*ALGORITMA*/
    Penanda->Neff = str_len(Kata);
    for (i = 0; i < Penanda->Neff; i++){
        Penanda->TI[i] = "0";
    }
}


void CetakHuruf(char* Kata, Array Penanda){
/* Menampilkan kata kata yang sudah ditebak
*/
    /* KAMUS LOKAL*/
    int i;
    int jumlah;
    /*ALGORITMA*/
    jumlah = Penanda.Neff;
    for(i = 0; i < jumlah; i++){
        if(Penanda.TI[i] == "0"){
            printf("__ ");
        }else if (Penanda.TI[i] == "1"){
            printf("%c ", Kata[i]);
        }
    }
}

boolean IsElement(ElType kata, char tebakan){
/* Menghasilkan True jika huruf pada tebakan terdapat dalam array kata
*/  
    /*KAMUS LOKAL*/
    boolean found;
    int i;
    /*ALGORITMA*/
    found = false;
    for (i = 0; i < str_len(kata); i++){
        if (kata[i] == tebakan || kata[i] == tebakan - 32){
            found = true;
        }
    }
    return found;
}

boolean haveguess(Queue huruftebakan, char tebakan){
/* menghasilkan true jika huruf yang ditebak sudah pernah ditebak
*/
    /*KAMUS LOKAL*/
    boolean found;
    /*ALGORITMA*/
    found = false;
    if (SearchElmtQueue(huruftebakan, tebakan)){
        found = true;
    }
    return found;
}

void ChangeArrayPenanda(ElType Kata, Array* Penanda, char tebakan){
/* Mengubah state pada Penanda.
   Kata : [M,A,K,A,N]
   tebakan : 'A'
   Penanda : [0,0,0,0,0] --> [0,1,0,1,0]
*/
    /*KAMUS LOKAL*/
    int i, jumlah;
    /*ALGORITMA*/
    jumlah = NbElmt((*Penanda));
    for(i = 0; i < jumlah; i++){
        if(Kata[i] == tebakan || Kata[i] == tebakan - 32){
            Penanda->TI[i] = "1";
        }
    }
}

boolean IsWin(Array Penanda){
/* Menghasilkan true jika semua elemen pada Penanda berelemen '1'
*/
    /*KAMUS LOKAL*/
    int i, jumlah;
    boolean found;
    /*ALGORITMA*/
    jumlah = Penanda.Neff;
    found = true;
    i = 0;
    while(found && i < jumlah){
        if(Penanda.TI[i] == "0"){
            found = false;
        }
        i += 1;
    }
    return found;
}