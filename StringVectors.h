//
// Created by 1 on 25.03.2023.
//
#include <stdio.h>
#include <stdlib.h>

#ifndef STRINGVECTORS_H
#define STRINGVECTORS_H


typedef struct CVector CVector;

CVector *init_cvector(int n);

CVector *input_cvector();

void print_cvector(CVector *ve);

void free_CV(CVector *ve);

char *give_string(CVector *ve);

#endif //STRINGVECTORS_H
