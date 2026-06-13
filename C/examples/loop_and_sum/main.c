/// Пример программы на C с циклом
///
/// Программа вводит числа с клавиатуры и суммирует их,
/// пока не будет введён 0.
///
/// Компиляция:  clang -std=c23 -Wall -Wextra -g main.c -o main
/// Запуск:      ./main
/// Отладка:     lldb main  (или через Zed: Ctrl+Shift+P → Debug)

#include <stdio.h>

int main(void) {
    int sum = 0;
    int value;

    printf("Вводите числа для суммирования (0 — выход):\n");

    while (1) {
        printf("> ");
        if (scanf("%d", &value) != 1) {
            printf("Ошибка ввода. Завершение.\n");
            break;
        }

        if (value == 0) {
            break; // условие выхода из цикла
        }

        sum += value;     // накопление суммы
        printf("Текущая сумма: %d\n", sum);
    }

    printf("Итоговая сумма: %d\n", sum);
    return 0;
}