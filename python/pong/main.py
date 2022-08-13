import sys
import abc
from enum import IntEnum
from typing import Final, Optional

import pygame as pg

MARGIN: Final = 15


pg.font.init()

font = pg.font.Font("./fonts/bit5x3.ttf", 48)

class SceneInterface(abc.ABC):
    """Scenes are shown to the user and updates the surface according to what scene needs to be shown 
        i.e the game menu, game over scene, or the main gameplay scene"""

    @abc.abstractmethod
    def show(self, screen):
        """show 'this' to the user"""
        pass

class KeyCode(IntEnum):
    key_up   = 0
    key_down = 1
    key_w    = 2
    key_s    = 3

class Player(IntEnum):
    one, two = 1, 2

class ScoreManager:
    
    __winning_score = 7

    def __init__(self):
        # score[0] => 1st Player
        # score[1] => 2nd Player
        self.score_board = [0, 0]
    
    def reset_score_board(self):
        self.score_board = [0, 0]

    def increment_score(self, player: int):
        self.score_board[player-1] += 1

    def is_winner(self):
        return self.score_board[0] == ScoreManager.__winning_score or self.score_board[1] == ScoreManager.__winning_score
    
    def get_winner(self) -> Optional[int]:
        if (self.score_board[0] == ScoreManager.__winning_score):
            return Player.one
        elif (self.score_board[1] == ScoreManager.__winning_score):
            return Player.two
        return None

score_m = ScoreManager()


class SceneManager:
    pass

