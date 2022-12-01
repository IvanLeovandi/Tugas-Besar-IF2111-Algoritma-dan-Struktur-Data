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

    #ifdef _WIN32
        PrintSnake(snake, food, meteor, obstacle);
    #else
        PrintSnakeLinux(snake, food, meteor, obstacle);
    #endif

    while (game){
        printf("\nTURN %d\n", turn);
        printf("Silahkan masukkan command anda: ");
        command = Input();
        ClearScreen();
        if (str_len(command) == 1){
            Move(*command, &snake, &food, &game, &meteor, obstacle, &turn);
            #ifdef _WIN32
                PrintSnake(snake, food, meteor, obstacle);
            #else
                PrintSnakeLinux(snake, food, meteor, obstacle);
            #endif
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
        printf("1: %d\n", ((*meteor).x == food.x && (*meteor).y == food.y));
        printf("2: %d\n\n", ((*meteor).x == obstacle.x && (*meteor).y == obstacle.y));
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
    printf("\nBerikut merupakan peta permainan\n");

    int a, b, c, d, e, f, g, h, i, j, k, s;
    a = 179; b = 180; c = 191;
    d = 192; e = 193; f = 194;
    g = 195; h = 196; i = 197;
    j = 217; k = 218; s = 178;
    int head = 1, tail = 240, mete = 19, obs = 88;

    printf("'%c' merupakan obstacle. '%c' merupakan meteor. 'o' merupakan makanan.\n", obs, mete);

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
                                printf("%c    ", a); HIJAU; printf("o    "); RESET;
                            } else if (o == obstacle.x && m == obstacle.y){
                                printf("%c    ", a); MERAH; printf("%c    ", obs); RESET;
                            } else if (o == meteor.x && m == meteor.y){
                                printf("%c    ", a); MERAH; printf("%c    ", mete); RESET;
                            } else {printf("%c         ", a);}
                        }
                        else{printf("%c         ", a);}
                    } else{
                        if(n==0){
                            if(Dir(P).prec == 'w' || Dir(P).succ == 'w'){
                                printf("%c   ", a); HIJAU; printf("%c%c%c   ", s, s, s); RESET;
                            } else {printf("%c         ", a);}
                        }
                        
                        else if(n==1){                            
                            if(Dir(P).prec == 'a' || Dir(P).succ == 'a'){
                                printf("%c", a); HIJAU; printf("%c%c%c%c", s, s, s, s); RESET;
                            } else {
                                if(Dir(P).prec == 'x' || Dir(P).succ =='x'){
                                    printf("%c    ", a);
                                } else {printf("%c   ", a); HIJAU; printf("%c", s); RESET;}
                            }

                            /* head */
                            if(Dir(P).prec == 'x'){
                                KUNING; printf("%c", head); RESET;
                            } else if(Dir(P).succ =='x'){
                                HIJAU; printf("%c", tail); RESET;
                            } else { HIJAU; printf("%c",s); RESET;}

                            if(Dir(P).prec == 'd' || Dir(P).succ == 'd'){
                                HIJAU; printf("%c%c%c%c", s, s, s, s); RESET;
                            } else{                                
                                if(Dir(P).prec == 'x' || Dir(P).succ =='x'){
                                    printf("    ");
                                } else {HIJAU; printf("%c   ", s); RESET;}}
                        }
                        
                        else{
                            if(Dir(P).prec == 's' || Dir(P).succ == 's'){
                                printf("%c   ", a); HIJAU; printf("%c%c%c   ", s, s, s); RESET;
                            } else {printf("%c         ", a);}
                        }
                    }
                }
                printf("%c\n", a);
                }
                
            }
        
    }
}

