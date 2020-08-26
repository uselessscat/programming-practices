-- from github
push = require 'lib/ulydev/push/push'
Class = require 'lib/vrld/hump/class'

require 'Paddle'
require 'Ball'

WINDOW_WIDTH = 1280
WINDOW_HEIGHT = 720

VIRTUAL_WIDTH = 432
VIRTUAL_HEIGHT = 243

-- pixels per second
PADDLE_SPEED = 200

function love.load()
    love.window.setTitle('Best pong ever!')
    love.graphics.setDefaultFilter('nearest', 'nearest')
    
    -- https://www.dafont.com/es/04b-03.font
    mainFont = love.graphics.newFont('assets/fonts/04b03.ttf', 8)
    scoreFont = love.graphics.newFont('assets/fonts/04b03.ttf', 32)
    
    push:setupScreen(VIRTUAL_WIDTH, VIRTUAL_HEIGHT, WINDOW_WIDTH, WINDOW_HEIGHT, {
        fullscreen = false,
        vsync = true,
        resizable = false
    })

    initializeVariables()
end

function initializeVariables()
    gameState = 'start'

    ball = Ball(VIRTUAL_WIDTH / 2 - 2, VIRTUAL_HEIGHT / 2 - 2, 5, 5)
    
    paddleOne = Paddle(10, 20, 5, 20)
    paddleTwo = Paddle(VIRTUAL_WIDTH - 15, VIRTUAL_HEIGHT - 40, 5, 20)

    playerServing = math.random(2) == 1 and 1 or 2
    ball:ensureCorrectServing(playerServing)
    
    playerOneScore = 0
    playerTwoScore = 0
end

function love.keypressed(key)
    if key == 'escape' then
        love.event.quit()
    elseif key == 'enter' or key == 'return' then
        if gameState == 'start' then
            gameState = 'serve'
        elseif gameState == 'serve' then
            gameState = 'play'
        end
    end
end

function sleep (a) 
    local sec = tonumber(os.clock() + a); 
    while (os.clock() < sec) do 
    end 
end

function love.update(dt)
    -- sleep(0.1)
    gdt = dt
    time = time + dt
    n = n + 1
    
    if gameState == 'play' then
        updatePaddle('w', 's', paddleOne, dt)
        updatePaddle('up', 'down', paddleTwo, dt)

        if ball:collides(paddleOne) or ball:collides(paddleTwo) then
            ball.dx = -ball.dx
        end

        if ball.y <= 0 then
            ball.dy = -ball.dy
            ball.y = 0
        end

        if ball.y >= VIRTUAL_HEIGHT - ball.height then
            ball.dy = -ball.dy
            ball.y = VIRTUAL_HEIGHT - ball.height
        end

        if ball.x <= 0 then
            gameState = 'serve'
            playerServing = 1
            playerTwoScore = playerTwoScore + 1
            ball:reset()
            ball:ensureCorrectServing(playerServing)
        end
        
        if ball.x >= VIRTUAL_WIDTH + ball.width then
            gameState = 'serve'
            playerServing = 2
            playerOneScore = playerOneScore + 1
            ball:reset()
            ball:ensureCorrectServing(playerServing)
        end

        ball:update(dt)
    end
end

function updatePaddle(keyUp, keyDown, paddle, dt)
    if love.keyboard.isDown(keyUp) then
        paddle.dy = -PADDLE_SPEED
    elseif love.keyboard.isDown(keyDown) then
        paddle.dy = PADDLE_SPEED
    else
        paddle.dy = 0
    end

    paddle:update(dt)
end

function love.draw(dt)
    push:apply('start')

    -- clear the whole screen
    love.graphics.clear(40 / 255, 40 / 255, 40 / 255, 1)

    -- print the title
    love.graphics.setFont(mainFont)
    if gameState == 'start' then
        love.graphics.printf('Welcome to Pong!', 0, 20, VIRTUAL_WIDTH, 'center')
        love.graphics.printf('Press [Enter] to start the game!', 0, 32, VIRTUAL_WIDTH, 'center')
    elseif gameState == 'serve' then
        love.graphics.printf('Player ' .. tostring(playerServing) .. '\'s turn!', 0, 20, VIRTUAL_WIDTH, 'center')
        love.graphics.printf('Press [Enter] to serve!', 0, 32, VIRTUAL_WIDTH, 'center')
    end

    -- draw the ball
    ball:draw()

    -- draw the paddles
    paddleOne:render()
    paddleTwo:render()

    -- print the score in background
    love.graphics.setFont(scoreFont)
    love.graphics.print(playerOneScore, VIRTUAL_WIDTH / 2 - 50, VIRTUAL_HEIGHT / 3)
    love.graphics.print(playerTwoScore, VIRTUAL_WIDTH / 2 + 30, VIRTUAL_HEIGHT / 3)

    printInformation()

    push:apply('end')
end

n = 0
gdt = 0
fixed_gdt = 0
time = 0
function printInformation()
    love.graphics.setFont(mainFont)

    love.graphics.setColor(1, 0, 0, 1)
    love.graphics.print("FRAME " .. tostring(n), 0, 10)
    love.graphics.print("DT " .. tostring(gdt - gdt % 0.001), 0, 20)
    love.graphics.print("TIME " .. tostring(time - time % 0.01), 0, 30)
    love.graphics.print("FPS " .. tostring(love.timer.getFPS()), 0, 50)

    if n % 10 == 0 then
        fixed_gdt = gdt
    end

    love.graphics.print("FPS " .. tostring(1/fixed_gdt), 0, 40)
end