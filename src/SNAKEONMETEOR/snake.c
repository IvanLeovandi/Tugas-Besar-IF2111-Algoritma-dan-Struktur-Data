#include <stdio.h>
#include <stdlib.h>

#include "snake.h"

void SnakeOnMeteor(int *score_game){
    printf("Selamat datang di snake on meteor!\n\n");
    printf("Mengenerate peta, snake dan makanan");
    loadingDelay();
    printf("\n\n");

    snakeList snake;
    point food, meteor, obstacle;
    boolean game = true; 
    int turn = 1;
    CreatePeta(&snake, &food, &obstacle);
    meteor.x = -1;
    meteor.y = -1;

    char *command;
    
    printf("Berhasil digenerate!\n\n");
    PrintGaris(); PrintGaris(); PrintGaris(); PrintGaris(); PrintGaris(); PrintGaris(); 
    PrintSnake(snake, food, meteor, obstacle);

    while (game){
        printf("\nTURN %d\n", turn);
        printf("Silahkan masukkan command anda: ");
        command = Input();
        ClearScreen();
        if (str_len(command) == 1){
            Move(*command, &snake, &food, &game, &meteor, obstacle, &turn);
            PrintSnake(snake, food, meteor, obstacle);
        }
        else{
            printf("\nCommand tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n");
        }
    }

    int score = nbSnake(snake);
    printf("Game berakhir. Skor: %d\n\n", score);
    *score_game = score;
}

void Move (char command, snakeList *L, point* food, boolean* game, point* meteor, point obstacle, int* turn){
    /* Snake bergerak */
    point cek, temppo;
    adrSnake P = Head(*L);
    char prev = command;
    char next, tempprev, tempnext;

    /* Validasi input */
    if (command == 'a'){
        cek.x = (Point(P).x+4) %5; 
        cek.y = Point(P).y;
        next = 'd';
    } else if (command == 'w'){
        cek.x = Point(P).x; 
        cek.y = (Point(P).y + 4) % 5;
        next = 's';
    } else if (command == 'd'){
        cek.x = (Point(P).x+1) % 5; 
        cek.y = Point(P).y;
        next = 'a';
    } else if (command == 's') {
        cek.x = Point(P).x; 
        cek.y = (Point(P).y + 1) % 5;
        next = 'w';
    } else {
        printf("Command tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n");
        return;
    }

    P = Next(P);

    /* Validasi kepala */
    if (Point(P).x == cek.x && Point(P).y == cek.y){
        printf("Anda tidak dapat bergerak ke tubuh anda sendiri!\nSilahkan input command yang lain\n");
        return;
    }
    else{
        while (Next(P)!=Nil){
            if (Point(P).x == cek.x && Point(P).y == cek.y){
                printf("Anda menabrak badan sendiri!\n");
                (*game) = false;
                Meteor(L, game, meteor, *food, obstacle);
                return;
            } else{P = Next(P);}
        }
    }

    if (cek.x == (*meteor).x && cek.y == (*meteor).y){
        printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\nSilahkan masukkan command lainnya\n");
        return;
    }

    P = Head(*L);

    Dir(P).prec = prev;

    while (Next(P)!= Nil){
        temppo = Point(P);
        tempprev = Dir(P).prec;
        tempnext = Dir(P).succ;
        Point(P) = cek;
        Dir(P).succ = next;
        Dir(P).prec = prev;
        next = tempnext;
        prev = tempprev;
        cek = temppo;
        P = Next(P);
    }
    Point(P) = cek;
    Dir(P).prec = prev;

    Dir(Head(*L)).prec = 'x';

    printf("\nBerhasil bergerak!\n");

    Food(L, food, obstacle);

    if(*turn != 1){
        Meteor(L, game, meteor, *food, obstacle);
    }

    (*turn) ++;

    P = Head(*L);

}

void Food (snakeList *L, point *food, point obstacle){
    /* Snake memanjang */
    adrSnake(P) = Head(*L);

    if (Point(P).x == (*food).x && Point(P).y == (*food).y){
        InsertSnake(L);
        *food = NewPoint(*L, obstacle);
    }
}

