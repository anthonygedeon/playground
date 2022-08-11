import sys, pygame
from enum import IntEnum
from typing import Final

MARGIN: Final = 15

class KeyCode(IntEnum):
    key_up   = 0
    key_down = 1
    key_w    = 2
    key_s    = 3


class Color:
    BLACK: Final = 0, 0, 0
    WHITE: Final = 255, 255, 255

class Ball:
    """"""
    WIDTH:  Final = 14
    HEIGHT: Final = 14

    def __init__(self, fill):
        self.center_pos = ((Game.WINDOW_WIDTH-Ball.WIDTH) // 2),  ((Game.WINDOW_HEIGHT- Ball.HEIGHT)//2)
        
        self.pos = pygame.Vector2(self.center_pos)
        self.vel = pygame.Vector2(1, 1)

        self.rect = pygame.Rect(self.pos, (Ball.WIDTH, Ball.HEIGHT))

        self.surface = pygame.Surface((Ball.WIDTH, Ball.HEIGHT))
        self.surface.fill(fill)
        
    def _go_left(self):
        self.pos.x -= (-1 * self.vel.x)

    def _go_right(self):
        self.pos.x += self.vel.x

    def _go_up(self):
        pass

    def _go_down(self):
        pass

    def reset(self):
        self.rect.update(self.center_pos, (Ball.WIDTH, Ball.HEIGHT))
        self.vel = pygame.Vector2(0, 0)

    def update(self):
        if (self.rect.right >= Game.WINDOW_WIDTH):
            self._go_left()
        else:
            self._go_right()

        self.rect.update(self.pos, (Ball.WIDTH, Ball.HEIGHT))

    def draw(self, screen):
        screen.blit(self.surface, self.rect)

class EventManager:

    class State(IntEnum):
        on, off = 1, 0

    def __init__(self):
        self.buffer: list[int] = [0, 0, 0, 0]

    def __repr__(self):
        return "[ K_UP({}), K_DW({}), K_w({}), K_s({}) ]".format(self.buffer[0], 
                self.buffer[1], 
                self.buffer[2], 
                self.buffer[3])
    
    def handle_keydown(self, KeyCode):
        """When a key is pressed, update the state of the event buffer of index 'KeyCode' to 1
            
            This will keep track of what keycodes are pressed
        """
        self.buffer[KeyCode] = EventManager.State.on

    def handle_keyup(self, KeyCode):
        """When a key is pressed, update the state of the event buffer of index 'KeyCode' to 0
            
            If the key is longer being pressed, reset the index of KeyCode back to 0 so we can handle the 
            state 
        """
        self.buffer[KeyCode] = EventManager.State.off

class Paddle:
    """"""
    WIDTH:  Final = 15
    HEIGHT: Final = 140

    def __init__(self, x, y, fill):
        _middle_y_position = ((Game.WINDOW_HEIGHT - Paddle.HEIGHT)//2)

        self.pos = pygame.Vector2(x, _middle_y_position)
        self.vel = pygame.Vector2(0, 15)

        # set the initial positon of the paddle
        self.rect = pygame.Rect(self.pos, (Paddle.WIDTH, Paddle.HEIGHT))

        self.surface = pygame.Surface((Paddle.WIDTH, Paddle.HEIGHT))
        self.surface.fill(fill)
    
    def _colliding_with_screen(self):
        # TODO: Instead of using Window dimensions, use game.screen instead with 'get_rect()'
        if (self.rect.top <= 0):
            self.pos.y = 1
        if (self.rect.bottom >= Game.WINDOW_HEIGHT):
            self.pos.y = (Game.WINDOW_HEIGHT - Paddle.HEIGHT)

    def move_up(self):
        # TODO: Consider using ints instead of floats
        self.pos.y -= 0.1

    def move_down(self):
        # TODO: Consider using ints instead of floats
        self.pos.y += 0.1

    def update(self):
        self.rect.update(self.pos, (Paddle.WIDTH, Paddle.HEIGHT))
        self._colliding_with_screen()

    def draw(self, screen):
        screen.blit(self.surface, self.rect)

class Game:
    
    WINDOW_WIDTH:  Final = 640
    WINDOW_HEIGHT: Final = 480

    def __init__(self):
           
        pygame.init()

        pygame.display.set_caption("Pong")

        self.screen = pygame.display.set_mode((Game.WINDOW_WIDTH, Game.WINDOW_HEIGHT))

        self.pong_ball    = Ball(Color.WHITE)
        self.left_paddle  = Paddle(MARGIN, 0, Color.WHITE)
        self.right_paddle = Paddle((Game.WINDOW_WIDTH-Paddle.WIDTH)-MARGIN, 0, Color.WHITE)

        self.event_m = EventManager()
    
    def update(self):
        self.left_paddle.update()
        self.right_paddle.update()
        self.pong_ball.update()

    def draw(self):
        self.screen.fill(Color.BLACK)
        self.left_paddle.draw(self.screen)
        self.pong_ball.draw(self.screen)
        self.right_paddle.draw(self.screen)
        pygame.display.flip()

    def run(self):
        while True:
            for event in pygame.event.get():

                match event.type:
                    case pygame.QUIT:
                        sys.exit()
                    case pygame.KEYDOWN:
                        if (event.key == pygame.K_UP):
                            self.event_m.handle_keydown(KeyCode.key_up)
                        if (event.key == pygame.K_DOWN):
                            self.event_m.handle_keydown(KeyCode.key_down)
                        if (event.key == pygame.K_w):
                            self.event_m.handle_keydown(KeyCode.key_w)
                        if (event.key == pygame.K_s):
                            self.event_m.handle_keydown(KeyCode.key_s)
                    case pygame.KEYUP:
                        if (event.key == pygame.K_UP):
                            self.event_m.handle_keyup(KeyCode.key_up)
                        if (event.key == pygame.K_DOWN):
                            self.event_m.handle_keyup(KeyCode.key_down)
                        if (event.key == pygame.K_w):
                            self.event_m.handle_keyup(KeyCode.key_w)
                        if (event.key == pygame.K_s):
                            self.event_m.handle_keyup(KeyCode.key_s)
            
            # TODO: How can we improve this code?
            if (self.event_m.buffer[KeyCode.key_up]):
                self.right_paddle.move_up()
            if (self.event_m.buffer[KeyCode.key_down]):
                self.right_paddle.move_down()
            if (self.event_m.buffer[KeyCode.key_w]):
                self.left_paddle.move_up()
            if (self.event_m.buffer[KeyCode.key_s]):
                self.left_paddle.move_down()

            self.update()

            self.draw()

def main():
    Game().run()

if __name__ == "__main__":
    main()
