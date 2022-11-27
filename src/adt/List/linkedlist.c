#include "linkedlist.h"

boolean IsSnakeEmpty (snakeList L){
    return (Head(L) == Nil && Tail(L)==Nil);
}


void CreateEmptySnake (snakeList *L){
    Head(*L) = Nil;
    Tail(*L) = Nil;
}



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


point NewPoint (snakeList L, point obstacle){
    point new;
    new.x = randomNumberMinMax(0, 4);
    new.y = randomNumberMinMax(0, 4);

    boolean found = false;
    adrSnake P = Head(L);

    while (obstacle.x == new.x && obstacle.y == new.y){
        new.x = randomNumberMinMax(0, 4);
        new.y = randomNumberMinMax(0, 4);
        P = Head(L);
    }

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


void DealokasiSnake (adrSnake *P){
    free(*P);
}

adrSnake SearchSnake (snakeList L, int X, int Y){
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

int nbSnake (snakeList L){
    adrSnake P = Head(L);
    int count = 0;
    while (P!= Nil){
        count ++;
        P = Next(P);
    }
    return count;    
}

void InsertFirstSnake (snakeList *L, adrSnake P){
    Next(P) = Head(*L);
    Head(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-adrSnake P sebagai elemen pertama */
void InsertAfterSnake (snakeList *L, adrSnake P, adrSnake Prec){
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLastSnake (snakeList *L, adrSnake P){
    adrSnake S = Head(*L);
    if (S==Nil){
        Head(*L) = P;
    }
    else{
    while (Next(S)!=Nil){
        S = Next(S);
    }
    InsertAfterSnake(L, P, S);
    }   
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstSnake (snakeList *L, adrSnake *P){
    *P = Head(*L);
    Head(*L) = Next(*P);
    Next(*P) = Nil;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelPSnake (snakeList *L, point X){
    adrSnake P, Prec; 
 
    P = SearchSnake(*L, X.x, X.y); 
    Prec = Head(*L); 
 
    if (P != Nil) { 
        if (P == Prec) { 
            DelFirstSnake(L, &P); 
        } else { 
            while (Next(Prec) != P) { 
                Prec = Next(Prec); 
            } 
            DelAfterSnake(L, &P, Prec); 
        } 
    } 
    DealokasiSnake(&P); 
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beradrSnake P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLastSnake (snakeList *L, adrSnake *P){
    adrSnake prec, last; 
 
    last = Head(*L); 
    prec = Nil; 
 
    while (Next(last) != Nil) { 
        prec = last; 
        last = Next(last); 
    } 
    *P = last; 
 
    if (prec == Nil) { 
        Head(*L) = Nil; 
    } else { 
        Next(prec) = Nil; 
    } 
}

/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfterSnake (snakeList *L, adrSnake *Pdel, adrSnake Prec){
    *Pdel = Next(Prec); 
    if (*Pdel != Nil) { 
        Next(Prec) = Next(*Pdel); 
    } 
    Next(*Pdel) = Nil; 
}