//
// Created by 1 on 16.04.2023.
//

#include "DynamicArray.h"

typedef struct Vector { // структура для расширяемого массива
    int *values; // содержимое
    int size; // реальный размер
    int capacity; // ёмкость массива
} Vector;

Vector *init_vector(int n) { // функция инициализации маассива -> создание, установка ёмкости, размера, выделение памяти
    Vector *vec = (Vector *) malloc(sizeof(Vector));

    if (!vec) { // Проверка на выделение памяти
        puts("Error allocate memory!");
        return NULL;
    }

    if (n < 0) { // обработка ввода отрицательного размера
        vec->capacity = 0;
        puts("Error: The size of the set must be >= 0");
    } else vec->capacity = n;

    vec->size = 0;
    vec->values = malloc(sizeof(int) * n);

    if (!vec->values) { // Проверка на выделение памяти
        puts("Allocation error!");
        exit(1);
    }

    return vec;
}

void free_vec(Vector *vec) {
    free(vec->values);
    free(vec);
}

void read_vector(Vector *vec, int size) { // функция ввода массива - структуры
    if (vec->capacity < size) {
        vec->values = realloc(vec->values, sizeof(int) * size);
        if (!vec->values) { // Проверка на выделение памяти
            puts("Allocation error!");
            exit(1);
        }
        vec->capacity = size;
    }
    vec->size = size;
    for (int i = 0; i < size; ++i) {
        vec->values[i] = input_int();
    }
}

void print_vector(Vector *vec) { // функция вывода массива - структуры
    for (int i = 0; i < vec->size; ++i)
        printf("%d\n", vec->values[i]);
}


void ShellSort_vector(Vector *vec) {
    int step, i, j, tmp; // Переменные для шага, счётчиков и временная переменная
    for (step = vec->size / 2; step > 0; step /= 2) // Выбираем шаг сортировки
        for (i = step; i < vec->size; i++) { // Проходим по всему массиву
            tmp = vec->values[i]; // Записываем текущий элемент
            for (j = i; j >= step; j -= step) { // Начинаем мини-сортировку вставками
                if (tmp < vec->values[j - step]) // Если элемент меньше текущего(), то сдвигаем элементы дальше
                    vec->values[j] = vec->values[j - step];
                else // Иначе выходим их цикла
                    break;
            }
            vec->values[j] = tmp; // и записываем наш элемент на его новое место, уже отсортированное по шагу
        }
}