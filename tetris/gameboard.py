import collections

Location = collections.namedtuple('Location', 'row column')
Shape = collections.namedtuple('Shape', 'width height')


class GameBoard:
  """Gameboard class has the required methods and atributes to play a Block Puzzle Game. It's relevant to know that all
  methods work with a tidy list of lists and reverse its rows just when printing it. By doing this, token treatment is
  much easier. 1x1 block is considered by default in case the size isn't specified."""

  def __init__(self, shape):
    """Constructor of the GameBoard class that declares the atribute Board, in where tokens will be added and removed.
    As we have a list of booleans, to check if a location is empty we can just look over the Board. Two lists are also
    declared to gain execution speed in following methods. They store the number of squares taken per row and column at
    each time. Precondition: shape.width && shape.height > 0"""
    self._shape = shape
    self._Board = [[False] * shape.width for i in range (shape.height)]
    self._sq_per_column = [0] * shape.width
    self._sq_per_row = [0] * shape.height

  def get_shape(self):
    "Funciton that returns a tuple containing Board sizes. -Complexity = O(1)"""
    return self._shape

  def is_empty(self, location, figure = Shape (1, 1)):
    """Boolean method that evaluates to True in case all positions in where a figure want to be located, are not occupied.
    -Complexity = O(figure.height x figure.width)"""
    lr, lc = location.row, location.column
    for i in range (lr, lr + figure.height):
      for j in range (lc, lc + figure.width):
        if self._Board[i][j]:
          return False
    return True #is empty

  def is_full(self, location, figure = Shape (1, 1)):
    """Opposite implementation of is_empty method, but this time returning True in case all positions are taken.
    -Complexity = O(figure.height x figure.width)"""
    lr, lc = location.row, location.column
    for i in range (lr, lr + figure.height):
      for j in range (lc, lc + figure.width):
        if not self._Board[i][j]:
          return False
    return True #is full

  def __legal_bounds(self, location, figure):
    """Given the location and sizes of a figure, this private method checks if their bounds are inside the Board and don't
    access to none existing positions. No returns are done as is only used to report illegallities. -Complexity = O(1)"""
    Board_width, Board_height = self.get_shape()
    lr, lc = location.row, location.column
    assert lr < Board_height or lc < Board_width, "Lower-left corner is out of bounds"
    assert lr + figure.height <= Board_height and lc + figure.width <= Board_width, "Upper-right corner is out of bounds"

  def __board_modifier(self, location, figure, insert):
    """Private method that changes the Board appareance when called from put and remove methods. To distinguish between
    them, a boolean is given. If we want to insert a token it evaluates to True, and to False conversely.
    -Complexity = O(figure.height x figure.width)"""
    lr, lc = location.row, location.column
    for i in range (lr, lr + figure.height):
      for j in range (lc, lc + figure.width):
        self._Board[i][j] = insert
        x = 1 #Value we have to add (put method) or substract (remove method) to the vectors declared in the constructor.
        if not insert:
          x = - 1
        self._sq_per_row [i] += x
        self._sq_per_column [j] += x
    return self

  def put(self, location, figure = Shape (1, 1)):
    """Put mehod, is responsible for adding blocks to the Board. It calls three external methods. Firstly it verifies if
    bounds are inside the Board, and then if the spot is free. Finally if no illegallities are detected, put method calls
    the board modifier to turn the corresponding positions into True. -Complexity = O(__legal_bounds) + O(is_empty) +
    + O(__board_modifier) = O(1) + 2 * O(figure.height x figure.width) = O(figure.height x figure.width)"""
    self.__legal_bounds(location, figure) #check if the figure could fit
    assert self.is_empty(location, figure), "The square cannot be put, a position is already occupied"
    self.__board_modifier(location, figure, True) #Boolean 'inside' is True as we want to put tokens
    return self

  def remove(self, location, figure = Shape (1, 1)):
    """Remove mehod's structure is the same as in the put, as well as its complexity. Then main difference is that it
    checks if the spot is occupied to be able to remove it. -Complexity = O(figure.height x figure.width)"""
    self.__legal_bounds(location, figure) #check if the figure could have been put
    assert self.is_full(location, figure), "The square cannot be removed, a position is empty"
    self.__board_modifier(location, figure, False) #Boolean 'inside' is False as we want to remove tokens
    return self

  def clear_rows(self, row):
    """This implementation erases all the elements of the rows that are contained in the given list.
    -Complexity = O(len(row) x width) = O(height x widht)""" #worst case
    Board_width, Board_height = self.get_shape()
    for i in row:
      for j in range (Board_width):
        if self._Board [i][j]: #Position i-j has to be occupied to remove tokens
            self._sq_per_column [j] -= 1 #we substract a token from the j-th column
            self._Board [i][j] = False
      self._sq_per_row [i] = 0 #no tokens remain in the row, we remove them from the list
    return self

  def clear_columns(self, col):
    """As well as the previous method, we erase all the elements of the columns that are contained in the list.
    -Complexity = O(len(col) x height) = O(widht x height)""" #worst case
    Board_width, Board_height = self.get_shape()
    for j in col:
      for i in range(Board_height):
        if self._Board [i][j]: #Position i-j has to be occupied to remove tokens
            self._sq_per_row [i] -= 1 #we substract a token from the i-th row
            self._Board [i][j] = False
      self._sq_per_column [j] = 0 #no tokens remain in the column, we remove them from the list
    return self

  def full_rows(self):
    """It returns a list containing the completed rows. To do it we just look over the list declared on the constructor
    to verify if any row is full. -Complexity = O(height)"""
    Board_width, Board_height = self.get_shape()
    rows = []
    for i in range (Board_height): #len(sq_per_row) == Board_width
      if self._sq_per_row [i] == Board_width: #if this happens the row is full
        rows.append(i)
    return rows

  def full_columns(self):
    """Similar method as full_rows but returning the list of completed columns. -Complexity = O(widht)"""
    Board_width, Board_height = self.get_shape()
    columns = []
    for j in range (Board_width): #len(sq_per_column) == Board_width
      if self._sq_per_column [j] == Board_height: #if this happens the column is full
        columns.append(j)
    return columns

  def row_counters(self):
    """It returns the list with the number of tokens per row. -Complexity = O(1)"""
    return self._sq_per_row

  def column_counters(self):
    """-Complexity = O(1)"""
    return self._sq_per_column

  def __str__(self):
    """Method that returns the grafical representation of the Board in a string. Row 0 is the lower one. Columns are
    written from left to right. -Complexity = O(height x width)"""
    s = ""
    Board_width, Board_height = self.get_shape()
    for i in reversed(range(Board_height)): #loop from (Board_height --> 0]
      for j in range (Board_width):
        if self._Board[i][j]:
          s += '\u2b1b' #black tokens
        else:
          s += '\u2b1c' #white tokens
      s += "\n" #line break
    return s

  def __repr__(self):
    """Method that returns a string with Board sizes and the positions with tokens. -Complexity = O(height x width)"""
    Board_width, Board_height = self.get_shape()
    s = str(Board_width) + "x" + str(Board_height) + " board: {"
    for i in range(Board_height):
      for j in range (Board_width):
        if self._Board[i][j]:
          if s[-1] != '{': #check if the string contains positions yet, s[-1] == last element of s
            s += ", "
          s = s + "(" + str(i) + ", " + str(j) + ")"
    return s + "}"
