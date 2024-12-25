#include <stdio.h>

// Declaración de la función en la DLL
extern int add(int a, int b);

int main() {
    int result = add(3, 5);
    printf("El resultado es: %d\n", result);
    return 0;
}