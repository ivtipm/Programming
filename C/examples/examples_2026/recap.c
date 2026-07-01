// 6. Устройство памяти программы.
// 7. Динамические массивы.
// 8. Файлы.
// 9. Структуры.
// 10. Списки.




#include <stdio.h>

#define N 1024

const float e = 2.718281828;

int Arr[N];

// array

/// Зануляет элементы массива
void zero_array( int arr[N] ){
    // массивы всегда передаётся в функцию по ссылке
    for (unsigned i = 0; i<N; i++){
        arr[i] = 0;
    }
}

/// Выводит массив на экран
void print_array( int arr[N] ){
    for (unsigned i = 0; i<N; i++){
        printf("%d ", arr[i]);
    }
}

int main(){

    Arr[0] = 123;

    // zero_array(Arr);

    print_array(Arr);

    puts("");

}
