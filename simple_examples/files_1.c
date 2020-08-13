#include <errno.h>
#include <string.h>
#include <stdio.h>


int main(){
    FILE *file;
    
    /**
     modes:
     r (read)
     w (write)
     a (append)
     r+ (read + update)
     w+ (write + update)
     
     b (binary)
     t (text)
    */
    if((file = fopen("./file.bin", "r+")) != NULL){
        
        int read;
        
        while ((read = fgetc(file)) != EOF){
            printf("%c", read);
        }
        
        printf("\n");
        
        if (fclose(file) == EOF){
            printf("No se puede cerrar");
        }
    } else {
        printf("No se puede abrir. Err: %s \n", strerror(errno));
        
        return errno;
    }
    
    return 1;
}
