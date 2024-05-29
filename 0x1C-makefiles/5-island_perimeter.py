#!/usr/bin/python3
"""module to define island_perimeter"""


def island_perimeter(grid):
    """ calaculates the grid perimeter
    Args:
        grid(matrix): represents island to calsulate perimeter
    """
    perimeter = 0
    directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 1:
                for dx, dy in directions:
                    x, y = i + dx, j + dy
                    if (x < 0 or x >= len(grid)
                            or y < 0 or y >= len(grid[0])
                            or grid[x][y] == 0):
                        perimeter += 1

    return perimeter
