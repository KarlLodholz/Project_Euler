"""
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
How many such routes are there through a 20×20 grid?
"""

import math

GRID_SIZE = 20
#I observed that the number of paths was a combination of (2i)C(i), where i = GRID_SIZE
#nCr = n! / (r! (n-r)!)
# this can be simplified in this situation to: (i*2)! / (i!*i!)
# // removes scientific notation
print( math.factorial(GRID_SIZE*2) // (math.factorial(GRID_SIZE)*(math.factorial(GRID_SIZE))) )