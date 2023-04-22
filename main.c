#include "DynamicArray.h"
#include "StringVectors.h"
#include "input_int.h"

int main() {
    // NUM 1
    puts("Num 1");
    puts("Input size:");
    int size = input_int();
    Vector *vec = init_vector(size);
    puts("Input values:");
    read_vector(vec, size);
    ShellSort_vector(vec);
    print_vector(vec);
    free_vec(vec);

    //NUM 2
    puts("\nNum 2");
    puts("Input string");
    CVector *str = input_cvector();
    print_cvector(str);
    free_CV(str);

    return 0;
}
