#include <math.h>
#include <stdio.h>

/*
 * Найти сумму ряда, где член ряда вычисляется по формуле
 * ai = 1 / 2^i
 * где i = 1, ..., n
 * n > 0
 *
 */
int main(){

    unsigned int n = 0;     //
    float a = 0.0, S = 0.0; //
    unsigned int i = 1;

    // do{
    //     printf("n = ");
    //     scanf("%ud", &n);
    // } while ( n == 0 );

    do{
        printf("n = ");
        scanf("%ud", &n);

        if ( n != 0 ) { break; }
        else { puts("Введите n > 0"); }

    } while ( 1 );


    while ( i != n+1 )        // заголовок цикла; i <= n -- условие продолжения цикла
        // тело цикла
        {
            a = 1.0 / powf(2, i);
            S = S + a;
            i = i + 1;
        }

    printf("S = %f\n", S);
}
