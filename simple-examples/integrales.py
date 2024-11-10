import math as m
import numpy as np

def theFunction(x):
    return x**4 - 2*x + 1

n = 10
limite_inferior = 0
limite_superior = 2
delta_x = (limite_superior - limite_inferior) / n

# integral simple
suma = 0
for i in range(1, n):
    suma += theFunction(limite_inferior + i * delta_x)

suma = delta_x * (0.5*(theFunction(limite_inferior) +
                       theFunction(limite_superior)) + suma)
print('for loop', suma)

# regla simpson
suma_1 = 0
for i in range(1, (int)(n / 2) + 1):
    suma_1 += theFunction(limite_inferior + (2 * i - 1) * delta_x)

suma_2 = 0
for i in range(1, (int)(n / 2)):
    suma_2 += theFunction(limite_inferior + 2 * i * delta_x)

suma = (1/3) * delta_x * (theFunction(limite_inferior) + theFunction(limite_superior) + 4 * suma_1 + 2 * suma_2)
print('simpson', suma)
