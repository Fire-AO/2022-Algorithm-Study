# 숫자카드
import sys

N = int(input())
n_data = list(map(int, sys.stdin.readline().rstrip().split()))
M = int(input())
m_data = list(map(int, sys.stdin.readline().rstrip().split()))

# 오름차순 정렬
n_data.sort()

for i in range(M):
    start = 0
    end = len(n_data) - 1

    # 이분탐색을 이용한 값 구하기
    while start < end:
        middle = int((start + end) / 2)
        if n_data[middle] >= m_data[i]:
            end = middle
        else:
            start = middle + 1

    # n_data에 정해진 값이 존재하는지 확인
    if n_data[start] == m_data[i]:
        m_data[i] = 1
    else:
        m_data[i] = 0

print(*m_data)