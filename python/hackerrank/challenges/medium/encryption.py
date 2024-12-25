#!/bin/python3

# https://www.hackerrank.com/challenges/encryption/problem

import os

from math import ceil, sqrt

def encryption(s):
    s = s.replace(" ", "")
    c = ceil(sqrt(len(s)))

    return " ".join(s[i::c] for i in range(c))

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = encryption(s)

    fptr.write(result + '\n')

    fptr.close()
