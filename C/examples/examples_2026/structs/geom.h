#pragma once

// Объявим тип данных struct Point для описания точки на плоскости
// Определяем синоним для типа struct Point: Point
typedef  struct Point {
    // поля структуры Point:
    float x;
    float y;
}  Point;


/// s
float distance_p(  Point p1,  struct Point p2 );
