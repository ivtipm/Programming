#include <stdio.h>
#include <math.h>

int main(){

    // выражение (expression) -- запись в программе у которой есть результат выполнения (вычисления)


    int x;
    x = 2+2;  // 2+2 - выражение
    x = 2;    // 2 - выражение

    float y = 2.2;    // 2.2 - выражение
    y = sin(2.2)*powf(x, 3);    // sin(2.2)*powf(x, 3) - выражение


    // логические выражения
    bool b1 = true;
    bool b2 = 1;

    bool b3 = 2 == 3;           // 0
    bool b4 = 2+2 == 5;         // false

    bool b5 = 0;
    bool b6 = 1;
    bool b7 = 87346;
    bool b8 = -87346;
    bool b9 = 0.6;
    bool b10 = 1.6;

    printf("b5 = %d\n", b5);
    printf("b6 = %d\n", b6);
    printf("b7 = %d\n", b7);
    printf("b8 = %d\n", b8);
    printf("b9 = %d\n", b9);
    printf("b10 = %d\n", b10);

    puts("");

}
