# BOJ 11399 ATM 실버4
#https://www.acmicpc.net/problem/11399

n = int(input())
t = []
t = list(map(int, input().split()))
t.sort()
sum = 0
wait = 0
for time in t:
    sum += wait + time
    wait += time
print(sum)
