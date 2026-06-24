#include <stdio.h>
#include <math.h>

int main(){

    // int x = round(3.14);    // округление до ближайшего целого
    // int y = (int)3.7;       // явное преобразование 3.7 в значение типа int, дробная часть будет отброшена
    // int z = (int)(3.14 + 1.88);
    // int t = (int)3.14 + (int)1.88;

    // printf("x = %d\n", x);
    // printf("y = %d\n", y);
    // printf("z = %d\n", z);
    // printf("t = %d\n", t);


    // puts("");
    short x = 32767;
    x = x + 1;      // переполнение типа
    printf("x = %hd\n", x);

    x = x - 1;
    printf("x = %hd\n", x);

    unsigned short y = 65535;
    printf("y = %hu\n", y);
    y = y+1;


    printf("y = %hu\n", y);

    puts("");

    // константа
    const int z = 5678;


    // литерал - значение записанное в коде
    long population = 8'300'000;

    double G = 667e-11;
    printf("G = %.12lf\n", G);


    // int x2 = 123.456 % 10;
    float x2 = fmod(2.7, 2.1);

    printf("x2 = %f", x2);

    puts("");
}
