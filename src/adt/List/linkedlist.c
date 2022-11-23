#include "linkedlist.h"

/* PROTOTYPE */
/****************** TEST Snake KOSONG ******************/
boolean IsEmpty (snakeList L){
    return (Head(L) == Nil && Tail(L)==Nil);
}
/* Mengirim true jika Snake kosong */

/****************** PEMBUATAN Snake KOSONG ******************/
void CreateEmpty (snakeList *L){
    Head(*L) = Nil;
    Tail(*L) = Nil;
}

void CreatePeta (snakeList *L, point* food){
    CreateEmpty(L);
    int X = randomNumberMinMax(0, 4);
    int Y = randomNumberMinMax(0, 4);

    adrSnake P = AlokasiSnake(X, Y, 'x');
    Head(*L) = P;
    Tail(*L) = P;

    InsertSnake(L);
    InsertSnake(L);

    *food = NewPoint(*L);
}

void InsertSnake (snakeList *L){
    int X = (Point(Tail(*L)).x + 4) % 5 ;
    int Y = Point(Tail(*L)).y;
    char prev = 'd';

    if (Search(*L, X, Y) != Nil){
        X = Point(Tail(*L)).x;
        Y = (Point(Tail(*L)).y + 4) % 5;
        prev = 's';

        if (Search(*L, X, Y) != Nil){
            X = Point(Tail(*L)).x + 1 & 5;
            Y = Point(Tail(*L)).y;
            prev = 'a';

            if (Search(*L, X, Y) != Nil){
                X = Point(Tail(*L)).x;
                Y = Point(Tail(*L)).y + 1 % 5;
                prev = 'w';
            }
        }
    }

    SetNext (L, X, Y, prev);
}

/* I.S. sembarang             */
/* F.S. Terbentuk Snake kosong */

/****************** Manajemen Memori ******************/
adrSnake AlokasiSnake (int X, int Y, char prev){
    adrSnake p = (adrSnake) malloc (sizeof(Snake));
    while (p==Nil){
        adrSnake p = (adrSnake) malloc (sizeof(Snake));}

    Point(p).x = X;
    Point(p).y = Y;
    Dir(p).prec = prev;
    Dir(p).succ = 'x';
    Next(p) = Nil;

    return p;
}

void SetNext (snakeList *L, int X, int Y, char prev){
    adrSnake P = AlokasiSnake(X, Y, prev);

    if(prev == 'a'){
        Dir(Tail(*L)).succ = 'd';
    } else if (prev == 'w'){
        Dir(Tail(*L)).succ = 's';
    } else if (prev == 's'){
        Dir(Tail(*L)).succ = 'w';
    } else if (prev == 'd'){
        Dir(Tail(*L)).succ = 'a';
    }

    Next(Tail(*L)) = P;
    Tail(*L) = P;
}

point NewPoint (snakeList L){
    point new;
    new.x = randomNumberMinMax(0, 4);
    new.y = randomNumberMinMax(0, 4);

    boolean found = false;
    adrSnake P = Head(L);
    while (P!= Nil){
        if (Point(P).x == new.x && Point(P).y == new.y){
            new.x = randomNumberMinMax(0, 4);
            new.y = randomNumberMinMax(0, 4);
            P = Head(L);
        } else {
            P = Next(P);
        }
    }   

    return new;
}

/* Mengirimkan adrSnake hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka adrSnake tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void DealokasiSnake (adrSnake *P){
    free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian adrSnake P */

/****************** PENCARIAN SEBUAH ELEMEN Snake ******************/
adrSnake Search (snakeList L, int X, int Y){
    adrSnake p = Head(L);
    boolean found = false;

    while (p!= Nil && !found){
        if (Point(p).x ==X && Point(p).y == Y){
            found = true;
        }
        else{p = Next(p);}
    }

    return p;
}
/* Mencari apakah ada elemen Snake dengan info(P)= X */
/* Jika ada, mengirimkan adrSnake elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/

/* I.S. Sembarang */
/* F.S. Jika ada elemen Snake beradrSnake P, dengan info(P)=X  */
/* Maka P dihapus dari Snake dan di-dealokasi */
/* Jika tidak ada elemen Snake dengan info(P)=X, maka Snake tetap */
/* Snake mungkin menjadi kosong karena penghapusan */


