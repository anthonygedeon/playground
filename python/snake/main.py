import pygame as pg

import abc, sys
from enum import Enum

class ScreenInterface(abc.ABC):
    """""" 
    @abc.abstractmethod
    def show(self):
        """"""

class Grid:
    """"""
    def __init__(self):
        pass

class Snake:
    """"""
    def __init__(self):
        pass

class Food:
    """"""
    def __init__(self):
        pass

class EventController:
    """"""
    
    def listen(self):
        """"""
        for event in pg.event.get():
            match (event.type):
                case pg.QUIT:
                    sys.exit()
                case pg.KEYDOWN:
                    pass
                case pg.KEYUP:
                    pass


class StartMenuScreen(ScreenInterface):
    """"""
    def show(self):
        pass

class OptionsScreen(ScreenInterface):
    """"""
    def show(self):
        pass

class GamePlayScreen(ScreenInterface):
    """"""
    def show(self):
        pass

class GameOverScreen(ScreenInterface):
    """"""
    def show(self):
        pass

class Game:
    """"""
    def reset(self):
        pass

class App:
    """""" 
    def __init__(self):
        self.setup()
        
        self.size = 680, 420
        self.screen = pg.display_set_mode(self.size)

    def setup(self):
        """"""
        pg.init()
        pg.mixer.init() 
        pg.font.init()

        pg.display.set_caption("Snake")


    def update(self):
        """"""
        pass
    
    def draw(self):
        """"""
        pass

if __name__ == "__main__":
    App()

    while True:



























