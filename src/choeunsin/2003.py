# 수들의 합2
N, M = map(int, input().split())
data = [*map(int, input().split())]

count = 0   # 합이 M이 되는 경우의 수
fir = 0     # 첫번째 포인터
sec = 0     # 두번째 포인터
now = 0     # 현재 합

while (sec <= N):
    #첫번째부터 두번째까지 data의 합 저장
    now = sum(data[fir:sec])
    # 합이 M보다 크면 첫번째 포인터의 기준에서는 더 구할 값이 없음
    # 첫번째 포인터 한 칸 이동
    if now > M:
        fir += 1
    # 합이 M보다 크지 않으면 두번째 포인터 한칸 이동
    else:
        # 합이 M과 같으면 count++
        if now == M:
            count += 1
        sec += 1

print(count)


