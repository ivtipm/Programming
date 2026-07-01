// Динамические двумерные массивы

#include <stdio.h>
#include <stdlib.h>


// Статический массив
int Matr0[3][5];          // 3 строк, 5 столбов
// 3 массива из массивов по 5 элементов

/// Выводит двумерный массив matr на экран
/// n -- количество строк
/// m -- количество столбцов
void print_matrix(int** matr, unsigned n, unsigned m){
      for (unsigned i = 0; i<n; i++){
            for (unsigned j = 0; j<m; j++){
                printf("%d ", matr[i][j]);
            }
            puts("");
      }
}

int main(){

    unsigned n = 3;
    unsigned m = 5;

    // Динамический одномерный массив
    int * arr = (int*) malloc( n*sizeof(int) );

    // Динамический двумерный массив = массив из указателей на массивы
    // 3 массива по 5 элементов каждый
    int * * matr = (int**)malloc( n*sizeof(int*) );
    // sizeof(int*) -- определение размера указателя на массив

    // выделение памяти под строки матрицы matr
    // matr[0] = (int*)malloc( 5*sizeof(int) );
    // matr[1] = (int*)malloc( 5*sizeof(int) );
    // matr[2] = (int*)malloc( 5*sizeof(int) );

    // выделение памяти под строки матрицы matr
    for (unsigned i = 0; i<n; i++) {
        matr[i] = (int*)malloc( m*sizeof(int) );
    }


    for (unsigned i = 0; i<n; i++)
          for (unsigned j = 0; j<m; j++)
              matr[i][j] = rand()%100;


    print_matrix(matr, n, m);


    // Освобождение памяти двумерного динамического массива:
    for (unsigned i = 0; i<n; i++) {        // освобождение памяти, которую занимаю строки матрицы
        free(matr[i]); matr[i] = NULL;
    }
    // Освобождение памяти из указателей не указатели (из указателей на строки матрицы)
    free( matr ); matr = NULL;


    free(arr); arr = NULL;


}
