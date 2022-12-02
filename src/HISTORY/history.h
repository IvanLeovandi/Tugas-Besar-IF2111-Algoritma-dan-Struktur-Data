#include "../adt/Mesin/mesinkata.h"
#include "../adt/Stack/stackhistory.h"

#ifndef HISTORY_H
#define HISTORY_H

void show_hist(StackHis history, int n);
/*I.S. StackHis Terdefinisi, StackHis Mungkin Kosong. */
/*F.S. Mencetak elemen pada StackHis sebanyak n. */

void reset_hist(StackHis *history);
/*I.S. StackHis Terdefinisi, StackHis Mungkin Kosong. */
/*F.S. Menghapus seluruh elemen history pemain jika menjawab "YA" */
/*     Jika pemain menjawab "TIDAK", maka history batal dihapus. */
/*     Program akan menampilkan pesan error jika masukkan diluar dari YA dan TIDAK
       dan meminta masukan ulang dari pemain. */

#endif