void PrintSnakeLinux(snakeList L, point food, point meteor, point obstacle){
    printf("\nBerikut merupakan peta permainan\n");
    /*******/
    int a, b, c, d, e, f, g, h, i, j, k, s;
    a = 179; b = 180; c = 191;
    d = 192; e = 193; f = 194;
    g = 195; h = 196; i = 197;
    j = 217; k = 218; s = 178;
    int head = 1, tail = 240, mete = 19, obs = 88; //mete = \u203c   obs = \u2715
    /******/
    printf("\u2715 merupakan obstacle. \u203c merupakan meteor. 'o' merupakan makanan.\n");

    for (int m =0; m<6; m++){
        for (int o=0; o<5; o++){
            if (m==0){
                if (o==0){printf("%s", "\u250c");} //k
                else {printf("%s", "\u252f");} //f
            } else if(m==5){
                if (o==0){printf("%s", "\u2514");} //d
                else {printf("%s", "\u2534");} //e
            } else {
                if (o==0){printf("%s", "\u251c");} //g
                else {printf("%s", "\u253c");} //i
            }

            for (int i = 0; i < 9; i++) {
                printf("%s", "\u2500"); //h
            }

            if (o==4){
                if (m==0){
                    printf("%s", "\u2510"); //c
                } else if (m==5) {
                    printf("%s", "\u2518"); //j
                } else {
                    printf("%s", "\u2524"); //b
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
                                printf("%s    ", "\u2502"); HIJAU; printf("o    "); RESET; //a
                            } else if (o == obstacle.x && m == obstacle.y){
                                printf("%s    ", "\u2502"); MERAH; printf("%s    ", "\u2715"); RESET; //a
                            } else if (o == meteor.x && m == meteor.y){
                                printf("%s    ", "\u2502"); MERAH; printf("%s    ", "\u203c"); RESET; //a
                            } else {printf("%s         ", "\u2502");} //a
                        }
                        else{printf("%s         ", "\u2502");} //a
                    } else{
                        if(n==0){
                            if(Dir(P).prec == 'w' || Dir(P).succ == 'w'){
                                printf("%s   ", "\u2502"); HIJAU; printf("%s%s%s   ", "\u2593", "\u2593", "\u2593"); RESET; //s
                            } else {printf("%s         ", "\u2502");} //a
                        }
                        
                        else if(n==1){                            
                            if(Dir(P).prec == 'a' || Dir(P).succ == 'a'){
                                printf("%s", "\u2502"); HIJAU; printf("%s%s%s%s", "\u2593", "\u2593", "\u2593", "\u2593"); RESET;
                            } else {
                                if(Dir(P).prec == 'x' || Dir(P).succ =='x'){
                                    printf("%s    ", "\u2502");
                                } else {printf("%s   ", "\u2502"); HIJAU; printf("%s", "\u2593"); RESET;}
                            }

                            /* head */
                            if(Dir(P).prec == 'x'){
                                KUNING; printf("%c", head); RESET;
                            } else if(Dir(P).succ =='x'){
                                HIJAU; printf("%s", "\u2261"); RESET; //tail
                            } else { HIJAU; printf("%s","\u2593"); RESET;}

                            if(Dir(P).prec == 'd' || Dir(P).succ == 'd'){
                                HIJAU; printf("%s%s%s%s", "\u2593", "\u2593", "\u2593", "\u2593"); RESET;
                            } else{                                
                                if(Dir(P).prec == 'x' || Dir(P).succ =='x'){
                                    printf("    ");
                                } else {HIJAU; printf("%s   ", "\u2593"); RESET;}}
                        }
                        
                        else{
                            if(Dir(P).prec == 's' || Dir(P).succ == 's'){
                                printf("%s   ", "\u2502"); HIJAU; printf("%s%s%s   ", "\u2593", "\u2593", "\u2593"); RESET;
                            } else {printf("%s         ", "\u2502");}
                        }
                    }
                }
                printf("%s\n", "\u2502");
                }
                
            }
        
    }
}

void PrintGaris() {
    #ifdef _WIN32
        for (int i = 0; i < 9; i++) {
            printf("%c", 196);
        }
    #else
        for (int i = 0; i < 9; i++) {
            printf("%s", "\u2500");
        }
    #endif
}