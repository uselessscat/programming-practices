#!/bin/python3

# https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem

import math
import os
import random
import re
import sys

# Complete the jumpingOnClouds function below.
def jumpingOnClouds(c):
    if (len(c) < 2):
        return 1

    steps = 0
    acc = 0
    for e in c:
        if (e == 0):
            acc += 1

        if (e == 1):
            steps += acc // 2 + 1
            acc = 0

    if (acc != 0):
        steps += acc // 2

    return steps


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    c = list(map(int, input().rstrip().split()))

    result = jumpingOnClouds(c)

    fptr.write(str(result) + '\n')

    fptr.close()
