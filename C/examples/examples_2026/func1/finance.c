#include <math.h>

#include "finance.h"

/// Функция вычисляет стоимость товара после t лет инфляции
/// s0 -- исходная стоимость товара на начальный момент времени
/// t --  количество лет
/// inflation -- годовая инфляция в процентах
float price_after_inflation(float s0, float inflation, unsigned t){
    float s;
    s = s0 * powf( 1.0 + inflation / 100.0, t );
    return s;
}
