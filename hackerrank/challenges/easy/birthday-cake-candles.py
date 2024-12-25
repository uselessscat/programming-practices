#!/bin/python3

# https://www.hackerrank.com/challenges/birthday-cake-candles/problem

import math
import os
import random
import re
import sys

def birthdayCakeCandles(ar):
    count = 0
    tallest = 0

    for a in ar:
        if a > tallest:
            tallest = a
            count = 1
        elif a == tallest:
            count += 1

    return count

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    ar_count = int(input())

    ar = list(map(int, input().rstrip().split()))

    result = birthdayCakeCandles(ar)

    fptr.write(str(result) + '\n')

    fptr.close()
