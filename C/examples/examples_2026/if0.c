#include <stdio.h>
#include <stdlib.h>

int main(){

   int n = 0;

   puts("Введите n, ( n > 0 )");
   printf("n = ");

   scanf("%d", &n);

   if ( n <= 0 ){
       puts("Вы ввели n <= 0");
       exit(1);
   }

   puts("Делаем дела...");


}
