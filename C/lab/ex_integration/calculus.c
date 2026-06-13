#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "calculus.h"


/// Пример функции для интегрирования
float f_x2(float x){
    return x*x;
}


/// @brief Функция интегрирования 
/// Использует метод прямоугольников
float integrate(float a, float b, size_t n){
    float h = (b-a)/n;
    float s = 0.0;

    for (float x = a; x<b; x+=h){
        s += f_x2(x+h/2)*h;}

    return s;
}


/// @brief Функция интегрирования 
/// Использует метод прямоугольников
float integrate_f(float a, float b, size_t n, TFunc f){
    float h = (b-a)/n;
    float s = 0.0;

    for (float x = a; x<b; x+=h){
        s += f(x+h/2)*h;}

    return s;
}


/// @brief Функция интегрирования 
/// Использует метод прямоугольников
float* integrate_f_array(float a, float b, size_t n, TFunc f, float *s){
    float *arr = malloc(n * sizeof(float));
    float h = (b-a)/n;

    size_t i = 0;
    for (float x = a; x<b-h/2; x+=h){
        arr[i] = f(x+h/2)*h;
        *s += arr[i];
        i++;}
    printf("i = %zu\n", i);
    return arr;
}


void print_array(const float *array, size_t size){
    for (size_t i = 0; i < size; i++){
        if ( (i !=0) &&( i%10 == 0) ) puts("");
        printf("%6.2f", array[i]);
    }
}


void array_to_file(float *array, size_t size, char filename[]){
    if (array == NULL ){
        puts("array is NULL");
        return;
    }
    puts("aray is ok");
    // printf("lld", (long long)array);
    puts("fopen");

    FILE *f = fopen(filename, "w");

    puts("for...");
    for(size_t i = 0; i<size; i++){
        fprintf(f, "%f ", array[i]);
    }

    fclose(f);
}


/// Тесты функций
void tests(){
    const float EPS = 1e-6;
    assert( fabs(integrate(0, 1, 1) - 0.25) < EPS );
    assert( fabs(integrate(0, 1, 20) - 0.333125) < EPS );
    assert( fabs(integrate(-5, +5, 7) - 81.632653) < EPS );

    puts("All tests [PASS]\n");
}