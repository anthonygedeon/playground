import sys
import abc
from enum import IntEnum
from typing import Final, Optional

import pygame as pg

MARGIN: Final = 15

pg.init()
pg.font.init()
pg.mixer.init()

fonts = {
    "menu": {
        "title": pg.font.Font("fonts/bit5x3.ttf", 108),
        "cta":   pg.font.Font("fonts/bit5x3.ttf", 42)
    },
    "game": {
        "score": pg.font.Font("fonts/bit5x3.ttf", 48), 
        "reset": pg.font.Font("fonts/bit5x3.ttf", 54)
    }
}

sounds = {
        "collision": {
            "paddle": pg.mixer.Sound("sounds/hit_paddle.mp3")
        }
}

class ScreenInterface(abc.ABC):
    """Screen are shown to the user and updates the surface according to what scene needs to be shown 
        i.e the game menu, game over scene, or the main gameplay scene"""

    @abc.abstractmethod
    def show(self, screen):
        """what to show to the user"""
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
        return self.score_board[0] == self.__winning_score or self.score_board[1] == self.__winning_score
    
    def get_winner(self) -> Optional[int]:
        if (self.score_board[0] == self.__winning_score):
            return Player.one
        elif (self.score_board[1] == self.__winning_score):
            return Player.two
        return None

score_m = ScoreManager()

