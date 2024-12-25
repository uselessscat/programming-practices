#!/bin/python3
# https://www.hackerrank.com/challenges/staircase/problem

import math
import os
import random
import re
import sys

def staircase(n):
    for i in range(n):
        spaces = ' ' * (n - (i + 1))
        hashes = '#' * (i + 1)
        print(spaces + hashes)

if __name__ == '__main__':
    n = int(input().strip())

    staircase(n)
