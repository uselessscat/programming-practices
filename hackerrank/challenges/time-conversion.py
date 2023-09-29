#!/bin/python3

# https://www.hackerrank.com/challenges/one-week-preparation-kit-time-conversion/problem

import math
import os
import random
import re
import sys


def timeConversion(s):
    hour, rest, am_pm = int(s[0:2]) % 12, s[2:8], s[8:]

    if am_pm == 'PM':
        hour += 12

    return f"{hour:02d}{rest}"


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = timeConversion(s)

    fptr.write(result + '\n')

    fptr.close()
