#!/bin/python3

# https://www.hackerrank.com/challenges/extra-long-factorials/problem

import math
import os
import random
import re
import sys

from functools import reduce
from operator import mul

def extraLongFactorials(n):
    print(reduce(mul, range(1, n + 1)))

if __name__ == '__main__':
    n = int(input().strip())

    extraLongFactorials(n)
