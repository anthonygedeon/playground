import pygame as pg

import abc
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
