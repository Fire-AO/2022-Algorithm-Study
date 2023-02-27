# 소수의 연속합
def isPrimeNumber(n):
    # 에라토스테네스의 체 초기화: n개 요소에 True 설정
    check = [True] * n

    # n의 제곱근
    m = int(n ** 0.5)
    for i in range(2, m + 1):
        # i가 소수일 때
        if check[i] == True:
            # i이후 i의 배수들을 False로 변환(소수가 아님)
            for j in range(i + i, n, i):
                check[j] = False

    # 소수 목록 리스트로 리턴
    return [i for i in range(2, n) if check[i] == True]

N = int(input())
data = isPrimeNumber(N+1)   #2부터 N까지 소수로 이루어진 리스트

count = 0   # 합이 M이 되는 경우의 수
fir = 0     # 첫번째 포인터
sec = 0     # 두번째 포인터
now = 0     # 현재 합

while (sec <= len(data)):
    #첫번째부터 두번째까지 data의 합 저장
    now = sum(data[fir:sec])
    # 합이 목표값보다 크면 첫번째 포인터의 기준에서는 더 구할 값이 없음
    # 첫번째 포인터 한 칸 이동
    if now > N:
        fir += 1
    # 합이 목표값보다 크지 않으면 두번째 포인터 한칸 이동
    else:
        # 합이 목표값과 같으면 count++
        if now == N:
            count += 1
        sec += 1

print(count)