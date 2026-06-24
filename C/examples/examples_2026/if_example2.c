#include <stdio.h>
#include <stdlib.h>

int main(){

   float x, y;

   printf("Введите x: ");
   scanf("%f", &x);

    if      ( x < 0 )
        y = x*x;
    else if ( x <= 10 )
        y = 0.0;
    else
        y = -1.0/7.0 * x;


   printf("y = %.2f", y);

   puts("");

}
