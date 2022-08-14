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
        pass

    def setup(self):
        """"""
        pass

    def update(self):
        """"""
        pass
    
    def draw(self):
        """"""
        pass

if __name__ == "__main__":
    App()
    
    pg.init()
    
    size = width, height = 680, 420

    screen = pg.display.set_mode(size)

    pg.display.set_caption("Snake")

    while True:
        for event in pg.event.get():
            match (event.type):
                case pg.QUIT:
                    sys.exit()




























