
#include <stdio.h>

void sort(int array[], int elements){
    for(int i = 0; i < elements; i++){
        for(int e = i; e < elements; e++){
            if(array[i] > array[e]){
                int aux = array[e];
                array[e] = array[i];
                array[i] = aux;
            }
        }
    }
}

void printArray(int array[], int elements){
    for(int i = 0; i < elements; i++){
        printf("%d ", array[i]);
    }
}

int main(void){
    int numbers[] = {1,34,6,50,1,28,341,9,12,534,3,8,1,29,5,1,52,384,9,1,0,62,834,6};
    int elements = sizeof(numbers)/sizeof(int);
    
    printArray(numbers, elements);
    printf("\n");
    sort(numbers, elements);
    printArray(numbers, elements);
    
    return 0;
}
