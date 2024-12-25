#!/bin/python3
# https://www.hackerrank.com/challenges/compare-the-triplets/problem

import math
import os
import random
import re
import sys


def compare_triplets(a, b):
    result = [0, 0]

    for i in range(len(a)):
        if a[i] == b[i]:
            continue
        result[0 if a[i] > b[i] else 1] += 1

    return result


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    a = list(map(int, input().rstrip().split()))

    b = list(map(int, input().rstrip().split()))

    result = compare_triplets(a, b)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
