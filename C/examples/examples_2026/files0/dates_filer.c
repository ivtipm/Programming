// Записать в другой файл только даты, которые относятся к лету

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE * f_in = fopen("dates.txt", "r");
    FILE *f_out = fopen("dates_summer.txt", "w");

    int y, m, d;
    while( fscanf(f_in, "%d.%d.%d", &y, &m, &d) == 3){
        if ( m == 6 || m == 7 || m == 8){       // если месяц летний
            fprintf(f_out, "%d.%d.%d\n", y, m, d);
        }
    }


    fclose(f_in);
    fclose(f_out);

    // while ( fscanf(f2, "%d", &x) != -1 ){
    //     printf("%d ", x);
    // }


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
