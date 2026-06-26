#include <stdio.h>
#include <math.h>

// Найти сумму ряда с точностью eps
// Член ряда: ai = (1 + i) / (3*i^2 + i^1.5 + 2), i = 1, 2, 3, ...

int main(){


    float eps;                  //
    float a;                    //
    float S = 0.0;              //
    unsigned int i = 1;         //

    printf("Eps = ");
    scanf("%f", &eps);

    a = (1.0 + i) / ( 3 * powf(i, 2.0) + powf(i, 1.5) + 2.0 );
    printf("i = %2d; ai = %.4f; S = %.4f\n", i, a, S);

    while ( a > eps ){
        S = S + a;
        i = i + 1;

        a = (1.0 + i) / ( 3 * powf(i, 2.0) + powf(i, 1.5) + 2.0 );
        printf("i = %2u; ai = %.4f; S = %.4f\n", i, a, S);
    }

    printf("ai = %.4f\n",a);
    printf("S = %.4f\n", S);

    puts("");

    return 0;

}
