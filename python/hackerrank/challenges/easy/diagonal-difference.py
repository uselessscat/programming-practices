#!/bin/python3

# https://www.hackerrank.com/challenges/diagonal-difference/problem

import math
import os
import random
import re
import sys


def diagonalDifference(arr):
    return abs(
        sum([arr[i][i] - arr[len(arr) - i - 1][i] for i in range(len(arr))])
    )


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = []

    for _ in range(n):
        arr.append(list(map(int, input().rstrip().split())))

    result = diagonalDifference(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
