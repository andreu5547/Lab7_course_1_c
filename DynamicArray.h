//
// Created by 1 on 16.04.2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "input_int.h"

#ifndef LAB7_DYNAMICARRAY_H
#define LAB7_DYNAMICARRAY_H


typedef struct Vector Vector;

Vector *init_vector(int n);

void free_vec(Vector *vec);

void read_vector(Vector *vec, int size);

void print_vector(Vector *vec);

void ShellSort_vector(Vector *vec);

#endif //LAB7_DYNAMICARRAY_H