void Meteor (snakeList *L, boolean *game, point* meteor, point food, point obstacle){
    /* Randomize bom dan hit jika mengenai snake */
    (*meteor).x = randomNumberMinMax(0,4);
    (*meteor).y = randomNumberMinMax(0,4);

    while (((*meteor).x == food.x && (*meteor).y == food.y) || ((*meteor).x == obstacle.x && (*meteor).y == obstacle.y)){
        (*meteor).x = randomNumberMinMax(0,4);
        (*meteor).y = randomNumberMinMax(0,4);
    }

    adrSnake P = Head(*L);

    if (Point(P).x == (*meteor).x && Point(P).y == (*meteor).y){
        adrSnake Q = Head(*L);
        Head(*L) = Next(Head(*L));

        DealokasiSnake(&Q);

        printf("Kepala snake terkena meteor!\n");
        *game = false;
        return;
    } else if (Point(P).x == obstacle.x && Point(P).y == obstacle.y){
        adrSnake Q = Head(*L);
        Head(*L) = Next(Head(*L));

        DealokasiSnake(&Q);

        printf("Kepala snake terkena obstacle!\n");
        *game = false;
        return;
    }
    else{
        boolean found = false;
        while (Next(P) != Nil && !found){
            if (Point(Next(P)).x == (*meteor).x && Point(Next(P)).y == (*meteor).y){
                adrSnake Q = Next(P);
                Next(P) = Next(Q);
                if (Q==Tail(*L)){
                    Tail(*L) = P;
                    Dir(P).succ = 'x';
                }
                DealokasiSnake(&Q);

                found = true;

                printf("Anda terkena meteor!\n");
            }
            else{P = Next(P);}
        }
        if (!found){
            printf("Anda beruntung tidak terkena meteor! Silahkan lanjutkan permainan\n");
        }
    }

}

void CreatePeta (snakeList *L, point* food, point* obstacle){
    CreateEmptySnake(L);
    int X = randomNumberMinMax(0, 4);
    int Y = randomNumberMinMax(0, 4);

    adrSnake P = AlokasiSnake(X, Y, 'x');
    Head(*L) = P;
    Tail(*L) = P;

    InsertSnake(L);
    InsertSnake(L);

    *food = NewPoint(*L, *obstacle);
    *obstacle = NewPoint(*L, *obstacle);
}

void InsertSnake (snakeList *L){
    int X = (Point(Tail(*L)).x + 4) % 5 ;
    int Y = Point(Tail(*L)).y;
    char prev = 'd';

    if (SearchSnake(*L, X, Y) != Nil){
        X = Point(Tail(*L)).x;
        Y = (Point(Tail(*L)).y + 4) % 5;
        prev = 's';

        if (SearchSnake(*L, X, Y) != Nil){
            X = Point(Tail(*L)).x + 1 & 5;
            Y = Point(Tail(*L)).y;
            prev = 'a';

            if (SearchSnake(*L, X, Y) != Nil){
                X = Point(Tail(*L)).x;
                Y = Point(Tail(*L)).y + 1 % 5;
                prev = 'w';

                if (SearchSnake(*L, X, Y) != Nil){
                    return;
                }
            }
        }
    }

    SetNext (L, X, Y, prev);
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

void PrintSnake(snakeList L, point food, point meteor, point obstacle){
    printf("\n\nBerikut merupakan peta permainan\n");

    int a, b, c, d, e, f, g, h, i, j, k, s;
    a = 179; b = 180; c = 191;
    d = 192; e = 193; f = 194;
    g = 195; h = 196; i = 197;
    j = 217; k = 218; s = 178;
    int head = 1, tail = 240, mete = 19, obs = 88;

    printf("\n'%c' merupakan obstacle.\n'%c' merupakan meteor.\n\n", obs, mete);

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
                    adrSnake P = SearchSnake(L, o, m);
                    if (P == Nil){
                        if (n==1){
                            if (o == food.x && m == food.y){
                                printf("%c    o    ", a);
                            } else if (o == obstacle.x && m == obstacle.y){
                                printf("%c    %c    ", a, obs);
                            } else if (o == meteor.x && m == meteor.y){
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