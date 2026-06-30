// 6. Устройство памяти программы.
// 7. Динамические массивы.
// 8. Файлы.
// 9. Структуры.
// 10. Списки.


#include <stdio.h>


/// вычисляет факториал числа n;
// @return факториал
unsigned long long fact(unsigned long long n){
    if ( n == 0 ) return 1;
    if ( n == 1 ) return 1;
    return fact(n-1) * n;

}


int main(){


    // автоматическое тестирование функций

    unsigned long long f = fact(0);     // 1
    printf("0! = %llu\n",  f);
    printf("1! = %llu\n",  fact(1) );     // 1
    printf("5! = %llu\n",  fact(5) );     // 120
    puts("");
}
