#include <errno.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

const char READ_WRITE_MODE[] = "r+";
const char LINE_FORMAT[] = "%-*s\t%s\n";
const int LINE_LENGTH = 16;

int main(){
    FILE *file;

    if((file = fopen("./file.bin", READ_WRITE_MODE)) == NULL){
        printf("No se puede abrir. Err: %s \n", strerror(errno));
        
        return errno;
    }
    
    printf("Printing file:\n");
    
    unsigned long reads = 0,
                  totalReads = 0;
    char readBuffer[LINE_LENGTH],
         hexLine[LINE_LENGTH * 3 + 1],
         charLine[LINE_LENGTH + 1];
    
    // read until no chars remain
    while ((reads = fread(readBuffer, sizeof(char), LINE_LENGTH, file)) > 0) {
        totalReads += reads;
        
        // generate the lines. Hexadecimal and ASCII content
        for (unsigned long i = 0, e = 0; i < reads; i++, e+=3) {
            // print formatted string to char array
            sprintf(&hexLine[e], "%02X ", readBuffer[i]);
            sprintf(&charLine[i], "%c", isprint(readBuffer[i])? readBuffer[i]: '.');
        }
        
        
        printf(LINE_FORMAT, LINE_LENGTH * 3, hexLine, charLine);
        
        reads = 0;
    }
    
    printf("\nReaded %ld bytes\n", totalReads);
    
    if (fclose(file) == EOF){
        printf("No se puede cerrar");
    }
    
    return 1;
}
