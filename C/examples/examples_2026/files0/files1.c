// Задача: записать в файл N случайных чисел
#include <stdio.h>
#include <stdlib.h>

int main(){

    // Пример чтения файла
    FILE * f2 = fopen("numbers.txt", "r");

    int x;

    // Чтение данных из файла
    // while( 1 ){
    //     int c = fscanf(f2, "%d", &x);       // fscanf возвращает количество прочитанных значений;
    //     // если facanf вернула -1, значит функции не удалось прочитать данные
    //     if ( c == -1 ) break;

    //     printf("%d ", x);
    // }

    // Чтение данных из файла
    while ( fscanf(f2, "%d", &x) != -1 ){
        printf("%d ", x);
    }

    // printf("Прочитано значений: %d\n", c);
    fclose(f2);

    puts("");
}
