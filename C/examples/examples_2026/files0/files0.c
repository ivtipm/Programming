// Задача: записать в файл N случайных чисел
#include <stdio.h>
#include <stdlib.h>

int main(){

    // Создадим файловую переменную, откроем файл для записи
    FILE * f = fopen("numbers.txt", "w");

    unsigned n = 100;

    for (unsigned i = 0; i<n; i++) {
        int x = rand()%100;
        fprintf(f, "%d ", x);        // запись данных в файл
    }

    fclose(f);  // закрытие файла
    // иначе в файл могут быть записаны не все данные



    // Пример чтения файла
    FILE * f2 = fopen("numbers.txt", "r");

    int x;
    fscanf(f2, "%d", &x);     printf("x = %d\n", x);
    fscanf(f2, "%d", &x);     printf("x = %d\n", x);

    fclose(f2);

    puts("");
}
