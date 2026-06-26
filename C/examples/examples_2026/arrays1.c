#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// найти минимальный элемент в массиве
// определить есть ли в массиве число 42, если есть, то запомнить его индекс первого наличия числа 24 в массиве
// найти среднее арифметическое элементов массива
// Записать в новый массив все элементы из старого, для которых справедливо ai > 0

int main(){

    srand( 20260624 );

    const unsigned N = 200;


    // автоматический массив (VLA)
    int a[N];


    for (unsigned int i = 0; i < N; i++){
        a[i] = rand() % 201 - 100;              // случайные числа от -100 до 100
    }


    // Вывод массива
    for (unsigned int i = 0; i < N; i++){
        printf("%4d ", a[i] );
        if ( i % 10 == 9 ) puts("");
    }


    // найти минимальный элемент в массиве:
    int min = a[0];

    for (unsigned int i = 1; i < N; i++){
        if ( min > a[i] )
            min = a[i];
    }

    printf("min = %d\n", min);


    // поиск элемента ( 0 ) в массиве
    int x = 42;
    unsigned int x_index = N;

    for (unsigned int i = 0; i < N; i++){
        if ( a[i] == x ){
            x_index = i;
            break;
        }
    }

    puts("\n");
    if ( x_index == N ){
        printf("Числа %d в массиве нет", x);
    }
    else {
        printf("Число %d в массиве первый раз встречается по индексу %u", x, x_index);
    }

    puts("\n");


    // найти среднее арифметическое элементов массива
    float average = 0.0;

    for (unsigned int i = 0; i < N; i++){
        average = average + a[i];
     }

    average = average / N;

    printf("Среднее арифметическое элементов массива: %.2f", average);

    puts("");


    // Записать в новый массив все элементы из старого, для которых справедливо ai > 0:
    int a_positive[N];
    unsigned n_positive = 0;    // количество положительных элементов

    // для примера: заполним каждый байт массива a_positive нулём
    memset(a_positive, 0, sizeof(int)*N);

    for (unsigned int i = 0; i < N; i++){
        if ( a[i] > 0){
            a_positive[ n_positive ] = a[i];
            n_positive++;
        }
    }


    puts("\nПоложительные элементы:");
    // Вывод массива
    for (unsigned int i = 0; i < n_positive; i++){
        printf("%4d ", a_positive[i] );
        if ( i % 10 == 9 ) puts("");
    }

    puts("");



}
