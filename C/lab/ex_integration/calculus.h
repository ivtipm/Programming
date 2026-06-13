/**
 * @brief Модуль с функциями численного интегрирования и другими служебными функциями
 * 
 */
#include <stddef.h>


/// Указатель на функцию
typedef float(* TFunc)(float);


/// Пример функции для интегрирования
float f_x2(float x);


/// @brief Функция интегрирования 
/// Использует метод прямоугольников
float integrate(float a, float b, size_t n);


/// @brief Функция интегрирования 
/// Использует метод прямоугольников
float integrate_f(float a, float b, size_t n, TFunc f);


/// @brief Функция интегрирования 
/// Использует метод прямоугольников
float* integrate_f_array(float a, float b, size_t n, TFunc f, float *s);

/**
 * @brief 
 * 
 * @param array 
 * @param size 
 */
void print_array(const float *array, size_t size);


/**
 * @brief 
 * 
 * @param array 
 * @param size 
 * @param filename 
 */
void array_to_file(float *array, size_t size, char filename[]);

/// Тесты функций
void tests();