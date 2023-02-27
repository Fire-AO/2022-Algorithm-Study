# 차집합
import sys

A, B = map(int, sys.stdin.readline().split())
a_data = list(map(int, sys.stdin.readline().rstrip().split()))
b_data = list(map(int, sys.stdin.readline().rstrip().split()))

a_data.sort()
b_data.sort()
answer_list = []

for i in range(A):
    start = 0
    end = len(b_data) - 1

    # 이분탐색을 이용한 값 구하기
    while start < end:
        middle = int((start + end) / 2)
        if b_data[middle] >= a_data[i]:
            end = middle
        else:
            start = middle + 1

    # a_data에 정해진 값이 존재하지 않으면 answer_list에 추가
    if b_data[start] != a_data[i]:
        answer_list.append(a_data[i])

print(len(answer_list))
if len(answer_list) > 0:
    print(*answer_list)