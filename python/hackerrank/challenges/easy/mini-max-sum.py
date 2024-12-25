#!/bin/python3

# https://www.hackerrank.com/challenges/mini-max-sum/problem

import math
import os
import random
import re
import sys

def miniMaxSum(arr):
    sum_ = 0
    min_ = max_ = arr[0]

    for v in arr:
        sum_ += v

        if v < min_: min_ = v
        if v > max_: max_ = v

    print(f"{sum_ - max_} {sum_ - min_}")

if __name__ == '__main__':

    arr = list(map(int, input().rstrip().split()))

    miniMaxSum(arr)
