/**
 * @brief Численное интегрирование функции f методов центральных прямоугольников.
 * 
 *
 * Компиляция: clang -o main main.c --std=c23 -O2
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calculus.h"

/// Функция для примера
float sin_f(float x){ return sin(x);}



int main(int argc, char* argv[]){
    /// Справка для пользователя
    const char HELP[] = "program a b n";

    /// Запуск текстов
    tests();

    
    float a = 0, b = 1;     // границы интегрирования
    unsigned n = 1;         // количество столбцов

    // Ручной ввод данных
    if (argc == 1){
        puts("Численное интегрирование функции x^2");
        puts("Введите границы интегрирования [a, b]");
        printf("a = ");
        scanf("%f", &a);
        printf("b = ");
        scanf("%f", &b);
        printf("Введите количество интервалов интегрирования n = ");
        scanf("%d", &n);
    }   // Получение данных из аргументов
    else if (argc == 4){
        a = atof(argv[1]);
        b = atof(argv[2]);
        n = atol(argv[3]);
    } else  // Вывод справки, если задано неправильное число аргументов
        {
            puts(HELP);
            exit(0);
        }

    // float s = integrate_f(a, b, n, sin_f);
    float s = 0.0;
    float *arr = integrate_f_array(a, b, n, sin_f, &s);
    
    print_array(arr, n);
    puts("");

    array_to_file(arr, n, "data.txt");

    printf("Интеграл f(x) от %.2f до %.2f, для %u интервалов: %.4f\n", a, b, n, s);

    free(arr);

    
    

}














