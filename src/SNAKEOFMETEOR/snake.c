#include "snake.h"

void Snake(){

    printf("Selamat datang di snake on meteor!\n\n");
    printf("Mengenerate peta, snake dan makanan . . .\n\n");

    snakeList snake;
    point food, meteor;
    boolean game = true; 
    int turn = 1;
    CreatePeta(&snake, &food);
    meteor.x = -1;
    meteor.y = -1;

    char *command;
    
    printf("Berhasil digenerate!\n\n");
    PrintGaris(); PrintGaris(); PrintGaris(); PrintGaris(); PrintGaris(); PrintGaris(); 
    PrintSnake(snake, food, meteor);

    while (game){
        printf("\nTURN %d\n", turn);
        printf("Silahkan masukkan command anda: ");
        command = Input();
        if (str_len(command) == 1){
            Move(*command, &snake, &food, &game, &meteor, &turn);
            PrintSnake(snake, food, meteor);
        }
        else{
            printf("\nCommand tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n");
        }
    }

    int score = SnakeScore(snake);
    printf("Game berakhir. Skor: %d\n\n", score);

}



void Move (char command, snakeList *L, point* food, boolean* game, point* meteor, int* turn){
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
                Meteor(L, game, meteor, *food);
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

    Food(L, food);

    if(*turn != 1){
        Meteor(L, game, meteor, *food);
    }

    (*turn) ++;

    P = Head(*L);

}



void Food (snakeList *L, point *food){
    /* Snake memanjang */
    adrSnake(P) = Head(*L);

    if (Point(P).x == (*food).x && Point(P).y == (*food).y){
        InsertSnake(L);
        *food = NewPoint(*L);
    }
}



void Meteor (snakeList *L, boolean *game, point* meteor, point food){
    /* Randomize bom dan hit jika mengenai snake */
    (*meteor).x = randomNumberMinMax(0,4);
    (*meteor).y = randomNumberMinMax(0,4);

    while ((*meteor).x == food.x && (*meteor).y == food.y){
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