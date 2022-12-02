# Tubes 2 IF2111 Kelompok 2

Program dibuat dengan menggunakan bahasa C menggunakan ADT Array, Queue, Mesin Karakter, Mesin Kata, Set, Map, Stack, Tree, dan Linked List yang sudah dipelajari di kelas IF2111 Algoritma dan Struktur Data. Pada awal permainan, user akan diminta untuk melakukan input command START / LOAD terlebih dahulu. Setelah melakukan command awal pemain dapat melakukan input CREATE GAME, LIST GAME, DELETE GAME, HISTORY <n>, RESET HISTORY, SCOREBOARD, RESET SCOREBOARD, QUEUE GAME, PLAY GAME, SKIP GAME <n>, SAVE <filename>, HELP, dan QUIT.
<br/><br/>
Dalam BNMO ini terdapat 7 game yang sudah bisa dimainkan yaitu:
- RNG
- Diner Dash
- RPS (Rock, Paper, Scissor)
- Hangman
- Tower of Hanoi
- Snake on Meteor
- Guessing Number <br/><br/>

Tugas dibuat oleh kelompok 2:
| No.| Nama                          |  NIM     | 
|:--:| :---------------------------: | :------: |
| 1. | Frendy Sanusi                 | 18221041 |
| 2. | Nadira Rahmananda Arifandi    | 18221059 |
| 3. | Nicolas Owen Halim            | 18221095 |
| 4. | Ivan Leovandi                 | 18221129 | 
| 5. | Gabriel P. Halomoan Panjaitan | 18221159 |
<br/>
Cara memulai program BNMO : 

#### 1. Pindah direktori
```
cd ./bin
```
#### 2. Jalankan makefile
```
make # {nama_file}

# Terdapat beberapa konfigurasi makefile:
# - Program utama: main
# - Program testing ADT: mesintest, arraytest, arraydiner, stacktest, treetest

# Contoh penggunaan:
# make main
```
#### 3. Jalankan program
```
1. Untuk program utama: make exec
2. Untuk program testing ADT:
   - {nama_file} # bila OS yang digunakan adalah Windows
   - ./{nama_file} # bila OS yang digunakan adalah Linux
```
