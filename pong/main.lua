-- from github
push = require 'lib/ulydev/push/push'

WINDOW_WIDTH = 1280
WINDOW_HEIGHT = 720

VIRTUAL_WIDTH = 432
VIRTUAL_HEIGHT = 243

function love.load()
    love.graphics.setDefaultFilter('nearest', 'nearest')

    -- https://www.dafont.com/es/04b-03.font
    mainfont = love.graphics.newFont('assets/fonts/04b03.ttf', 8)
    love.graphics.setFont(mainfont)

    push:setupScreen(VIRTUAL_WIDTH, VIRTUAL_HEIGHT, WINDOW_WIDTH, WINDOW_HEIGHT, {
        fullscreen = false,
        vsync = true,
        resizable = false
    })
end

function love.keypressed(key)
    if key == 'escape' then
        love.event.quit()
    end
end

n = 0
gdt = 0
fixed_gdt = 0
time = 0
function love.update(dt)
    gdt = dt
    time = time + dt
    n = n + 1
end

function love.draw(dt)
    push:apply('start')

    -- clear the whole screen
    love.graphics.clear(40 / 255, 40 / 255, 40 / 255, 1)

    -- print the title
    love.graphics.printf('Hello world', 0, 20, VIRTUAL_WIDTH, 'center')

    -- draw the ball
    love.graphics.rectangle('fill', VIRTUAL_WIDTH / 2 - 2, VIRTUAL_HEIGHT / 2 - 2, 5, 5)

    -- draw the paddles
    love.graphics.rectangle('fill', 5, 20, 5, 20)
    love.graphics.rectangle('fill', VIRTUAL_WIDTH - 10, VIRTUAL_HEIGHT - 40, 5, 20)

    love.graphics.setColor(1, 0, 0, 1)
    love.graphics.print(tostring(n), 0, 10)
    love.graphics.print(tostring(gdt), 0, 20)
    love.graphics.print(tostring(time), 0, 30)

    if n % 5 == 0 then
        fixed_gdt = gdt
    end
    
    love.graphics.print(tostring(1/fixed_gdt), 0, 40)
    push:apply('end')
end
