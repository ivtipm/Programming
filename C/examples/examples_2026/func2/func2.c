#include <stdio.h>
#include <assert.h>

#include "my_math.h"

int main(){

    // автоматическое тестирование функций
    //
    assert ( fact(0) ==   1 );
    assert ( fact(1) ==   1 );
    assert ( fact(4) ==  24 );
    assert ( fact(5) == 120 );

    unsigned long long f = fact(0);     // 1
    printf("0! = %llu\n",  f);
    printf("1! = %llu\n",  fact(1) );     // 1
    printf("5! = %llu\n",  fact(5) );     // 120
    puts("");
}
