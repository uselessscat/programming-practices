#!/bin/python3

# https://www.hackerrank.com/challenges/morgan-and-a-string/problem

import math
import os
import random
import re
import sys

def morganAndString(a, b):
    i = j = 0
    a += "z"
    b += "z"
    result = []
    
    while i + j < len(a) + len(b) - 2:
        if i < len(a) -1 and j < len(b) - 1:
            if a[i:] <= b[j:]:
                result.append(a[i])

                i += 1
            else:
                result.append(b[j])

                j += 1
        else:
            if i < len(a) - 1:
                result.append(a[i])

                i += 1
            else:
                result.append(b[j])

                j += 1


    return "".join(result)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        a = input()

        b = input()

        result = morganAndString(a, b)

        fptr.write(result + '\n')

    fptr.close()
