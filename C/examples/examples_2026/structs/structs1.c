#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Пример создания синонима для типа float, real -- название синонима
typedef float real;

// typedef int matr_type;
typedef float matr_type;



matr_type M[10][10];

void print_matrix(matr_type m[10][10]){
    //...
}

// Объявим тип данных struct Point для описания точки на плоскости
// struct Point {
//     // поля структуры Point:
//     float x;
//     float y;
// };

// Объявим тип данных struct Point для описания точки на плоскости
// Определяем синоним для типа struct Point: Point
typedef  struct Point {
    // поля структуры Point:
    float x;
    float y;
}  Point;

/// Вычисляет расстояние между точками (x1, y1) (x2, y2)
float distance_f(real x1, float y1,  float x2, float y2){
    return sqrt( powf(x2-x1, 2.0) + powf(y2-y1, 2.0) );
}


float distance_p(  Point p1,  struct Point p2 ){
    // разницы между Point и struct Point нет
    return sqrt( powf(p2.x-p1.x, 2.0) + powf(p2.y-p1.y, 2.0) );
}

// Lazarus - record, class
// C - struct


/// Выводит точку на экран
void print_point1( struct Point p){
    printf("(%.2f, %.2f)", p.x, p.y);
}

/// Выводит точку на экран
void print_point2( const struct Point * p){
    // (*p).x = 100;  // Ошибка: менять p нельзя, т.к. это указатель на константу
    printf("(%.2f, %.2f)", (*p).x, p->y);
    // (*p).x и p->x равнозначны
}


/// Создаёт случайную точку
struct Point random_point( ){
    struct Point p;
    p.x = 1.0 * rand() / RAND_MAX * 200 - 100;      // [-100, 100];
    p.y = 1.0 * rand() / RAND_MAX * 200 - 100;      // [-100, 100];
    return p;
}

int main(){
    float x;
    float y;

    float d1 = distance_f(1,2, 0,0);

    printf("d1 = %.2f\n", d1);

    puts("");



    Point  p1 = {1.0, 2.0};
    struct Point  p2;
    // .x -- обращение к полю переменной p1
    // p1.x = 1.0;
    // p1.y = 2.0;

    p2.x = 0.0;
    p2.y = 0.0;

    // пример присваивания структур
    struct Point p3 = p1;
    // p3.x = p1.x; p3.y = p3.y;

    float d2 = distance_p( p3, p2);

    printf("d2 = %.2f\n", d2);

    // printf("p3 = %f\n", p3);
    printf("p1 = ");
    print_point1(p1); puts("");

    printf("p2 = ");
    print_point1(p2); puts("");




    struct Point p4 = random_point();

    printf("p4 = ");
    print_point2(&p4); puts("");

    puts("");


}
