--[[
    Represents our Flag in the game, with its own sprite.
]]

Flag = Class{}

function Flag:init(map)
    self.xOffset = 11
    self.yOffset = 6

    self.x = 0
    self.y = 0
    self.width = 16
    self.height = 16

    -- reference to map for checking tiles
    self.map = map

    -- current animation frame
    self.currentFrame = nil

    -- used to determine behavior and animations
    self.state = 'idle'

    self.animations = {
        ['idle'] = Animation({
            texture = self.map.spritesheet,
            frames = {
                self.map.sprites[13],
                self.map.sprites[14],
            },
            interval = 0.25
        }),
        
        ['used'] = Animation({
            texture = self.map.spritesheet,
            frames = {
                self.map.sprites[15]
            }
        })
    }

    -- initialize animation and current frame we should render
    self.animation = self.animations['idle']
    self.currentFrame = self.animation:getCurrentFrame()
end

function Flag:update(dt)
    self.animation:update(dt)
    self.currentFrame = self.animation:getCurrentFrame()
end

function Flag:render()
    love.graphics.draw(self.map.spritesheet, self.currentFrame, self.x, self.y)
end
