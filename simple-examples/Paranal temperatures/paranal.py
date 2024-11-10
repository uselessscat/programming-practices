import numpy as np
import matplotlib.pyplot as plt

from matplotlib import cm
from mpl_toolkits.mplot3d import Axes3D

data = np.loadtxt('D:\Proyectos\Practicas\python\Temperatura paranal\TMP_MM5_Paranal.dat')

fig = plt.figure()

ax = plt.subplot(111, projection='3d', proj_type='ortho')
ax.set_title('Temperatura sobre Paranal', )
ax.set_xlabel('Tiempo [minutos]')
ax.set_ylabel('Altura [kilometros]')
ax.set_zlabel('Temperatura [celcius]')

x, y = np.meshgrid(np.arange(0, len(data[0]) * 10, 10), np.arange(0, len(data), 1))

ax.plot_surface(x, y, data - 273.15, cmap=cm.viridis)

# esto genera un plano horizonal en z = 0
ax.plot_surface(
    np.array([[0, len(data[0]) * 10], [0, len(data[0]) * 10]]),
    np.array([[0, 0], [len(data), len(data)]]),
    np.array([[0, 0], [0, 0]]), color=(1.0, 1.0, 1.0, 0.3))

plt.show()
