// Пример предусловий функции
// Пример кодов ошибок функции

#include <stdio.h>
#include <math.h>

/// Функция возвращает стоимость товара после t лет инфляции
/// s0 -- исходная стоимость товара на начальный момент времени
/// t --  количество лет
/// inflation -- годовая инфляция в процентах
/// error -- обозначает код ошибки,
//          error = 0 -- нет ошибки,
//          error = 1, ошибка в значении s0,
//          error = 2, ошибка в значении inflation
//          error = 3, ошибка в значении s0 и inflation
float price_after_inflation(float s0, float inflation, unsigned t, int *error){
    *error = 0;

    // предусловия:
    // проверка корректности аргументов функции
    if ( s0 < 0 )        { *error = 1; }
    if ( inflation < 0 ) { *error += 2; }

    if ( *error != 0 ) return 0.0;

    // s0, inflation, price -- принимаются по значению
    // s принимается по ссылке
    return s0 * powf( 1.0 + inflation / 100.0, t );
}



int main(){

    int Error;

    float S0, inflation;

    printf("S0 = ");
    scanf("%f", &S0);        // S0 передаётся по ссылке


    printf("inflation = ");
    scanf("%f", &inflation);        // S0 передаётся по ссылке

    float price;
    //  &price -- взятие адреса переменной price ( получение указателя на переменную price )
    // указатель = адрес
    price = price_after_inflation(S0, inflation, 5, &Error);

    if ( Error == 0 )
        printf("price = %.2f", price);
    else {
        puts("В данных s0 и / или inflation есть ошибка");

    }
    puts("");

}
