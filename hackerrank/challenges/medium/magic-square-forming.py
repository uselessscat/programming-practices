#!/bin/python3

# https://www.hackerrank.com/challenges/magic-square-forming/problem

import os

from operator import abs, sub

def forming_magic_square(s):
    squares = (
        [5 + a, 5 - (a + b), 5 + b, 5 - (a - b), 5, 5 + (a - b), 5 - b, 5 + (a + b), 5 - a]
        for a, b in [(1, 3), (3, 1), (1, -3), (3, -1), (-1, 3), (-3, 1), (-1, -3), (-3, -1)]
    )

    return min(sum(map(abs, map(sub, square, s))) for square in squares)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = []

    for _ in range(3):
        s += list(map(int, input().rstrip().split()))

    result = forming_magic_square(s)

    fptr.write(str(result) + '\n')

    fptr.close()
