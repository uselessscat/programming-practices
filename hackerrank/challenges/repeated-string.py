#!/bin/python3

# https://www.hackerrank.com/challenges/repeated-string/problem

import math
import os
import random
import re
import sys

# Complete the repeatedString function below.
def repeatedString(s, n):
    aMod = n % len(s)

    aCount = 0
    aCountMod = s[:aMod].count('a')

    if(n // len(s) > 0):
        aCount = (s[aMod:].count('a') + aCountMod) * (n // len(s))

    return aCount + aCountMod


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    n = int(input())

    result = repeatedString(s, n)

    fptr.write(str(result) + '\n')

    fptr.close()
