#!/bin/python3

# https://www.hackerrank.com/challenges/queens-attack-2/problem

import os
from itertools import cycle


def nor(coord, n):
    return (n - coord[0], coord[1] - 1)


def queens_attack(n, r_q, c_q, obstacles):
    y, x = nor((r_q, c_q), n)
    free_cells = [y, min(y, n - x - 1), n - x - 1, min(n - y - 1, n - x - 1), n - y - 1, min(n - y - 1, x), x, min(y, x)]

    for col, row in map(nor, obstacles, cycle([n])):
        if row == x:
            if col < y:
                free_cells[0] = min(free_cells[0], y - col - 1)
            else:
                free_cells[4] = min(free_cells[4], col - y - 1)
        elif col == y:
            if row > x:
                free_cells[2] = min(free_cells[2], row - x - 1)
            else:
                free_cells[6] = min(free_cells[6], x - row - 1)
        elif abs(row - x) == abs(col - y):
            if row > x:
                if col < y:
                    free_cells[1] = min(free_cells[1], row - x - 1)
                else:
                    free_cells[3] = min(free_cells[3], row - x - 1)
            else:
                if col < y:
                    free_cells[7] = min(free_cells[7], x - row - 1)
                else:
                    free_cells[5] = min(free_cells[5], x - row - 1)

    return sum(free_cells)


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    k = int(first_multiple_input[1])

    second_multiple_input = input().rstrip().split()

    r_q = int(second_multiple_input[0])

    c_q = int(second_multiple_input[1])

    obstacles = []

    for _ in range(k):
        obstacles.append(list(map(int, input().rstrip().split())))

    result = queens_attack(n, r_q, c_q, obstacles)

    fptr.write(str(result) + '\n')

    fptr.close()