class MenuScreen(ScreenInterface):

    def __init__(self):
        self.surface = pg.Surface((App.WINDOW_WIDTH, App.WINDOW_HEIGHT))
        self.surface.fill(pg.Color("black"))

        self.title = "pong".upper()
        self.cta   = "press enter to play".upper()

    def show(self, screen):
        screen_title = fonts["menu"]["title"].render(self.title, True, pg.Color("white"))
        screen_play = fonts["menu"]["cta"].render(self.cta, True, pg.Color("white"))
        screen.blit(screen_title, pg.Rect(((App.WINDOW_WIDTH // 2)-60,60), (58, 58)))
        screen.blit(screen_play, pg.Rect(((App.WINDOW_WIDTH // 2)-140,App.WINDOW_HEIGHT - 200), (58, 58)))

class Ball:
    WIDTH:  Final = 14
    HEIGHT: Final = 14

    __velocity: Final = 0.1

    def __init__(self, fill):
        self.center_pos = ((App.WINDOW_WIDTH-Ball.WIDTH) // 2),  ((App.WINDOW_HEIGHT- Ball.HEIGHT)//2)
        
        self.pos = pg.Vector2(self.center_pos)
        self.vel = pg.Vector2(self.__velocity, self.__velocity)

        self.rect = pg.Rect(self.pos, (Ball.WIDTH, Ball.HEIGHT))

        self.surface = pg.Surface((Ball.WIDTH, Ball.HEIGHT))
        self.surface.fill(fill)
        
    def go_left(self):
        self.vel.x = (-1 * self.__velocity)

    def go_right(self):
        self.vel.x = self.__velocity

    def __go_up(self):
        self.vel.y = (-1 * self.__velocity)

    def __go_down(self):
        self.vel.y = self.__velocity

    def stop_ball(self):
        self.vel.x = 0
        self.vel.y = 0
        self.pos = pg.Vector2(self.center_pos)

    def reset(self):
        self.pos = pg.Vector2(self.center_pos)
        self.vel = pg.Vector2(Ball.__velocity, self.__velocity)
        self.rect.update(self.center_pos, (Ball.WIDTH, Ball.HEIGHT))

    def update(self):
        if (self.rect.right >= App.WINDOW_WIDTH):
            self.reset()
            score_m.increment_score(Player.one)
            self.go_right()
        if (self.rect.left <= 0): 
            self.reset()
            score_m.increment_score(Player.two)
            self.go_left()
        if (self.rect.top <= 0):
            self.__go_down()
        if (self.rect.bottom >= App.WINDOW_HEIGHT):
            self.__go_up()

        self.pos.x += self.vel.x 
        self.pos.y += self.vel.y

        self.rect.update(self.pos, (Ball.WIDTH, Ball.HEIGHT))

    def draw(self, screen):
        screen.blit(self.surface, self.rect)

class EventManager:

    class State(IntEnum):
        on, off = 1, 0

    def __init__(self):
        self.buffer: list[int] = [0] * 4

    def __repr__(self):
        return "[ K_UP({}), K_DW({}), K_w({}), K_s({}) ]".format(self.buffer[0], 
                self.buffer[1], 
                self.buffer[2], self.buffer[3])

    def reset(self):
        self.buffer = [0] * 4
    
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
        self.__middle_y_position = ((App.WINDOW_HEIGHT - Paddle.HEIGHT)//2)

        self.pos = pg.Vector2(x, self.__middle_y_position)
        self.vel = pg.Vector2(0, 15)

        # set the initial positon of the paddle
        self.rect = pg.Rect(self.pos, (Paddle.WIDTH, Paddle.HEIGHT))

        self.surface = pg.Surface((Paddle.WIDTH, Paddle.HEIGHT))
        self.surface.fill(fill)
    
    def _colliding_with_screen(self):
        # TODO: Instead of using Window dimensions, use game.screen instead with 'get_rect()'
        if (self.rect.top <= 0):
            self.pos.y = 1
        if (self.rect.bottom >= App.WINDOW_HEIGHT):
            self.pos.y = (App.WINDOW_HEIGHT - Paddle.HEIGHT)

    def reset(self):
        self.pos.y = self.__middle_y_position

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


class App:
    
    WINDOW_WIDTH:  Final = 640
    WINDOW_HEIGHT: Final = 480

    def __init__(self):
           

        self.menu = MenuScreen()

        pg.display.set_caption("Pong")

        self.screen = pg.display.set_mode((App.WINDOW_WIDTH, App.WINDOW_HEIGHT))

        self.pong_ball    = Ball(pg.Color("white"))
        self.left_paddle  = Paddle(MARGIN, 0, pg.Color("white"))
        self.right_paddle = Paddle((App.WINDOW_WIDTH-Paddle.WIDTH)-MARGIN, 0, pg.Color("white"))

        self.event_m = EventManager()
        
        self.show_menu = 1

        self.__running = True

        self.run()

    def __reset_game(self):
        score_m.reset_score_board()
        self.pong_ball.reset()
        self.event_m.reset()
        self.left_paddle.reset()
        self.right_paddle.reset()

    def __stop_game(self):
        self.pong_ball.stop_ball()
        self.event_m.reset()
    
    def update(self):
        if (not self.show_menu):
            self.left_paddle.update()
            self.right_paddle.update()
            self.pong_ball.update()

    def draw(self):
        self.screen.fill(pg.Color("black"))
        
        if (self.show_menu):
            self.menu.show(self.screen)
        
        if (not self.show_menu):
            self.left_paddle.draw(self.screen)
            self.pong_ball.draw(self.screen)
            self.right_paddle.draw(self.screen)

            left_score  = fonts["game"]["score"].render(str(score_m.score_board[0]), True, pg.Color("white"))
            right_score = fonts["game"]["score"].render(str(score_m.score_board[1]), True, pg.Color("white"))
            dash        = fonts["game"]["score"].render("-", True, pg.Color("white"))

            self.screen.blit(left_score, pg.Rect(( 
                (App.WINDOW_WIDTH // 2) - 48 - 12, 10), 
                (left_score.get_width(), left_score.get_height())))
            self.screen.blit(right_score, pg.Rect(( 
                (App.WINDOW_WIDTH // 2) - 48 + 86, 10), 
                (right_score.get_width(), right_score.get_height())))
            self.screen.blit(dash, pg.Rect(( 
                (App.WINDOW_WIDTH // 2) - 10, 10), 
                (right_score.get_width(), right_score.get_height())))

            if (score_m.is_winner()):
                match (score_m.get_winner()):
                    case Player.one:
                        winner = fonts["game"]["score"].render("YOU WIN!", True, pg.Color("white"))
                        loser = fonts["game"]["score"].render("YOU LOSE!", True, pg.Color("white"))

                        self.screen.blit(winner, pg.Rect(( 
                            (App.WINDOW_WIDTH // 4) - 40, (App.WINDOW_HEIGHT // 2) - loser.get_height()), 
                            (winner.get_width(), winner.get_height())))

                        self.screen.blit(loser, pg.Rect(( 
                            (App.WINDOW_WIDTH - loser.get_width()) - 100, (App.WINDOW_HEIGHT // 2) - loser.get_height() ), 
                            (loser.get_width(), loser.get_height())))
                    case Player.two:
                        winner = fonts["game"]["score"].render("YOU WIN!", True, pg.Color("white"))
                        loser = fonts["game"]["score"].render("YOU LOSE!", True, pg.Color("white"))

                        self.screen.blit(winner, pg.Rect(( 
                            (App.WINDOW_WIDTH - winner.get_width()) - 100, (App.WINDOW_HEIGHT // 2) - winner.get_height() ), 
                            (winner.get_width(), winner.get_height())))

                        self.screen.blit(loser, pg.Rect(( 
                            (App.WINDOW_WIDTH // 4) - 80, (App.WINDOW_HEIGHT // 2) - loser.get_height()), 
                            (loser.get_width(), winner.get_height())))
                 
                reset = fonts["game"]["reset"].render("press r to reset".upper(), True, pg.Color("white"))
                self.screen.blit(reset, pg.Rect(( 
                    (App.WINDOW_WIDTH // 2) - 180, (App.WINDOW_HEIGHT -10) - reset.get_height()), 
                    (reset.get_width(), reset.get_height())))

                self.__stop_game()

        pg.display.flip()

    def run(self):
        while self.__running:
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
                        if (event.key == pg.K_RETURN):
                            self.show_menu = 0
                        if (event.key == pg.K_r):
                            self.__reset_game()
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
                sounds["collision"]["paddle"].play()
                self.pong_ball.go_right()

            if (self.pong_ball.rect.colliderect(self.right_paddle.rect)):
                sounds["collision"]["paddle"].play()
                self.pong_ball.go_left()

            self.update()

            self.draw()

def main():
    App()

if __name__ == "__main__":
    main()
