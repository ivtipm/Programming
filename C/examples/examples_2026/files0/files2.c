// Заполнить файл случайными датами


#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE * f = fopen("dates.txt", "w");

    size_t n = 1'000'000'000ull;       // size_t == unsigned long long

    for (size_t i = 0; i<n; i++) {
        int year = 1900 + rand()%126;
        int month = 1 + rand()%12;
        int day = rand()%28;

        fprintf(f, "%d.%d.%d\n", year, month, day);
    }
    fclose(f);


    // // Пример чтения файла
    // FILE * f2 = fopen("dates.txt", "r");


    // // Чтение данных из файла
    // while ( fscanf(f2, "%d", &x) != -1 ){
    //     printf("%d ", x);
    // }

    // // printf("Прочитано значений: %d\n", c);
    // fclose(f2);

    // puts("");
}
