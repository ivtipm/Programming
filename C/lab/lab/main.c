#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

/*
Операторы: арифметические
Логические операторы и выражения 

условнуый оператор: полная и сокращённая форма
один или несколько вложенных операторов
комбинация условных операторов: вложенные условия

*/


int main(){

   int t = time(0); 
   printf("t = %d\n", t);

   srand( t );

   printf("RAND_MAX = %d\n", RAND_MAX);
   
int x;
x = rand() % 100;          //   0 ..  99
x = rand() % 101;          //   0 .. 100
x = rand() % 101 - 50;     // -50 ..  50 

float y;
y = 1.0 * rand() / RAND_MAX;        // 0.0 ..   1.0
y = 1.0 * rand() / RAND_MAX * 100;  // 0.0 .. 100.0

printf("y = %.4f\n", y);

   printf("\n");
}























/*
A  B   A и B
0  0     0 
0  1     0
1  0     0
1  1     1

*/