#!/bin/python3

# https://www.hackerrank.com/challenges/counting-valleys/problem

import math
import os
import random
import re
import sys

#
# Complete the 'countingValleys' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER steps
#  2. STRING path
#
def countingValleys(steps, path):
    level = 0
    valleys = 0
    for op in path:
        c = 1 if op == 'U' else -1

        level += c
        if (level == 0 and c == 1):
            valleys += 1

    return valleys


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    steps = int(input().strip())

    path = input()

    result = countingValleys(steps, path)

    fptr.write(str(result) + '\n')

    fptr.close()
