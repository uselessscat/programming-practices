from mpl_toolkits.mplot3d import Axes3D

import numpy as np
import matplotlib.pyplot as plt

radial_inicial = 10
azimutal_inicial = 3
altura_inicial = 1

print("radial_inicial: " + str(radial_inicial)
      + " azimutal_inicial: " + str(azimutal_inicial)
      + " altura_inicial: " + str(altura_inicial))

# preparar grafico
fig = plt.figure()
axis = fig.gca(projection='3d', proj_type='ortho')

# generar datos de tiempo
desde_t, hasta_t, iteraciones = 0, 3, 1000
tiempo = np.linspace(desde_t, hasta_t, iteraciones, dtype=np.float64)

axis.plot([0, 0],
          [0, 0],
          [altura_inicial * desde_t ** (2/3), altura_inicial * hasta_t ** (2/3)],
          'k--')

radial, azimutal, altura = (
    radial_inicial + tiempo * 0,
    azimutal_inicial * tiempo ** 2,
    altura_inicial * tiempo ** (2/3)
)

x, y, z = (
    radial * np.cos(azimutal),
    radial * np.sin(azimutal),
    altura
)

# graficar posiciones
axis.plot(x, y, z, 'r-', label='Posicion')

v_radial, v_azimutal, v_altura = (
    tiempo * 0,
    (2 * azimutal_inicial * tiempo),
    (2/3) * altura_inicial * tiempo ** (-1/3)
)

vx, vy, vz = (
    v_radial * np.cos(azimutal) - radial * v_azimutal * np.sin(azimutal),
    v_radial * np.sin(azimutal) + radial * v_azimutal * np.cos(azimutal),
    v_altura
)

# disminuir la cantidad de puntos para los vectores de velocidad
iteraciones_vectores = 3 * 10
iteraciones_n = np.round(np.linspace(
    0, iteraciones - 1, iteraciones_vectores)).astype(int)

# graficar los puntos del origen de los vectores velocidad
axis.plot(x[iteraciones_n], y[iteraciones_n], z[iteraciones_n], 'r.')

# normalize, length y arrow_length_ratio son para fijar el tamaño
# de los vectores, eliminalos para ver los tamaños reales (el grafico se desfigura xd)
axis.quiver(x[iteraciones_n], y[iteraciones_n], z[iteraciones_n],
            vx[iteraciones_n], vy[iteraciones_n], vz[iteraciones_n], label='Velocidad',
            normalize=True, length=10, arrow_length_ratio=0.01)


def aceleracion(tiempo):
    coord_radial = tiempo * 0
    coord_azimutal = 2 * azimutal_inicial
    coord_alturas = (-2/9) * altura_inicial * tiempo ** (-4/3)

    return coord_radial * np.cos(coord_azimutal), coord_radial * np.sin(coord_azimutal), coord_alturas

# ax, ay, az = aceleracion(tiempo)
# axis.plot(ax, ay, az, 'g-', label='Aceleracion')


axis.legend()
plt.show()
