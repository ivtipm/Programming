#include <math.h>
#include <stdio.h>

/*
    Вычислить сумму ряда
    где член ряда: ai = 1000 / i!,
    i = 1..n

    n! = 1 * 2 * 3 * ... * (n-1) * (n);
 */
int main(){

    unsigned int n = 0;     //
    float S = 1000.0;
    float ai = 0.0;
    unsigned int F = 1;

    printf("n = "); scanf("%u", &n);

    for (unsigned int i = 2; i<=n; i++){

        F = F * i;

        ai = 1000.0 / F;

        S = S + ai;
    }

    printf("S = %f", S);

    puts("");

}
