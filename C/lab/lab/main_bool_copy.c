#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

/*
Операторы: арифметические
Логические операторы и выражения 

условный оператор: полная и сокращённая форма
один или несколько вложенных операторов
комбинация условных операторов: вложенные условия

*/


int main(){


    int x = 9, y = 8, z = 100;

    printf("x = %d   ", x);
    printf("y = %d\n", y);


    // логический тип данных
    bool b1 = 1;    // истина = 1 = true
    bool b2 = 0;    // ложь = 0 = false

    // можно использовать int вместо типа bool
    int b3 = 1;
    int b4 = 1; 


    // 7 % 2 -> 1
    // 8 % 2 -> 0

    int b5 =   x > y;     // 1
    int b6 =   z <= y;    // 0

    printf("x > y  ->  %d\n", b5);         // 1
    printf("z <= y  ->  %d\n", b6);        // 0

    int b7 =   x == y;     // 0
    int b8 =   z != y;     // 1
    
    printf("x == y  ->  %d\n", b7);        // 0
    printf("z != y  ->  %d\n", b8);        // 1


    int b9 =   ! (x == y);     // 1
    int b99 =     x != y;      // 1

    int b10 =   ! (z != y);     // 0
    int b100 =     z == y;     // 0
    
    printf("! (x == y)  ->  %d\n", b9);         // 1
     printf("x != y  ->  %d\n", b99);         // 1
     
    printf("! (z != y)  ->  %d\n", b10);        // 0
    printf( "z == y  ->  %d\n", b100);        // 0

}
