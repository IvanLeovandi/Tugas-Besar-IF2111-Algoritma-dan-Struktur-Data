#include <stdio.h>

int main(){
    char* x= "M15";
    char* y[2];
    y[0] = x[1];
    y[1] = x[2];
    // int a = y[1] - '0';

    printf("%s\n", y);
    // printf("%d", a);

    return 0;
}