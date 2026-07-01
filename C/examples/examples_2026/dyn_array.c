// Динамические массивы

#include <stdio.h>
#include <stdlib.h>

#define N 1024

// Статический (в прогр.) -- характеристика того, что известно (или происходит) на этапе компиляции.
// Динамический (в прогр.) -- характеристика того, что известно (или происходит) на этапе выполнения программы.

// Статический массив (размер такого массива задётся на этапе компиляции)
// int Arr[1'000'000'000ull];


/// Выводит массив на экран
/// int *arr -- указатель на динамический массив
/// size -- количество элементов массива
void print_array( int *arr, unsigned long long size ){
    for (unsigned i = 0; i<size; i++){
        printf("%d ", arr[i]);
    }
}


void foo(){
     int * arr = (int *)malloc( 10 * sizeof(int) );
     // ...
     // утечка памяти, т.к. указатель arr будет потерян после завершения функции, а память на которую он указывает не будет освобождена
}

/// выделение памяти под массив из n элементов
/// Возвращает указатель на массив
int* allocate_array(unsigned long long n){
     int * arr = (int *)malloc( n * sizeof(int) );
     return arr;
}


/// Ошибочный пример: фактический параметр у функции НЕ изменится! (указатель передаётся по значению)
/// выделение памяти под массив из n элементов
void create_array_bad(int *arr, unsigned long long n){
     arr = (int *)malloc( n * sizeof(int) );
}

/// Правильный пример: фактический параметр у функции изменится, т.к. передаётся адрес указателя (указатель передаётся по ссылке)
/// выделение памяти под массив из n элементов
void create_array_good(int **arr, unsigned long long n){
     *arr = (int *)malloc( n * sizeof(int) );
}


int main(){

    foo();

    // int arr2[1'000'000'000ull];
    unsigned long long n = 0;

    printf("Введите размер массива: ");
    scanf("%llu", &n);

    int *arr2 = allocate_array(10);
    // ...
    printf("arr2 = %p\n", arr2);
    free( arr2 ); arr2 = NULL;


    int* arr3 = NULL;
    create_array_bad(arr3, 10);
    printf("arr3 = %p\n", arr3);    // arr3 не изменился

    int* arr4 = NULL;
    create_array_good(&arr4, 10);
    printf("arr3 = %p\n", arr4);    // arr3 не изменился
    arr4 = NULL;
    // arr4 = 1234;        // нельзя записать произвольное число в адрес


    // arr -- Динамический массив из элементов типа int
    int * arr = (int *)malloc( n * sizeof(int) );
    // malloc -- выделяет память, возвращает указатель на эту память
    // n * sizeof(int) -- количество байт
    // sizeof(int) -- определение количества байт, которое занимает одно значение типа int
    // (int *) -- операция преобразования типа указателя из типа void * в тип int *

    // NULL -- обозначение пустого указателя (указателя который никуда не указывает)
    if ( arr == NULL ){
        puts("Недостаточно памяти");
        return 1;
    }

    arr[0] = 10;
    arr[n-1] = 99;

    // print_array(arr, n);

    free(arr);      // освобождение памяти
    arr = NULL;     // признак того, что мы освободили память

    free(arr);

    puts("");

}
