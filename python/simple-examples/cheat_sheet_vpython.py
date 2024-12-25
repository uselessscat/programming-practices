import vpython as vp

# para llamar a vector de la forma v(0,0,0)
from vpython import vector as v

# ejemplo 1
#vp.sphere(radius=0.5, pos=vp.vector(1.0, -0.2, 0.0), color=vp.color.green)

# ejemplo 2
#L = 5
#R = 0.3
# for i in range(-L, L+1):
#    for j in range(-L, L+1):
#        for k in range(-L, L+1):
#            vp.sphere(pos=v(i, j, k), radius=R)

# ejemplo 3
# vp.canvas(x=100, y=100, width=600, height=600,
#            center=v(5, 0, 0), forward=v(0, 0, -1),
#            background=vp.color.blue, foreground=vp.color.yellow)
# vp.sphere()

# ejemplo 4
# vp.canvas(background=vp.color.blue)
# vp.sphere()

# ejemplo 5
#d = vp.canvas()
#d.background = vp.color.black
# vp.sphere()

# ejemplo 6
#a, b, c = 1, 2, 3
#L, H, W = 1, 1, 1
# vp.box(pos=v(1, 1, 1), axis=v(a, b, c), length=L,
#       height=H, width=W)
#vp.cone(pos=v(3, 1, 1), axis=v(a, b, c), radius=2)
#vp.cylinder(pos=v(3, 3, 3), axis=v(a, b, c), radius=2)
#vp.pyramid(pos=v(1, 3, 1), size=v(a, b, c))
# vp.arrow(pos=v(1, 1, 3), axis=v(a, b, c),
#         headwidth=H, headlength=L, shaftwidth=W)

# ejemplo 6
#from numpy import arange, cos, sin, pi
#
#s = vp.sphere(pos=v(1, 0, 0), radius=0.1)
# for theta in arange(0, 10*pi, 0.1):
#    vp.rate(30)
#    x = cos(theta)
#    y = sin(theta)
#    s.pos = v(x, y, 0)

# ejemplo 7
floor = vp.box(pos=v(0, 0, 0), length=4, height=0.5, width=4, color=vp.color.blue)
ball = vp.sphere(pos=v(0, 4, 0), radius=1, color=vp.color.red)
ball.velocity = v(0, -1, 0)
dt = 0.01
while 1:
    vp.rate(100)
    ball.pos = ball.pos + ball.velocity*dt

    if ball.pos.y < ball.radius:
        ball.velocity.y = abs(ball.velocity.y)
    else:
        ball.velocity.y = ball.velocity.y - 9.8*dt
