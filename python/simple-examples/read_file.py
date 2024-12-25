#abrir fichero
import numpy as np
import math as m

print('Ingrese la direccion del fichero: ')

# la direccion del archivo
# listado de numeros random 
filePath = input()

data = np.loadtxt(filePath)

print('datos: ' + str(data))
print('promedio: ' + str(np.mean(data)))
print('media cuadratica: ' + str(np.mean(data ** 2)))