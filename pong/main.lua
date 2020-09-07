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

VICTORY_REQUIRED = 3

function love.load()
    love.window.setTitle('Best pong ever!')
    love.graphics.setDefaultFilter('nearest', 'nearest')
    
    -- https://www.dafont.com/es/04b-03.font
    mainFont = love.graphics.newFont('assets/fonts/04b03.ttf', 8)
    scoreFont = love.graphics.newFont('assets/fonts/04b03.ttf', 32)
    winFont = love.graphics.newFont('assets/fonts/04b03.ttf', 24)
    
    sounds = {
        ['paddle'] = love.audio.newSource('sound/paddle.wav', 'static'),
        ['point'] = love.audio.newSource('sound/point.wav', 'static'),
        ['wall'] = love.audio.newSource('sound/wall.wav', 'static') 
    }

    push:setupScreen(VIRTUAL_WIDTH, VIRTUAL_HEIGHT, WINDOW_WIDTH, WINDOW_HEIGHT, {
        fullscreen = false,
        vsync = true,
        resizable = true
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
    playerWin = 0

    cpuPlaying = 1
end

function love.resize(w, h)
    push:resize(w, h)
end

function love.keypressed(key)
    if key == 'escape' then
        love.event.quit()
    elseif key == 'enter' or key == 'return' then
        if gameState == 'start' then
            gameState = 'serve'
        elseif gameState == 'victory' then
            initializeVariables()
        elseif gameState == 'serve' then
            gameState = 'play'
        end
    elseif key == "rctrl" then
        debug.debug()
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
        
        if cpuPlaying > 0 then
            paddleTwo.dy = botAction(dt)
            
            paddleTwo:update(dt)
        else
            updatePaddle('up', 'down', paddleTwo, dt)
        end
        
        -- update ball after paddles
        ball:update(dt)

        -- check collision with paddles
        if ball:collides(paddleOne) then
            ball.x = (paddleOne.x + paddleOne.width) + ((paddleOne.x + paddleOne.width) - ball.x)
            ball.dx = -ball.dx
            
            sounds['paddle']:play()
        end

        if ball:collides(paddleTwo) then
            ball.x = paddleTwo.x - ball.width - ((ball.x + ball.width) - paddleTwo.x)
            ball.dx = -ball.dx
            
            sounds['paddle']:play()
        end

        if ball.y <= 0 then
            ball.y = math.abs(ball.y)
            ball.dy = -ball.dy

            sounds['wall']:play()
        end

        if ball.y >= VIRTUAL_HEIGHT - ball.height then
            ball.y = VIRTUAL_HEIGHT - ball.height - (ball.y + ball.height - VIRTUAL_HEIGHT)
            ball.dy = -ball.dy

            sounds['wall']:play()
        end

        if ball.x <= 0 then
            sounds['point']:play()
            playerTwoScore = playerTwoScore + 1
            
            if playerTwoScore >= VICTORY_REQUIRED then
                gameState = 'victory'
                playerWin = 2
            else
                gameState = 'serve'
                playerServing = 1
                ball:reset()
                ball:ensureCorrectServing(playerServing)
            end
        end
        
        if ball.x >= VIRTUAL_WIDTH - ball.width then
            sounds['point']:play()
            playerOneScore = playerOneScore + 1
            
            if playerOneScore >= VICTORY_REQUIRED then
                gameState = 'victory'
                playerWin = 1
            else
                gameState = 'serve'
                playerServing = 2
                ball:reset()
                ball:ensureCorrectServing(playerServing)
            end
        end
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
    if gameState == 'start' then
        love.graphics.setFont(winFont)
        love.graphics.printf('Welcome to Pong!', 0, 20, VIRTUAL_WIDTH, 'center')
        love.graphics.setFont(mainFont)
        love.graphics.printf('Press [Enter] to start the game!', 0, 50, VIRTUAL_WIDTH, 'center')
    elseif gameState == 'serve' then
        love.graphics.setFont(mainFont)
        love.graphics.printf('Player ' .. tostring(playerServing) .. '\'s turn!', 0, 20, VIRTUAL_WIDTH, 'center')
        love.graphics.printf('Press [Enter] to serve!', 0, 32, VIRTUAL_WIDTH, 'center')
    elseif gameState == 'victory' then
        love.graphics.setFont(winFont)
        love.graphics.printf('Player ' .. tostring(playerWin) .. ' wins!', 0, 20, VIRTUAL_WIDTH, 'center')
        love.graphics.setFont(mainFont)
        love.graphics.printf('Press [Enter] to restart!', 0, 50, VIRTUAL_WIDTH, 'center')
    end

    -- draw the ball
    ball:draw()

    -- draw the paddles
    paddleOne:render()
    paddleTwo:render()

    printScore()
    printInformation()
    
    push:apply('end')
end

function printScore()
    -- print the score in background
    love.graphics.setFont(scoreFont)
    love.graphics.print(playerOneScore, VIRTUAL_WIDTH / 2 - 50, VIRTUAL_HEIGHT / 3)
    love.graphics.print(playerTwoScore, VIRTUAL_WIDTH / 2 + 30, VIRTUAL_HEIGHT / 3)
end

posy = 0
tim = 0
function botAction(dt)
    -- this happens every frame, we can improve to happens less often
    timeTo = 0
    pos = 0

    -- calculate the time-to-collision
    if ball.dx > 0 then
        timeTo = (paddleTwo.x - (ball.x + ball.width)) / ball.dx
    else
        absdx = math.abs(ball.dx)
        -- the distance ball-paddle plus paddle-paddle
        timeToPaddleOne = (ball.x - (paddleOne.x + paddleOne.width)) / absdx
        timeToPaddelTwo = (paddleTwo.x - ball.width - (paddleOne.x + paddleOne.width)) / absdx
        timeTo = timeToPaddleOne + timeToPaddelTwo
    end

    -- the collision position calculated 
    pos = math.abs(ball.y + ball.dy * timeTo)

    ADJUSTED_VHEIGHT = VIRTUAL_HEIGHT - ball.height

    -- fix position if is greater than screen
    if math.floor(pos / ADJUSTED_VHEIGHT) % 2 == 0 then
        pos = pos % ADJUSTED_VHEIGHT
    else
        pos = ADJUSTED_VHEIGHT - pos % ADJUSTED_VHEIGHT
    end

    -- debug
    posy = pos
    tim = timeTo
    
    -- adjust the ball pos to the middle
    pos = pos + ball.height / 2
    paddlePos = paddleTwo.y + paddleTwo.height / 2
    absDiff = math.abs(paddlePos - pos)
    dir = -1

    -- set paddle direction
    if paddlePos - pos < 0 then
        dir = 1
    end
    
    -- if the difference of distance is greater than the pladdle move in the next frame, move
    if absDiff > PADDLE_SPEED * dt then
        return PADDLE_SPEED * dir
    else
        return 0
    end
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
    love.graphics.print("POSY " .. tostring(posy), 0, 60)
    love.graphics.print("TIM " .. tostring(tim), 0, 70)
end