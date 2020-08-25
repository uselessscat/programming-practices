-- from github
push = require 'lib/ulydev/push/push'

WINDOW_WIDTH = 1280
WINDOW_HEIGHT = 720

VIRTUAL_WIDTH = 432
VIRTUAL_HEIGHT = 243

-- pixels per second
PADDLE_SPEED = 200

function love.load()
    initializeVariables()

    love.graphics.setDefaultFilter('nearest', 'nearest')

    -- https://www.dafont.com/es/04b-03.font
    mainFont = love.graphics.newFont('assets/fonts/04b03.ttf', 8)
    scoreFont = love.graphics.newFont('assets/fonts/04b03.ttf', 32)

    push:setupScreen(VIRTUAL_WIDTH, VIRTUAL_HEIGHT, WINDOW_WIDTH, WINDOW_HEIGHT, {
        fullscreen = false,
        vsync = true,
        resizable = false
    })
end

function initializeVariables()
    gameState = 'start'

    playerOneScore = 0
    playerTwoScore = 0

    playerOnePos = 20
    playerTwoPos = VIRTUAL_HEIGHT - 40

    ballX = VIRTUAL_WIDTH / 2 - 2
    ballY = VIRTUAL_HEIGHT / 2 - 2

    ballDX = math.random(2) == 1 and -100 or 100
    ballDY = math.random(-50, 50)
end

function love.keypressed(key)
    if key == 'escape' then
        love.event.quit()
    elseif key == 'enter' or key == 'return' then
        if gameState == 'start' then
            gameState = 'play'
        elseif gameState == 'play' then
            initializeVariables()
        end
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

    playerOnePos = getUpdatedPaddlePosition('w', 's', playerOnePos, dt)
    playerTwoPos = getUpdatedPaddlePosition('up', 'down', playerTwoPos, dt)

    if gameState == 'play' then
        ballX = ballX + ballDX * dt
        ballY = ballY + ballDY * dt
    end
end

function getUpdatedPaddlePosition(keyUp, keyDown, actualPosition, dt)
    if love.keyboard.isDown(keyUp) then
        return math.max(0, actualPosition - PADDLE_SPEED * dt)
    elseif love.keyboard.isDown(keyDown) then
        return math.min(VIRTUAL_HEIGHT - 20, actualPosition + PADDLE_SPEED * dt)
    else
        return actualPosition
    end
end

function love.draw(dt)
    push:apply('start')

    -- clear the whole screen
    love.graphics.clear(40 / 255, 40 / 255, 40 / 255, 1)

    -- print the title
    love.graphics.setFont(mainFont)
    if gameState == 'start' then
        love.graphics.printf('Press [Enter] to start the game!', 0, 20, VIRTUAL_WIDTH, 'center')
    elseif gameState == 'play' then
        love.graphics.printf('Playing', 0, 20, VIRTUAL_WIDTH, 'center')
    end

    -- draw the ball
    love.graphics.rectangle('fill', ballX, ballY, 5, 5)

    -- draw the paddles
    love.graphics.rectangle('fill', 10, playerOnePos, 5, 20)
    love.graphics.rectangle('fill', VIRTUAL_WIDTH - 15, playerTwoPos, 5, 20)

    -- print the score in background
    love.graphics.setFont(scoreFont)
    love.graphics.print(playerOneScore, VIRTUAL_WIDTH / 2 - 50, VIRTUAL_HEIGHT / 3)
    love.graphics.print(playerTwoScore, VIRTUAL_WIDTH / 2 + 30, VIRTUAL_HEIGHT / 3)

    printInformation()

    push:apply('end')
end

function printInformation()
    love.graphics.setFont(mainFont)

    love.graphics.setColor(1, 0, 0, 1)
    love.graphics.print(tostring(n), 0, 10)
    love.graphics.print(tostring(gdt), 0, 20)
    love.graphics.print(tostring(time), 0, 30)

    if n % 10 == 0 then
        fixed_gdt = gdt
    end

    love.graphics.print(tostring(1/fixed_gdt), 0, 40)
end