class MenuScene(SceneInterface):
    
    __text = {
            "title_font"      : pg.font.Font("./fonts/bit5x3.ttf", 108), 
            "subheading_font" : pg.font.Font("./fonts/bit5x3.ttf", 38),
    }

    def __init__(self):
        self.surface = pg.Surface((Game.WINDOW_WIDTH, Game.WINDOW_HEIGHT))
        self.surface.fill(pg.Color("black"))

        self.title = "PONG" 
        self.cta   = "PRESS ENTER TO PLAY"

    def show(self, screen):
        screen_title = MenuScene.__text["title_font"].render(self.title, True, pg.Color("white"))
        screen_play = MenuScene.__text["subheading_font"].render(self.cta, True, pg.Color("white"))
        screen.blit(screen_title, pg.Rect(((Game.WINDOW_WIDTH // 2)-60,60), (58, 58)))
        screen.blit(screen_play, pg.Rect(((Game.WINDOW_WIDTH // 2)-140,Game.WINDOW_HEIGHT - 200), (58, 58)))

class GameScene(SceneInterface):
    def show(self, screen):
        pass

class Ball:
    """"""
    WIDTH:  Final = 14
    HEIGHT: Final = 14

    _INITIAL_VELOCITY: Final = 0.1

    def __init__(self, fill):
        self.center_pos = ((Game.WINDOW_WIDTH-Ball.WIDTH) // 2),  ((Game.WINDOW_HEIGHT- Ball.HEIGHT)//2)
        
        self.pos = pg.Vector2(self.center_pos)
        self.vel = pg.Vector2(Ball._INITIAL_VELOCITY, Ball._INITIAL_VELOCITY)

        self.rect = pg.Rect(self.pos, (Ball.WIDTH, Ball.HEIGHT))

        self.surface = pg.Surface((Ball.WIDTH, Ball.HEIGHT))
        self.surface.fill(fill)
        
    def _go_left(self):
        self.vel.x = (-1 * Ball._INITIAL_VELOCITY)

    def _go_right(self):
        self.vel.x = Ball._INITIAL_VELOCITY

    def _go_up(self):
        self.vel.y = (-1 * Ball._INITIAL_VELOCITY)

    def _go_down(self):
        self.vel.y = Ball._INITIAL_VELOCITY

    def stop_ball(self):
        self.vel.x = 0
        self.vel.y = 0
        self.pos = pg.Vector2(self.center_pos)

    def reset(self):
        self.pos = pg.Vector2(self.center_pos)
        self.rect.update(self.center_pos, (Ball.WIDTH, Ball.HEIGHT))

    def update(self):
        if (self.rect.right >= Game.WINDOW_WIDTH):
            self.reset()
            score_m.increment_score(Player.one)
            self._go_right()
        if (self.rect.left <= 0): 
            self.reset()
            score_m.increment_score(Player.two)
            self._go_left()
        if (self.rect.top <= 0):
            self._go_down()
        if (self.rect.bottom >= Game.WINDOW_HEIGHT):
            self._go_up()

        self.pos.x += self.vel.x 
        self.pos.y += self.vel.y

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

        self.pos = pg.Vector2(x, _middle_y_position)
        self.vel = pg.Vector2(0, 15)

        # set the initial positon of the paddle
        self.rect = pg.Rect(self.pos, (Paddle.WIDTH, Paddle.HEIGHT))

        self.surface = pg.Surface((Paddle.WIDTH, Paddle.HEIGHT))
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

    __paddle_sound = "hit_paddle.mp3"

    def __init__(self):
           
        pg.init()
        pg.mixer.init()

        self.sound = pg.mixer.Sound("./sfx/" + Game.__paddle_sound)

        pg.display.set_caption("Pong")

        self.screen = pg.display.set_mode((Game.WINDOW_WIDTH, Game.WINDOW_HEIGHT))

        self.pong_ball    = Ball(pg.Color("white"))
        self.left_paddle  = Paddle(MARGIN, 0, pg.Color("white"))
        self.right_paddle = Paddle((Game.WINDOW_WIDTH-Paddle.WIDTH)-MARGIN, 0, pg.Color("white"))

        self.event_m = EventManager()
        self.score_m = ScoreManager()
    
    def update(self):
        self.left_paddle.update()
        self.right_paddle.update()
        self.pong_ball.update()

    def draw(self):
        self.screen.fill(pg.Color("black"))
        self.left_paddle.draw(self.screen)
        self.pong_ball.draw(self.screen)
        self.right_paddle.draw(self.screen)

        font_s_1 = font.render(str(self.score_m.score_board[0]), True, pg.Color("white"))
        font_s_2 = font.render(str(self.score_m.score_board[1]), True, pg.Color("white"))
        self.screen.blit(font_s_1, pg.Rect(( 
            (Game.WINDOW_WIDTH // 2) - 48 - 12, 10), 
            (font_s_1.get_width(), font_s_1.get_height())))
        self.screen.blit(font_s_2, pg.Rect(( 
            (Game.WINDOW_WIDTH // 2) - 48 + 86, 10), 
            (font_s_2.get_width(), font_s_2.get_height())))

        pg.display.flip()

    def run(self):
        while True:
            for event in pg.event.get():

                match event.type:
                    case pg.QUIT:
                        sys.exit()
                    case pg.KEYDOWN:
                        if (event.key == pg.K_UP):
                            self.event_m.handle_keydown(KeyCode.key_up)
                        if (event.key == pg.K_DOWN):
                            self.event_m.handle_keydown(KeyCode.key_down)
                        if (event.key == pg.K_w):
                            self.event_m.handle_keydown(KeyCode.key_w)
                        if (event.key == pg.K_s):
                            self.event_m.handle_keydown(KeyCode.key_s)
                    case pg.KEYUP:
                        if (event.key == pg.K_UP):
                            self.event_m.handle_keyup(KeyCode.key_up) 
                        if (event.key == pg.K_DOWN):
                            self.event_m.handle_keyup(KeyCode.key_down)
                        if (event.key == pg.K_w):
                            self.event_m.handle_keyup(KeyCode.key_w)
                        if (event.key == pg.K_s):
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
            
            # TODO: this function should not dictate the control of the ball, this should be done in the Ball class
            if (self.pong_ball.rect.colliderect(self.left_paddle.rect)):
                self.sound.play()
                self.pong_ball._go_right()

            if (self.pong_ball.rect.colliderect(self.right_paddle.rect)):
                self.sound.play()
                self.pong_ball._go_left()

            self.update()

            self.draw()

def main():
    Game().run()

if __name__ == "__main__":
    main()
