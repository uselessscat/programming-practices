Ball = Class{}

local function reset_ball(ball)
    ball.x = ball.initial_x
    ball.y = ball.initial_y

    ball.dx = math.random(2) == 1 and -100 or 100
    ball.dy = math.random(-200, 200)
end

function Ball:init(x, y, width, height)
    self.initial_x = x
    self.initial_y = y

    self.width = width
    self.height = height

    reset_ball(self)
end

function Ball:reset()
    reset_ball(self)
end

function Ball:collides(box)
    -- check x axis
    if self.x > box.x + box.width or self.x + self.width < box.x then
        return false
    end

    -- check y axis
    if self.y > box.y + box.height or self.y + self.height < box.y then
        return false
    end

    return true
end

function Ball:ensureCorrectServing(player)
    self.dx = player == 1 and math.abs(self.dx) or -math.abs(self.dx)
end

function Ball:update(dt)
    self.x = self.x + self.dx * dt
    self.y = self.y + self.dy * dt
end

function Ball:draw()
    love.graphics.rectangle('fill', self.x, self.y, self.width, self.height)
end