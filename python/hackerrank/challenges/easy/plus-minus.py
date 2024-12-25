#!/bin/python3
# https://www.hackerrank.com/challenges/plus-minus/problem

import math
import os
import random
import re
import sys

def plusMinus(arr):
    p, z, n, t = 0, 0, 0, len(arr)
    
    for v in arr:
        if v > 0:
            p += 1
        elif v < 0:
            n += 1
        else:
            z += 1

    print(f"{p/t:.6f}\n{n/t:.6f}\n{z/t:.6f}")

if __name__ == '__main__':
    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    plusMinus(arr)
