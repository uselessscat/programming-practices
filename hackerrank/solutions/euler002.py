#!/bin/python3

# https://www.hackerrank.com/contests/projecteuler/challenges/euler002/problem
import sys

t = int(input().strip())

for _ in range(t):
    n = int(input().strip())
    
    low, high, total = 1, 1, 0
    
    while True:
        actual = low + high
        
        if actual > n:
            break
            
        if actual & 1 == 0:
            total += actual
            
        low, high = high, actual
    
    print(total)
