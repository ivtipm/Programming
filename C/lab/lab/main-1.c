#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>



int main(){

    // инициализируем формулу для генерации случайных
    srand(time(0) ) ;

    int a = 0;

    a = rand();

    printf("RAND_MAX = %llu\n", RAND_MAX);
    printf("A = %d\n", a);


    float b = 1.0 * rand() / RAND_MAX;      // 0,1
    b = b*1000 - 500;
    printf("b = %f\n", b);

}

    // float x, y;

    // printf("X = ");
    // scanf("%f", &x);


    // if ( x > 0 ){
    //         printf("X - положительный");
    //         printf("la-la-la");        }
    // else

    //     {

    //         printf("X - отрицательный или 0");
    //         printf("pu-pu-pu");
        
    //     }    
        


}

/*


        // Составные логические выражения
        // Задача: определить в какой че8стверти координатной плоскости нахожится точка с координатами

    float x, y;

    printf("X = ");
    scanf("%f", &x);

    printf("Y = ");
    scanf("%f", &y);

    if ( x >= 0 )
        if ( y >= 0 )
           printf("I четверть");
        else
           printf("IV четверть");
    else     
        if ( y >= 0 )
           printf("II четверть");
        else
           printf("III четверть");


    if ( (x > 0)  &&  (y > 0) )
        printf("I четверть");
    else 
        if ( (x < 0)  &&  (y > 0) )
            printf("II четверть");
        else 
            if ( (x < 0)  &&  (y < 0) )
                printf("III четверть");
            else   
                printf("IV четверть");
            
            */


/*

Таблица истинности

A B   A и B
0 0     0
0 1     0
1 0     0
1 1     1

*/



/*


   float x, y;

    printf("X = ");
    scanf("%f", &x);

    if ( x > 0 )            // x > 0
        y = x*x;
    else
        if ( x >= -10 )     // -10 <= x <= 0
            y = x;
        else                // x < -10
            y = sin(x);    

    printf("y = %.2f\n", y);

*/


/*

    //  Задача: определить является ли число X чётным

    int x;

    printf("X = ");
    scanf("%d", &x);

    // int remainder = x % 2;      // остаток

    if ( (x % 2) == 0 )
        printf("Число X чётное");
    else
       printf("Число X нечётное");

*/

/*
int main(){


    float x = 3, y = 4, z = 5;

    // bool b1 = x < y;            // инстина =true = 1
    // bool b2 = y <= z;           // инстина =true = 1
    // bool b3 = z > x;             // инстина =true = 1


    // printf("b1 %d\n", b1);
    // printf("b2 %d\n", b2);
    // printf("b3 %d\n", b3);



    int b1 = x < y;            // инстина =true = 1
    int b2 = y <= z;           // инстина =true = 1
    int b3 = z > x;             // инстина =true = 1

    int b4 = x != y;            // инстина =true = 1
    int b5 = y == z;            // ложь  = false = 0



    printf("b1 %d\n", b1);
    printf("b2 %d\n", b2);
    printf("b3 %d\n", b3);

    printf("x != y   %d\n", b4);
    printf("y == z   %d\n", b5);

    int b6 = !0;           // истина, 1
    int b7 = !1;           // истина, 0

    printf("! 0   %d\n", b6);
    printf("! 1   %d\n", b7);


    int b8 =    ! (x != y);            // ложь = false = 0
    int b88 =      x == y;               // ложь = false = 0
    
    int b9 =    ! (y == z);            // инстина = true = 1
    int b99 =      y != z;            // инстина = true = 1


    printf("! (x != y)   %d\n", b8);
    printf("x == y   %d\n", b88);
    printf("! (y == z)   %d\n", b9);
    printf("y != z   %d\n", b99);

}

*/