import numpy as np
import matplotlib.pyplot as plt

import vpython as vp
from vpython import vector as v

# gravitacion
c_gravitacional = 1
masa_centro = 1e5

vp.canvas(width=1240, height=600, background=vp.color.black)

def generarEstrellas(cant_estrellas=2000):
    # constantes
    golden = (1 + 5 ** 0.5) / 2

    # valores espiral
    radio_i, radio_f = 2, 100.0
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

    # verificar modelos
    # plt.scatter(x, y, masas, z, cmap='binary')
    # plt.plot(radios, angulos, 'b.')
    # plt.plot(radios, constante, 'r.')
    # plt.plot(radios, mult, 'g.')
    # plt.show()

    return np.transpose([x, y, z]).tolist()


def calcularMagnitud(x, y, z):
    return np.sqrt(x**2 + y**2 + z**2)


def calcularAceleracionCentripeta(posiciones, aceleracionAnterior=[]):
    if (len(aceleracionAnterior) == len(posiciones)):
        for i in range(len(posiciones)):
            magnitud = calcularMagnitud(
                posiciones[i][0], posiciones[i][1], posiciones[i][2])
            aceleracion_x = -posiciones[i][0] / magnitud
            aceleracion_y = -posiciones[i][1] / magnitud
            aceleracion_z = -posiciones[i][2] / magnitud

            m_aceleracion = c_gravitacional * masa_centro / (magnitud * magnitud)

            aceleracionAnterior[i][0] = aceleracion_x * m_aceleracion
            aceleracionAnterior[i][1] = aceleracion_y * m_aceleracion
            aceleracionAnterior[i][2] = aceleracion_z * m_aceleracion
    else:
        for i in range(len(posiciones)):
            magnitud = calcularMagnitud(posiciones[i][0], posiciones[i][1], posiciones[i][2])

            aceleracion_x = -posiciones[i][0] / magnitud
            aceleracion_y = -posiciones[i][1] / magnitud
            aceleracion_z = -posiciones[i][2] / magnitud

            m_aceleracion = c_gravitacional * masa_centro / (magnitud * magnitud)

            aceleracionAnterior.append([
                aceleracion_x * m_aceleracion,
                aceleracion_y * m_aceleracion,
                aceleracion_z * m_aceleracion])

    return aceleracionAnterior


def calcularVelocidadInicial(posiciones, aceleraciones):
    velocidades = []
    for i in range(len(posiciones)):
        magnitud = calcularMagnitud(posiciones[i][0], posiciones[i][1], posiciones[i][2])

        # vector perpendicular unitario
        magnitud_perpendicular = calcularMagnitud(-posiciones[i][1], posiciones[i][0], 0)
        perp_x = -posiciones[i][1] / magnitud_perpendicular
        perp_y = posiciones[i][0] / magnitud_perpendicular 

        velocidades.append([
            np.sqrt(c_gravitacional * masa_centro / magnitud) * perp_x + np.random.rand() * 10,
            np.sqrt(c_gravitacional * masa_centro / magnitud) * perp_y + np.random.rand() * 10,
            0])

    return velocidades


count = 2000
posiciones = generarEstrellas(count)
aceleraciones = calcularAceleracionCentripeta(posiciones)
velocidades = calcularVelocidadInicial(posiciones, aceleraciones)

sCentro = vp.sphere(pos=v(0, 0, 0), radius=1, color=vp.color.red)

estrellas = []
for i in range(len(posiciones)):
    estrellas.append(vp.sphere(pos=v(posiciones[i][0], posiciones[i][1], posiciones[i][2]), radius=0.1, color=vp.color.white))

rate = 100
delta_tiempo = 0.007
delta_tiempo_2 = delta_tiempo ** 2
while True:
    vp.rate(rate)
    aceleraciones = calcularAceleracionCentripeta(posiciones, aceleraciones)

    for i in range(count):
        velocidades[i][0] -= aceleraciones[i][0] * delta_tiempo
        velocidades[i][1] -= aceleraciones[i][1] * delta_tiempo
        velocidades[i][2] -= aceleraciones[i][2] * delta_tiempo

        posiciones[i][0] = posiciones[i][0] - velocidades[i][0] * delta_tiempo
        posiciones[i][1] = posiciones[i][1] - velocidades[i][1] * delta_tiempo
        posiciones[i][2] = posiciones[i][2] - velocidades[i][2] * delta_tiempo

        estrellas[i].pos.x = posiciones[i][0]
        estrellas[i].pos.y = posiciones[i][1]
        estrellas[i].pos.z = posiciones[i][2]
