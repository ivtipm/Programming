/// вычисляет факториал числа n;
// @return факториал
unsigned long long fact(unsigned long long n){
    if ( n == 0 || n == 1) return 1;
    return fact(n-1) * n;
}
