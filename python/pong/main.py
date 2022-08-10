import sys, pygame
from typing import Final

MARGIN: Final = 15
pygame.init()

pygame.display.set_caption("Pong")

size = width, height = 640, 480

screen = pygame.display.set_mode(size)

class Color:
    BLACK: Final = 0, 0, 0
    WHITE: Final = 255, 255, 255

class Ball:
    """"""
    WIDTH:  Final = 14
    HEIGHT: Final = 14

    def __init__(self, fill):
        self.center_pos = ((width-Ball.WIDTH) // 2),  ((height - Ball.HEIGHT)//2)

        self.rect = pygame.Rect(self.center_pos, (Ball.WIDTH, Ball.HEIGHT))
        
        self.pos = pygame.Vector2(self.center_pos)
        self.vel = pygame.Vector2(0, 0)

        self.surface = pygame.Surface((Ball.WIDTH, Ball.HEIGHT))
        self.surface.fill(fill)

    def bounce_up(self):
        pass

    def bounce_down(self):
        pass

    def reset(self):
        self.rect.move_ip(self.center_pos)
        self.vel = pygame.Vector2(0, 0)

    def update(self):
        self.pos.y += self.vel.y
        self.pos.x += self.vel.x

    def draw(self, screen):
        screen.blit(self.surface, self.rect)

class Paddle:
    """"""
    WIDTH:  Final = 15
    HEIGHT: Final = 140

    def __init__(self, x, y, fill):
        middle_pos = ((height - Paddle.HEIGHT)//2)

        self.pos = pygame.Vector2(x, middle_pos)
        self.vel = pygame.Vector2(0, 15)

        # set the initial positon of the paddle
        self.rect = pygame.Rect(self.pos, (Paddle.WIDTH, Paddle.HEIGHT))

        self.surface = pygame.Surface((Paddle.WIDTH, Paddle.HEIGHT))
        self.surface.fill(fill)

    def update(self):
        self.pos.y += self.vel.y

    def draw(self, screen):
        screen.blit(self.surface, self.rect)

class Game:
    
    def __init__(self):
        pass

    def run(self):
        pass

def main():
    

    pong_ball    = Ball(Color.WHITE)
    left_paddle  = Paddle(MARGIN, 0, Color.WHITE)
    right_paddle = Paddle((width-Paddle.WIDTH)-MARGIN, 0, Color.WHITE)

    while True:
        for event in pygame.event.get():
            match event.type:
                case pygame.QUIT:
                    sys.exit()
                case pygame.KEYDOWN:
                    if (event.key == pygame.K_UP):
                        left_paddle.pos.y = -1
                    if (event.key == pygame.K_DOWN):
                        left_paddle.pos.y = 1
                    if (event.key == pygame.K_w):
                        right_paddle.pos.y = -1
                    if (event.key == pygame.K_s):
                        right_paddle.pos.y = 1

        # TODO: Handle collision better with left_paddles and screen
        # TODO: DRY duplicated code
        if (left_paddle.rect.bottom >= screen.get_rect().bottom):
            left_paddle.rect.bottom = screen.get_rect().bottom
        if (left_paddle.rect.top < screen.get_rect().top):
            left_paddle.rect.top = screen.get_rect().top

        if (right_paddle.rect.bottom >= screen.get_rect().bottom):
            right_paddle.rect.bottom = screen.get_rect().bottom
        if (right_paddle.rect.top < screen.get_rect().top):
            right_paddle.rect.top = screen.get_rect().top

        pong_ball.vel.x = 1

        if (pong_ball.rect.top <= screen.get_rect().top):
            pong_ball.vel.y = 1
            pong_ball.bounce_down()
        if (pong_ball.rect.bottom >= screen.get_rect().bottom):
            pong_ball.vel.y = -1
            pong_ball.bounce_up()
        if (pong_ball.rect.left <= screen.get_rect().left):
            pong_ball.reset()
        if (pong_ball.rect.right >= screen.get_rect().right):
            pong_ball.reset()

        screen.fill(Color.BLACK)
        left_paddle.draw(screen)
        pong_ball.draw(screen)
        right_paddle.draw(screen)
        
        left_paddle.update()
        right_paddle.update()
        pong_ball.update()

        pygame.display.flip()

if __name__ == "__main__":
    main()

