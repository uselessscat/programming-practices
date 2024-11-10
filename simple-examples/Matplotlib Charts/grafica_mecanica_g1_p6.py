from mpl_toolkits.mplot3d import Axes3D

import numpy as np
import matplotlib.pyplot as plt

fig = plt.figure()
axis = fig.gca(projection='3d', proj_type='ortho')

# generar datos de tiempo
desde_t, hasta_t, iteraciones = 0, 5, 1000
tiempo = np.linspace(desde_t, hasta_t, iteraciones, dtype=np.float64)

x, y, z = (
    2 * tiempo ** 2 - 3,
    4 * tiempo + 4,
    tiempo ** 3 + 2 * tiempo ** 2
)

axis.plot(x, y, z, 'r-', label='Posicion')

vx, vy, vz = (
    4 * tiempo,
    4 + tiempo * 0,
    3 * tiempo ** 2 + 4 * tiempo
)

axis.plot(vx, vy, vz, 'b-', label='Velocidad')

ax, ay, az = (
    4 + tiempo * 0,
    tiempo * 0,
    6 * tiempo + 4
)

axis.plot(ax, ay, az, 'g-', label='Aceleracion')

# disminuir la cantidad de puntos para los vectores de velocidad
iteraciones_vectores = hasta_t - desde_t
iteraciones_n = np.round(np.linspace(
    0, iteraciones - 1, iteraciones_vectores)).astype(int)

# graficar los puntos del origen de los vectores velocidad
axis.plot(x[iteraciones_n], y[iteraciones_n], z[iteraciones_n], 'r.')

axis.legend()
plt.show()
