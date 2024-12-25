#!/bin/python3

# https://www.hackerrank.com/challenges/big-sorting/problem

import os

def bigSorting(unsorted):
    unsorted.sort(key=lambda v: (len(v), v))

    return unsorted

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    unsorted = []

    for _ in range(n):
        unsorted_item = input()
        unsorted.append(unsorted_item)

    result = bigSorting(unsorted)

    fptr.write('\n'.join(result))
    fptr.write('\n')

    fptr.close()
