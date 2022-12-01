/* File hangman.c */
#include "hangman.h"
#include "../clear.h"

void Hangman(int *score_game){
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
    Array Penanda, Kamus;
    QueueHangman huruftebakan;
    int score, percobaan;
    char* InputTebakan;
    char tebakan;
    ElType Kata, KataBaru;
    int index_kamus;
    int opsi;
    boolean win;
    boolean valid;
    boolean validitas;
    char body[11] = {'\0'}; /* hangman body */
    /*ALGORITMA*/
    printf("Selamat datang di Hangman!\n\n");
    printf("Menu.\n\n");

    MakeEmpty(&Penanda);
    CreateQueueHangman(&huruftebakan);
    MakeEmpty(&Kamus);
    valid = false;

    while (valid == false){
        printf("1. Mulai Game\n");
        printf("2. Tambah Kata Baru\n\n");
        printf("Masukkkan nomor opsi: ");
        opsi = StrToInt(Input());
        if (opsi == 1 || opsi == 2){
            valid == true;
            ClearScreen();
            printf("\nLoading...\n");
            break;
        }else{
            printf("Masukkan tidak valid, silahkan input ulang!\n\n");
        }
    }
    KamusToArray(&Kamus);
    if (opsi == 1){
        percobaan = 10;
        score = 0;
        while (percobaan > 0){
            printf("Bahasa yang digunakan pada game ini adalah bahasa Indonesia.\n\n");
            printf("Kata yang harus ditebak: \n");
            index_kamus = randomNumber() % (Kamus.Neff -1);
            Kata = Kamus.TI[index_kamus];
            CreateArrayPenanda(Kata, &Penanda);
            while (percobaan >0 && IsWin(Penanda) == false){
                CetakHuruf(Kata,Penanda);
                printf("\n\nSisa Percobaan: %d\n\n",percobaan);
                printf("Masukkan Tebakan: ");
                InputTebakan = Input();
                printf("\n");
                while (str_len(InputTebakan) != 1 ){
                    ClearScreen();
                    printf("\nHuruf yang anda tebak sebelumnya: \n\n");
                    displayQueueHangman(huruftebakan);
                    CetakHuruf(Kata,Penanda);
                    printf("\n\nTebakan Harus 1 Huruf\n\n");
                    printf("Masukkan Tebakan: ");
                    InputTebakan = Input();
                }
                while ((InputTebakan[0]<'A' || (InputTebakan[0] > 'Z' && InputTebakan[0] < 'a') || InputTebakan[0] > 'z')){
                    ClearScreen();
                    printf("\nHuruf yang anda tebak sebelumnya: \n\n");
                    displayQueueHangman(huruftebakan);
                    CetakHuruf(Kata,Penanda);
                    printf("\n\nTebakan harus berupa Huruf\n\n");
                    printf("Masukkan Tebakan: ");
                    InputTebakan = Input();
                }
                ClearScreen();
                tebakan = *InputTebakan;
                while (haveguess(huruftebakan, tebakan)){
                    PrintBody(10 - percobaan, body);
                    printf("\nHuruf yang ditebak sudah ditebak sebelumnya!\n\n");
                    printf("\nHuruf yang anda tebak sebelumnya: \n\n");
                    displayQueueHangman(huruftebakan);
                    CetakHuruf(Kata,Penanda);
                    printf("\n\nMasukkan Tebakan: ");
                    InputTebakan = Input();
                    tebakan = *InputTebakan;
                    printf("\n");
                }
                enqueueHangman(&huruftebakan, tebakan);
                if (IsElement(Kata, tebakan) == false){
                    percobaan = percobaan - 1;
                }
                PrintBody(10 - percobaan, body);

                ChangeArrayPenanda(Kata, &Penanda, tebakan);
                if (percobaan > 0 && IsWin(Penanda) == false){
                    printf("\nHuruf yang anda tebak sebelumnya: \n\n");
                    displayQueueHangman(huruftebakan);
                }
                if(IsWin(Penanda)){
                    score += str_len(Kata);
                    printf("Jawaban yang benar: %s\n", Kata);
                    printf("\nWow bagus! Kamu mendapatkan %d poin. GGWP!! Let's go lanjut kata berikutnya!!!\n", str_len(Kata));
                    printf("\nScore sementara anda adalah %d\n\n\n", score);
                    CreateQueueHangman(&huruftebakan);
                }
            }
        }
        printf("Jawaban yang benar: %s\n", Kata);
        printf("\nYey, Score akhir anda adalah %d\n\n", score);
        *score_game = score;
    }else{
        printf("\nMasukkan Kata Baru: ");
        KataBaru = Input();
        if (IsElmt(Kamus, KataBaru) == false && IsFull(Kamus) == false ){
            Kamus.TI[Kamus.Neff] = KataBaru;
            Kamus.Neff += 1;
        }else if (IsElmt(Kamus, KataBaru)){
            printf("Kata sudah ada dalam kamus\n");
        }else if (IsFull(Kamus)){
            printf("Kamus telah penuh\n");
        }
        SaveKamus(Kamus);
        printf("\n\n");
        Hangman(score_game);
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

boolean haveguess(QueueHangman huruftebakan, char tebakan){
/* menghasilkan true jika huruf yang ditebak sudah pernah ditebak
*/
    /*KAMUS LOKAL*/
    boolean found;
    /*ALGORITMA*/
    found = false;
    if (SearchElmtQueueHangman(huruftebakan, tebakan)){
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

void KamusToArray(Array* Kamus){
/*  I.S. Array Kamus berupa array kosong
    F.S. Membuat suatu Array pada suatu Kamus*/
    //Kamus Lokal
    boolean valid;
    int idx, i;
    //ALGORITMA
    valid = StartLOAD("../data/kamus.txt");
    if (valid){
        i = 0;
        while(!EOP){
            char *strkata;
            strkata = (char *)malloc(currentWord.Length * sizeof(char));
            if(strkata != NULL){
                for (idx = 0; idx < currentWord.Length; idx++ ){
                    *(strkata + idx) = currentWord.TabWord[idx];
                }
                *(strkata + currentWord.Length) = '\0';
                Kamus->TI[i] = strkata;
                i += 1;
                Kamus->Neff += 1;
            }
            ADVWORDLOAD();
        }
        char *strkata;
            strkata = (char *)malloc(currentWord.Length * sizeof(char));
            if(strkata != NULL){
                for (idx = 0; idx < currentWord.Length; idx++ ){
                    *(strkata + idx) = currentWord.TabWord[idx];
                }
                *(strkata + currentWord.Length) = '\0';
                Kamus->TI[i] = strkata;
                i += 1;
                Kamus->Neff += 1;
            }
    }
}

void SaveKamus(Array Kamus){
/* Menyimpan kata kata dalam array kamus ke kmus.txt*/
    /*KAMUS LOKAL*/
    FILE *outp;
    int count, idx;
    /*ALGORITMA*/
    outp = fopen("../data/kamus.txt", "w+");
    count = Kamus.Neff;
    for (idx = 0; idx < count; idx++){
        if (idx != count -1){
            fprintf(outp,"%s\n",Kamus.TI[idx]);
        }else{
            fprintf(outp,"%s",Kamus.TI[idx]);
        }
    }
    fclose(outp);
}

void PrintBody(int mistakes, char* body) {
/* Menampilkan gambar hangman ke layar */
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
	switch (mistakes) {
        case 10:
            body[9] = '\\';
            break;
        case 9:
            body[8] = '\\';
            break;
        case 8:
            body[7] = '/';
            break;
        case 7:
            body[6] = '|';
            break;
		case 6:
            body[5] = '-';
            break;
		case 5:
            body[3] = '-';
            break;
		case 4:
            body[3] = ' ';
            body[4] = '|';
            break;
		case 3:
            body[2] = ')';
            break;
		case 2:
            body[1] = '(';
            break;
		case 1:
            body[0] = '|';
            break;
		default:
            break;
	}

    printf("\t");
    for (i = 0; i < 9; i++) {
        #ifdef _WIN32
            printf("%c", 196);
        #else
            printf("%s", "\u2500");
        #endif
    }
    printf("\n");

    printf("\t|       %c\n"
	       "\t|      %c %c\n"
	       "\t|      %c%c%c\n"
           "\t|       %c  \n"
	       "\t|      %c %c%c\n"
	       "\t|             \n"
	       "\t|             \n\n",
           body[0], body[1], body[2], body[3], body[4], body[5], body[6], body[7],
           body[8], body[9]);
}