from gameboard import *

class MyPlayer:
  """MyPlayer class uses Gameboard methods and is capable of playing the game authomatically. Given a sequence of blocks
  it can find a free place, in case it exists, and put the block in it. If all the tokens of a row or column become
  occupied, they are erased. If the block can't be put, the game stops"""

  def __init__(self, width, height):
    """Constructor of MyPlayer class where a Board is inizialized using the GameBoard class"""
    self._Board = GameBoard(Shape(width, height))

  def is_legal(self, figure = Shape (1, 1)):
    """This method works as a boolean checker that returns True in case all parameters given are from the type required.
    -Complexity = O(1)"""
    Board_width, Board_height = self._Board.get_shape()
    assert type(figure) is Shape
    assert type(figure.height) is int and type(figure.width) is int
    assert figure.height > 0 and figure.width > 0
    return True

  def place_block(self, location, figure = Shape (1, 1)):
    """Place_block calls to other methods, firstly to check if the given location for a block is legal, and then to put
    the block in the spot. In case some rows or columns are full, we erase their elements. -Complexity = O(1) +
    + O(figure.height x figure.width) + O(height) + O(width) + 2 * O(widht x height) = O(widht x height)"""
    self.is_legal(figure)
    self._Board.put(location, figure) #when calling put method, bounds are checked automatically
    rw, cl = self._Board.full_rows(), self._Board.full_columns() #lists that store full rows and columns
    self._Board.clear_rows(rw)
    self._Board.clear_columns(cl)
    return self

  def play(self, figure = Shape (1, 1)):
    """Given a figure, this method returns the location in where the given block can be put, and in case it doesn't fit,
    returns None.
    -Complexity = O(((Board_height - figure.height) * (Board_width - figure.width)) x (figure.height x figure.width))"""
    Board_width, Board_height = self._Board.get_shape()
    for i in range(Board_height - figure.height + 1):
        for j in range(Board_width - figure.width + 1):
            if self._Board.is_empty(Location(i, j), figure): #check if the figure can fit
                return Location(i, j)

  def __str__(self):
    """It returns a string of the Board representation. -Complexity = O(height x width)"""
    return self._Board.__str__()
