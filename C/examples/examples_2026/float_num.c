#include <stdio.h>
#include <assert.h>
#include <math.h>


float hypot1(float a, float b){
    return sqrt( a*a + b*b);
}

int main(){

    double x1 = 1.0/3.0;
    double x2 = 1.0/4.0;
    double x3 = 1.0/5.0;
    double x4 = 1.0/7.0;
    double x5 = 1.0/11.0;
    double x6 = 7.0/3.0;
    double x7 = 5.0/3.0;


    printf("x1 = %.16lf\n", x1);
    printf("x2 = %.16lf\n", x2);
    printf("x3 = %.16lf\n", x3);
    printf("x4 = %.16lf\n", x4);
    printf("x5 = %.16lf\n", x5);
    printf("x6 = %.16lf\n", x6);
    printf("x7 = %.16lf\n", x7);

    // сравнение вещественных чисел
    assert ( fabs(0.2500000000000003 - 1.0 / 4.0) <= 0.001  );

    // рискованный способ сравнения вещественных чисел:
    assert( hypot1(3.0, 4.0) == 5.0 );

    // правильный способ сравнения вещественных чисел
    assert( fabs( hypot1(2.85,3.89) - 4.82) <= 0.02 );

    printf( "hypot1 = %lf\n", hypot1(2.85,3.89));

    puts("");
}
