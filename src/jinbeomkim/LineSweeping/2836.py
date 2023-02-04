# BOJ 2836 수상택시 골드3
# https://www.acmicpc.net/problem/2836

n, m = map(int, input().split())

p = [list(map(int, input().split())) for _ in range(n)]

p.sort()

# 역순 찾기
rp = []
for l in p:
    if l[0] > l[1]:
        rp.append((l[1], l[0]))

rp.sort()

# 값 초기화
res = m
end = 0
rev = 0
for rl in rp:
    # 포함 관계
    if end > rl[0]:
        if end < rl[1]:
            rev += rl[1] - end
    # 비포함 관계
    else:
        rev += rl[1] - rl[0]
    # 기준값 갱신
    if end < rl[1]:
        end = rl[1]

print(res + rev * 2)
