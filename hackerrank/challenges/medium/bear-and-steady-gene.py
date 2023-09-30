#!/bin/python3

# https://www.hackerrank.com/challenges/bear-and-steady-gene/problem

import math
import os
import random
import re
import sys

def steadyGene(gene):
    count = [0, 0, 0, 0]
    ngene = [0] * len(gene)
    
    for i in range(len(gene)):
        if gene[i] == 'A':
            c = 0
        elif gene[i] == 'C':
            c = 1
        elif gene[i] == 'G':
            c = 2
        else:
            c = 3

        ngene[i] = c
        count[c] += 1

    if all(x == len(ngene) / 4 for x in count):
        return 0

    left = 0
    result = len(ngene)

    for i in range(len(ngene)):
        count[ngene[i]] -= 1

        while all(c <= len(ngene) / 4 for c in count) and left < i:
            result = min(result, i - left + 1)
            count[ngene[left]] += 1
            left += 1

    return result

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    gene = input()

    result = steadyGene(gene)

    fptr.write(str(result) + '\n')

    fptr.close()
