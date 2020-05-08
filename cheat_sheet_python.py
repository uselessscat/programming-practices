# Cheat sheet para python 3.*

# para escribir comentarios se usa "#"

# Para importar dependencias/bibliotecas se usa:
# import <nombre> as <alias>
import math as mate
import numpy

# para imprimir por la salida estandar el valor de algo se usa la funcion "print"
# print(<expresion>)
print('Esto es un string (cadena de caracters)')

# para declarar variables, la sintaxis es:
# <nombre1>, <nombre2>, <nombre3> = <valor1>, <valor2>, <valor3>
# se pueden declarar varias al mismo tiempo, usando comas
unNumero = 1
var1, var2 = unNumero, unNumero * 6

# para imprimir variables:
# print(<texto> + str(<expresion no texto>))
print('Valor de unNumero: ' + str(unNumero))
print('Valor de var1: ' + str(var1))
print('Valor de var2: ' + str(var2))

# las operaciones basicas son + - * / % **
suma = 2 + 2
resta = 34 - 16
multiplicacion = 4 * 3
potencia = 2 ** 8

# para dividir se puede usar / (devuelve decimales)
# para division entera (sin decimales) se puede usar //
# para obtener el resto de una division entera se usa %
division = 355 / 113
divisionEntera = 355 // 113
restoDivision = 355 % 113

print('Valor de operaciones: ')
print('  suma: ' + str(suma))
print('  resta: ' + str(resta))
print('  multiplicacion: ' + str(multiplicacion))
print('  potencia: ' + str(potencia))

# para acceder a una funcion dentro de una biblioteca se usa:
# <nombre>.<contenido>
print('  potencia usando math: ' + str(mate.pow(2, 8)))
print('  valor de pi: ' + str(mate.pi))
print('  division: ' + str(division))
print('  division entera: ' + str(divisionEntera))
print('  resto de division entera: ' + str(restoDivision))
print('Esto significa que 113 * 3 + 16 = 355')

# Ejemplos de string
miHermosoPoema = ('Erase una vez un calcetin que salio a la calle'
                  ' y se lo pusieron')

print(miHermosoPoema + ' ..Ta tan!')  # concatenar
print(2 * miHermosoPoema)  # repetir
print(miHermosoPoema[0])  # caracter en posision
print(miHermosoPoema[-1])  # si el indice es negativo se empieza por el final
print(miHermosoPoema[18:26])  # seleccionar una sub cadena
print(miHermosoPoema[:10])  # desde el principio hasta la pos 10
print(miHermosoPoema[10:])  # desde la pos 10 hasta el fin

# obtener la cantidad de letras. Tambien funciona para listas
print('Largo del texto: ' + str(len(miHermosoPoema)))

# mucho texto por hoy, ahora las listas
listaVacia = []
print(listaVacia)

# se puede inicializar de las siguientes formas
for i in range(10):
    listaVacia.append(1)
print(listaVacia)

# usando "comprension"
# sintaxis [expression for variable in list]
listaConCeros = [0 for i in range(10)]
print(listaConCeros)

listaConTexto = ['Saludos x' + str(i) for i in range(10)]
print(listaConTexto)

listaMagna = ['Perro', 'Gato', 'Caballo', 'Zebra']
print(listaMagna)

# Se puede concatenar
listaMagna = listaMagna + ['Hamster', 'Waren']
print(listaMagna)

# Se puede añadir con append
listaMagna.append('Marmota')
listaMagna.append(3.141592)
print(listaMagna)

# no me gustan esto animales, los cambio con: (si la nueva lista está vacia, se eliminan)
listaMagna[2:4] = ['Zorro', 'Pericote']
print(listaMagna)

# Vaciar lista
listaMagna[:] = []
print(listaMagna)

# listas multidimensionales
listaMagna = [
    ['Perro', 'Gato', 'Hamster'],
    ['Zorro', 'Gasela', 'Kanguro', 'Iluminati']
]
print(listaMagna)

# usando comprension
listaMComprension = [[i for j in range(3)] for i in range(3)]
print(listaMComprension)

# Estructuras de control
# if. para bifurcar con condiciones logicas
variableLogica = True

if(variableLogica):
    print('Estoy en el if!')

laTierraEsPlana = True

if not laTierraEsPlana:
    print('La tierra es plana!')
elif 1 != 0:
    print('obvio, 1 no es igual a 0')
else:
    print('Nunca debería entrar acá')

# ahora los ciclos
listaPerros = ['Pastor Aleman', 'Husky Siveriano', 'Golden retriever', 'Rotweiler', 'Beagle', 'Boxer', 'San bernardo',
               'Pit Bull', 'Chihuahua', 'Bichon maltes', 'Dalmata', 'Bull dog', 'Bull terrier', 'Yorkshire', 'Carlino']

# recorrer un listado con for
for perro in listaPerros:
    if perro == 'Chihuahua':
        print(perro + ' Pellito moso, tiernurita muerdecarteros!')
    elif perro == 'Bull terrier':
        print(perro + ', diganle al babe que lo andan buscando!')
    else:
        print(perro + ' feo')

# iterar sobre el listado de perros usando indices desde [4] hasta el ultimo
print('***** listado de perros 2 *******')
for i in range(4, len(listaPerros)):
    print(listaPerros[i])

# usar comprension para editar una lista
listadoPerrosLikes = [perro + ' likes:' + str(numpy.random.randint(0, 10)) for perro in listaPerros]
print(listadoPerrosLikes)