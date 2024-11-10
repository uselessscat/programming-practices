import numpy as np
import matplotlib.pyplot as graficador
from matplotlib.widgets import Slider, Button

# inicializa variables
tiempo = np.arange(0, 10.0, 0.1)
aceleracion = 9.8
velocidadInicial = 0
posicion = velocidadInicial * tiempo - 0.5 * aceleracion * tiempo ** 2

# configura grafico
fig, ax = graficador.subplots()

# agrega un margen por debajo, para agregar controles
graficador.subplots_adjust(bottom=0.25)

# define los valores limites que se mostraran en los ejes
graficador.axis([0, 10, -20, 20])

# grafica la funcion de caida libre
l, = graficador.plot(tiempo, posicion, lw=2, color='red')

# crea el espacio para el control de velocidad
ejeControl = graficador.axes([0.25, 0.1, 0.65, 0.03])

# crea el control de velocidad
controlVelocidad = Slider(ejeControl, 'Velocidad', -20, 30.0, valinit=velocidadInicial, valstep=0.1)

# funcion que vuelve a calcular los valores de la posicion al cambiar la v. inicial
def actualizar(val):
    velocidad = controlVelocidad.val
    l.set_ydata(velocidad * tiempo - 0.5 * aceleracion * tiempo ** 2)
    fig.canvas.draw_idle()

# añade evento de cambio en control velocidad
controlVelocidad.on_changed(actualizar)

# crea el eje y le asigna el boton
ejeBoton = graficador.axes([0.8, 0.025, 0.1, 0.04])
button = Button(ejeBoton, 'Reset', hovercolor='0.975')

# funcion para reiniciar
def reiniciar(event):
    controlVelocidad.reset()

# añade evento a boton
button.on_clicked(reiniciar)

# muestra el grafico en la pantalla
graficador.show()
