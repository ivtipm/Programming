#include <stdio.h>
#include <string.h>

int main(){

    char c1 = 97;
    char c2 = 55;
    char c3 = '!';
    char c4 = '8'+1;
    char c5 = '\n';         // символ перехода на новую строку
    char c6 = '\t';         // табуляция


    printf("c1 = %c (%d)\n", c1, c1);
    printf("c2 = %c (%d)\n", c2, c2);
    printf("c4 = %c (%d)\n", c4, c4);
    printf("c3 = %c (%d)\n", c3, c2);
    printf("c5 = %c (%d)\n", c5, c5);
    printf("c6 = %c (%d)\n", c6, c6);

    bool b = 'a' < 'b';     // true
    bool b1 = '0' <= c4 && c4 <= '9';
    printf("b = %d\n", b);
    printf("b1 = %d\n", b1);
    puts("");

    char s1[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char s2[] = {'H', 'e', 'l', 'l', 'o', 0};

    // s1 = s2;

    puts("");

    char s3[] = "Привет! ₽";

    puts(s3);
    printf("strlen(s3) = %lu", strlen(s3) );


}
