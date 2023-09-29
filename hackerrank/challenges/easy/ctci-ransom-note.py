#!/bin/python3

# https://www.hackerrank.com/challenges/ctci-ransom-note/problem

import math
import os
import random
import re
import sys

# Complete the checkMagazine function below.
def checkMagazine(magazine, note):
    mwords = dict()

    for e in magazine:
        mwords[e] = mwords.get(e, 0) + 1

    for e in note:
        c = mwords.get(e, 0)
        if(c > 0):
            mwords[e] = c - 1
        else:
            return 'No'

    return 'Yes'


if __name__ == '__main__':
    mn = input().split()

    m = int(mn[0])

    n = int(mn[1])

    magazine = input().rstrip().split()

    note = input().rstrip().split()

    result = checkMagazine(magazine, note)

    print(result)
