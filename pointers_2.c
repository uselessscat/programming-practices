/** Ejemplo de punteros */
#include<stdio.h>

int main() {
    int integer = 1;
    
    // estos son equivalentes
    int array0[10];
    // pero en este caso, array1 es un tipo puntero
    int (*array1)[10];
    
    int *array2 = &integer;
    
    // array de 10 punteros
    // [] tiene mayor precendencia que *
    int *array3[10];
    array3[0] = array2;
    
    int *(*array4)[10];
    
    printf("%lu %lu\n", sizeof(array0), sizeof(*array0));
    printf("%lu %lu %lu\n", sizeof(array1), sizeof(*array1), sizeof(**array1));
    printf("%lu %lu\n", sizeof(array2), sizeof(*array2));
    printf("%lu %lu %lu\n", sizeof(array3), sizeof(*array3), sizeof(**array3));
    printf("%lu %lu %lu %lu\n", sizeof(array4), sizeof(*array4), sizeof(**array4), sizeof(***array4));
    
    return 0;
}
