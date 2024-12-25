#!/bin/python3

# https://www.hackerrank.com/challenges/2d-array/problem

import math
import os
import random
import re
import sys
from itertools import product
from functools import reduce
from operator import add

#
# Complete the 'hourglassSum' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY arr as parameter.
#

def hourglassSum(arr):
    max_ = -9 * 7

    for y, x in product(range(4), repeat=2):
        if (local := reduce(add, arr[y][x:x + 3] + [arr[y + 1][x + 1]] + arr[y + 2][x:x + 3])) > max_:
            max_ = local

    return max_

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    arr = []

    for _ in range(6):
        arr.append(list(map(int, input().rstrip().split())))

    result = hourglassSum(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
