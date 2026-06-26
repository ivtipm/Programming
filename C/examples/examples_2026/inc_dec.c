#include <stdio.h>


int main(){

    int a = 0;
    int b = a++;        // b = 0, a = 1
    int c = ++a;        // c = 2, a = 2

    b = a--;            // b = 2, a = 1
    c = --a;            // c = 0, a = 0


}
