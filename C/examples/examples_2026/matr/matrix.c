/// Модуль для работы с матрицами

#include <stdio.h>
#include "matrix.h"


/// вывод на экран матрицу matr размером в n строк и m столбцов
void print_matrix(float matr[N][M], unsigned n, unsigned m ){
    for ( unsigned i = 0; i < n; i++) {    // i - индекс строки
        for ( unsigned j = 0; j < m; j++) {  // j - индекс столбца
            printf(" %5.2f ", matr[i][j]);
        }
        puts("");
    }
}
