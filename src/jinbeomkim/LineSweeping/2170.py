# BOJ 2170 선긋기 골드5
#https://www.acmicpc.net/problem/2170

n = int(input())
p = [list(map(int, input().split())) for _ in range(n)]

p.sort()

# 기준값을 최솟값으로 초기화
end = -10**10
# 길이는 0으로 초기화
res = 0
for l in p:
    # 포함관계인 경우
    if l[0] <= end < l[1]:
        res += l[1] - end
    # 포함관계가 아닌경우
    elif l[0] > end:
        res += l[1] - l[0]
    # end 갱신
    if l[1] > end:
        end = l[1]

print(res)