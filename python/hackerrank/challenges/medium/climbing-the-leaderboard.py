#!/bin/python3

# https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem

import os

from itertools import accumulate

def climbing_leaderboard(ranked, player):
    ret = []
    positions = list(accumulate([1] + [x != y for x, y in zip(ranked, ranked[1:])]))

    i = len(ranked) - 1
    for p in player:
        while i > 0 and ranked[i] < p:
            i -= 1

        if p < ranked[i]:
            ret.append(positions[i] + 1)
        else:
            ret.append(positions[i])

    return ret


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    ranked_count = int(input().strip())

    ranked = list(map(int, input().rstrip().split()))

    player_count = int(input().strip())

    player = list(map(int, input().rstrip().split()))

    result = climbing_leaderboard(ranked, player)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
