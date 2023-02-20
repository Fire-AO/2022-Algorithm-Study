# BOJ 11501 주식 실버2
#https://www.acmicpc.net/problem/11501

import sys
t = int(input())

for i in range(t):
    day = int(input())
    cost = []
    cost = list(map(int, sys.stdin.readline().split()))

    cost.reverse()

    m = cost[0]

    rev = 0
    for c in cost:
        if(c > m):
            m = c
        else:
            rev += (m-c)

    print(rev)