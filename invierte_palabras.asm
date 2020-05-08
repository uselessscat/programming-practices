; Invierte las palabras de una cadena
; https://es.stackoverflow.com/questions/10234/invertir-orden-de-palabras-en-cadena-de-texto-en-ensamblador/21124#21124


.model small
.stack 
.data
    instr1      DB 'Ingrese el texto a invertir:$'
    texto1      DB 255 dup(?)       ; Cadena original ingresada por usuario
    largoTexto  DW 0                ; Cantidad de caracteres que se ingresan

.code
    .startup
; ----------------------------------
; inicializar el programa
; ----------------------------------
    mov     AX, @data               ; Cargar el puntero de .data al registro Acumulador
    mov     DS, AX                  ; Mover el puntero al registro de segmento

; ----------------------------------
; Mostrar el string de instruccion
; ----------------------------------
    mov     DX, offset instr1       ; Cargar el puntero al string en DX (es necesario DS tambien)
    mov     AH, 09h                 ; Preparar el servicio 09h (poner en AH): Display string (ver wiki)
    int     21h                     ; Usar la interrupcion para mostrar el string

; ----------------------------------
; Leer la entrada del usuario (no protegido contra desbordamiento de buffer)
; ----------------------------------
    mov     DI, offset texto1       ; mover el puntero a la cadena al DESTINATION INDEX [DI]
    mov     CX, DI                  ; copiar el puntero a CX para luego obtener el largo de la cadena

    le_leer:
    mov     AH, 01h                 ; servicio 1h Read Character input
    int     21h                     ; interrupcion para leer un caracter (el caracter queda en AL)
    cmp     AL, 13                  ; comparar con retorno de carro
    je      le_terminar             ; Si e retorno de carro, entonces terminar la lectura
    mov     [DI], AL                ; Si no es retorno, mover el caracter al buffer texto1
    inc     DI                      ; Incrementar el puntero de texto1
    jmp     le_leer                 ; volver al inicio del ciclo

    le_terminar:
    mov     [DI], "$"               ; Terminar el string con "$" ($ en ciertas impl. de asm, en c y c++ suele ser el x00)
                                    ; aunque he visto tambien { int lenght , char[] string } sobre todo en archivos
    mov     AX, DI                  ; Mover la ultima posicion del puntero a AX
    sub     AX, CX                  ; Calcular los caracteres leidos y ponerlos en AX
    mov     largoTexto, AX          ; Mover el largo calculado a la variable predestinada para ello

; ----------------------------------
; Invertir toda la linea
; ----------------------------------
    mov     SI, offset texto1       ; Poner el puntero a texto1 en Source Index (este sera el extremo izquierdo)
    mov     DI, offset texto1       ; lo mismo para DI (este sera el extremo derecho)
    add     DI, largoTexto          ; Sumar a DI el largo de la cadena, apuntar al final
    dec     DI                      ; Restar 1 para la conversion de largo a indice(ej: "hola", largo=4, ultimo indice=3)

    il_inicio:
    cmp     SI, DI                  ; Compara SI (desde la derecha) con DI (desde la izquierda)
    jge     il_fin                  ; Si SI es mayor que DI (o sea estan en el centro) terminar el ciclo
    mov     AL, byte ptr[SI]        ; Copia el caracter (byte) de la mitad izquierda al registro AL (byte)
    xchg    AL, byte ptr[DI]        ; Intercambia el contenido de AL con el de DI (EXCHANGE), SI queda en DI, DI en AL
    xchg    AL, byte ptr[SI]        ; Intercambia nuevamente con AL para poner lo que habia en DI en SI
    inc     SI                      ; Aumenta SI
    dec     DI                      ; Disminuye DI (la idea es que se encuentren en el centro de la cadena)
    jmp     il_inicio               ; Repetir el ciclo

    il_fin:                         ; Etiqueta para terminar el ciclo

; ----------------------------------
; Invertir Palabras
; ----------------------------------
    mov     CX, offset texto1       ; Poner el puntero a texto1 en CX (sera nuestro contador)
    mov     BX, offset texto1
    mov     DX, offset texto1       ; En DX ira el puntero al fin de la cadena
    add     DX, largoTexto          ; Sumar el largo para apuntar al final

    ip_for:                         
    cmp     CX, DX                  ; Comparacion que determina si se recorre toda la cadena
    jge     ip_forend               ; Si CX es mayor o igual que DX sale del ciclo
    inc     CX                      ; Actualiza CX; CX++

    ip_if1:                         ; Cuando el caracter actual es espacio y no se esta en la primera posicion
    mov     DI, CX                  ; ** no se como cargar el byte al que apunta CX al registro AL... por lo que lo cargo 
    mov     AL, byte ptr[DI]        ; a DI y luego uso byte ptr[DI] para acceder a el y hacer la comparacion **
    cmp     AL, 32                  ; Compara la posicion actual con espacio " " para determinar que hay una palabra nueva  
    jne     ip_if2                  ; Salta a if2 si el caracter actual no es espacio
    cmp     CX, offset texto1       ; Compara si el contador actual es cero. CX == texto1[0]
    je      ip_if2                  ; Salta a if2 
    mov     SI, BX                  ; Mueve BX a SI, BX mantiene el puntero al inicio de la palabra actual
    mov     DI, CX                  ; Mueve CX a DI, CX mantiene el puntero al fin de la parabra actual
    dec     DI                      ; Disminuye DI para no considerar el espacio de la posicion actual y apuntar a la ultima letra.
    mov     BX, CX                  ; Actualiza BX para apuntar a la siguiente palabra
    inc     BX                      ; Suma 1 a BX por que la posicion actual es un " ".
    jmp     ip_while                ; Salta a l ciclo que invierte la palabra

    ip_if2:                         ; Esta condicion se cumple cuando el puntero esta en el final de la cadena (ultimo caracter)
    mov     AX, DX                  ; Mueve DX (puntero al fin de la palabra) a AX
    dec     AX                      ; Disminuye AX para apuntar a la ultima letra. (antes de esto apuntaba al "$" de cierre)
    cmp     CX, AX                  ; Compara si CX esta en el final de la cadena
    jne     ip_for                  ; Si CX no es igual a text1.length - 1  salta a la siguiente iteracion del ciclo
    mov     SI, BX                  ; Si no Mueve BX a SI. (el inicio de la palabra)
    mov     DI, CX                  ; Mueve CX a DI. DI apunta al ultimo caracter de la cadena

    ip_while:                       ; No hace falta comentar esto, ya que es lo mismo que en "invertir letras"
    cmp     SI, DI 
    jge     ip_for
    mov     AL, byte ptr[SI]
    xchg    AL, byte ptr[DI]
    xchg    AL, byte ptr[SI]
    inc     SI
    dec     DI
    jmp     ip_while

    ip_forend:

; ----------------------------------
; Mostrar el string invertido
; ----------------------------------
    mov     DX, offset texto1       ; Cargar el puntero al string en DX
    mov     AH, 09h                 ; Preparar el servicio 09h (poner en AH): Display string (ver wiki)
    int     21h                     ; Usar la interrupcion para mostrar el string

    .exit
end