/**
 * Programa que asigna memoria y luego la rellena con numeros aleatorios
 */

#include<stdlib.h>
#include<stdio.h>

// define el tipo byte como un unsigned char (0 - 255)
#define byte unsigned char

const int INTEGER_COUNT = 100;

void printByteArray(void *array, int bytes){
    // ej: 0xAB01CD23
    printf("0x%08X (%d elements):\n", (int) array, bytes);
    
    for (int i = 0; i < bytes; i++) {
        byte *pointer = (byte *) array + i;
        
        printf("%02X", *pointer);
        
        if (i % 4 == 3){
            printf(" ");
        }
        
        if (i % 16 == 15){
            printf("\n");
        }
    }
    
    printf("\n");
}

void fillArrayWithRandomBytes(void *array, int bytes){
    for (int i = 0; i < bytes; i++) {
        byte *pointer = (byte *) array + i;
        
        // rand() esta definido en <stdlib.h>
        *pointer = rand() & 0xFF;
    }
}

int main(int argc, const char * argv[]) {
    // reserva "integer_count" enteros
    int *allocated = (int *) malloc(sizeof(int) * INTEGER_COUNT);
    
    if(allocated == NULL) {
        printf("allocation failed");
        
        return 0;
    }
    
    for (int i = 0; i < INTEGER_COUNT; i++){
        // allocated[i]
        *(allocated + i) = 0;
    }
    
    printByteArray(allocated, INTEGER_COUNT * 4);
    fillArrayWithRandomBytes(allocated, INTEGER_COUNT * 4);
    printByteArray(allocated, INTEGER_COUNT * 4);
    
    // es buena practica liberar la memoria explicitamente (?)
    free(allocated);

    return 0;
}
