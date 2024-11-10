import numpy as np
import matplotlib.pyplot as plt

import vpython as vp
from vpython import vector as v

# constantes
golden, cant_estrellas = (1 + 5 ** 0.5) / 2, 2000

# valores espiral
radio_i, radio_f = 0.1, 100.0
const_i, const_f = 0.1, 0.0001
disp_i, disp_f = 0.1, 10

# calcular espiral
radios = np.linspace(radio_i, radio_f, cant_estrellas)
constante = np.logspace(const_i, const_f, cant_estrellas)
angulos = (constante / (np.log(golden) / (np.pi / 2.0))) * np.log(radios / constante)

# dispersar estrellas
altura_max = np.linspace(1.5, 0.1, cant_estrellas)
mult = np.linspace(disp_i, disp_f, cant_estrellas)
despl_x = np.random.normal(-1, 1, cant_estrellas) * mult
despl_y = np.random.normal(-1, 1, cant_estrellas) * mult
despl_z = np.random.normal(-1, 1, cant_estrellas) * altura_max

# valores de estrellas
x = radios * np.cos(angulos) + despl_x
y = radios * np.sin(angulos) + despl_y
z = despl_z

masa_min, masa_max = 0.15, 0.2
masas = (masa_max - masa_min) * np.random.randn(cant_estrellas) + masa_min

# verificar modelos
#plt.scatter(x, y, masas, z, cmap='binary')
#plt.plot(radios, angulos, 'b.')
#plt.plot(radios, constante, 'r.')
#plt.plot(radios, mult, 'g.')
# plt.show()

# recalcular valores
rate = 100
radios_n = np.sqrt(x**2 + y**2)
angulos_n = np.arctan2(y, x)

# que se yo, no soy 100tifico
constante_g = 6.6
velocidad = np.sqrt(constante_g * masas / radios_n) * rate / 1000

vp.canvas(width=1300, height=700, background=vp.color.black)

estrellas = []
for i in range(cant_estrellas):
    pos_x = radios_n[i] * np.cos(angulos_n[i])
    pos_y = radios_n[i] * np.sin(angulos_n[i])
    estrellas.append(
        vp.sphere(pos=v(pos_x, pos_y, z[i]), radius=masas[i], color=vp.color.white))

# :O
while True:
    vp.rate(rate)

    # actualizar radios
    angulos_n = angulos_n - velocidad

    # actualizar posiciones
    for i in range(cant_estrellas):
        estrellas[i].pos.x = radios_n[i] * np.cos(angulos_n[i])
        estrellas[i].pos.y = radios_n[i] * np.sin(angulos_n[i])