/****************** PROSES SEMUA ELEMEN Snake ******************/

/* I.S. Snake mungkin kosong */
/* F.S. Jika Snake tidak kosong, iai Snake dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Snake kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int SnakeScore (snakeList L){
    adrSnake P = Head(L);
    int count = 0;
    while (P!= Nil){
        count += 2;
        P = Next(P);
    }
    return count;    
}
/* Mengirimkan banyaknya elemen Snake mengirimkan 0 jika Snake kosong */


void PrintSnake(snakeList L, point food, point meteor){
    printf("\n\nBerikut merupakan peta permainan\n");

    int a, b, c, d, e, f, g, h, i, j, k, s;
    a = 179; b = 180; c = 191;
    d = 192; e = 193; f = 194;
    g = 195; h = 196; i = 197;
    j = 217; k = 218; s = 178;
    int head = 1, tail = 4, mete = 19;

    for (int m=0; m<6; m++){
        for (int o=0; o<5; o++){
            if (m==0){
                if (o==0){printf("%c", k);}
                else {printf("%c", f);}
            } else if(m==5){
                if (o==0){printf("%c", d);}
                else {printf("%c", e);}
            } else {
                if (o==0){printf("%c", g);}
                else {printf("%c", i);}
            }

            printf("%c%c%c%c%c%c%c%c%c",h,h,h,h,h,h,h,h,h);

            if (o==4){
                if (m==0){
                    printf("%c", c);
                } else if (m==5) {
                    printf("%c", j);
                } else {
                    printf("%c", b);
                }
            }
        }
        printf("\n");
        
        if (m!=5){
            for (int n=0; n<3; n++){
                for (int o=0; o<5; o++){
                    adrSnake P = Search(L, o, m);
                    if (P == Nil){
                        if (n==1){
                            if (o == food.x && m == food.y){
                                printf("%c    o    ", a);
                            }
                            else if (o == meteor.x && m == meteor.y){
                                printf("%c    %c    ", a, mete);
                            } else {printf("%c         ", a);}
                        }
                        else{printf("%c         ", a);}
                    } else{
                        if(n==0){
                            if(Dir(P).prec == 'w' || Dir(P).succ == 'w'){
                                printf("%c   %c%c%c   ", a, s, s, s);
                            } else {printf("%c         ", a);}
                        }
                        
                        else if(n==1){                            
                            if(Dir(P).prec == 'a' || Dir(P).succ == 'a'){
                                printf("%c%c%c%c%c", a, s, s, s, s);
                            } else {
                                if(Dir(P).prec == 'x' || Dir(P).succ =='x'){
                                    printf("%c    ", a);
                                } else {printf("%c   %c", a, s);}
                            }

                            /* head */
                            if(Dir(P).prec == 'x'){
                                printf("%c", head);
                            } else if(Dir(P).succ =='x'){
                                printf("%c", tail);
                            } else {printf("%c",s);}

                            if(Dir(P).prec == 'd' || Dir(P).succ == 'd'){
                                printf("%c%c%c%c", s, s, s, s);
                            } else{                                
                                if(Dir(P).prec == 'x' || Dir(P).succ =='x'){
                                    printf("    ");
                                } else {printf("%c   ", s);}}
                        }
                        
                        else{
                            if(Dir(P).prec == 's' || Dir(P).succ == 's'){
                                printf("%c   %c%c%c   ", a, s, s, s);
                            } else {printf("%c         ", a);}
                        }
                    }
                }
                printf("%c\n", a);
                }
                
            }
        
    }
}

void PrintGaris(){
    int h = 196;
    printf("%c%c%c%c%c%c%c%c%c",h,h,h,h,h,h,h,h,h);
}