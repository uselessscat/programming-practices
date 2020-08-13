// pruebas con punteros
#include<stdio.h>

int valorGlobal = 2;

void imprimir1 (){
    printf("imprimir 1\n");
}

void *devolverPuntero (){
    return &valorGlobal;
}

int main(){
    /** prueba de strings y punteros */
    char texto[20] = "Hola como estas";
    
    int pos = 3;
    
    // texto es un puntero, por lo que se puede escribir de ambas formas
    printf("prueba con texto:\n%c\n", texto[pos]);
    printf("%c\n", *(texto + pos));
    
    // debido a que la suma es conmutativa en *(texto + pos)
    // la expresion con "[ ]" como en el siguiente ejemplo, tambien
    printf("%c %c\n", pos[texto], *(pos + texto));
    
    /** pruebas de funciones */
    printf("prueba con funciones y punteros:\n");
    int x = 2;
    
    // puntero que vale 0, definido en stdio o stddef
    int *puntero_nulo = NULL; 
    
    // puntero generico
    void *puntero; 
    
    // almacenar la direccion de x
    puntero = &x; 
    
    // modelar(casting) puntero como un puntero a un int
    int b = * (int *) puntero; 
    
    printf("%d\n", b);
    
    /** Ejemplo con puntero a funcion */
    // puntero a una funcion
    void (*fun1)();
    fun1 = &imprimir1;
    
    // llamar a la funcion de fun1. El operador de "( )" tiene precedencia sobre el "*"
    (*fun1)();
    
    // puntero a una funcion que devuelve un puntero a un valor cualquiera: void* function(){ ... }
    void *(*fun2)() = &devolverPuntero;
    
    // puntero a int
    int* pvalorGlobal = &valorGlobal;
    
    // llamar a fun2 luego modelar (conversion explicita, casting) el resultado (void*) 
    // como un puntero a int y luego deferenciar para asignarle un int
    // fun2 == &devolverPuntero
    // (*fun2)() == devolverPuntero()
    // *(*fun2)() == *devolverPuntero() // no se puede, por que no existen los punteros void. no se pueden "deferenciar"
    // *(int*)(*fun2)() == *(int *)devolverPuntero() // se hace el casting a int
    *(int*)(*fun2)() = 6;
    
    printf("%d\n", *pvalorGlobal);
    printf("%d\n", valorGlobal);
    
    return 0;
}
