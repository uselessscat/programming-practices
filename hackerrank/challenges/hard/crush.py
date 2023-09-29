#!/bin/python3

# https://www.hackerrank.com/challenges/crush/problem

import math
import os
import random
import re
import sys

def arrayManipulation(n, queries):
    array = [0] * (n + 1)
    m = 0
    t = 0

    for a, b, k in queries:
        array[a - 1] += k
        array[b] -= k

    for v in array:
        t += v

        if t > m:
            m = t
        
    return m

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    m = int(first_multiple_input[1])

    queries = []

    for _ in range(m):
        queries.append(list(map(int, input().rstrip().split())))

    result = arrayManipulation(n, queries)

    fptr.write(str(result) + '\n')

    fptr.close()
