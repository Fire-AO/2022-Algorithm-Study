#주식
test_number = int(input())
test_case = []
for _ in range(test_number):
    day = int(input())
    value = list(map(int, input().split()))
    test_case.append([day, value])

def stock(day, value):
    '''
    1] 주어진 주가가 내림차순으로 되어있는지 확인
    : 이윤을 얻을 수 있는 경우가 존재하지 않음
    - 확인할 필요 x

    2] 내림차순이 아니라면
    > 주어진 주가에서 가장 큰 주가를 선택
        : 가장 큰 주가의 앞쪽 날은 무조건 이윤을 얻을 수 있음.
        : 첫 날부터 가장 큰 주가의 앞 날은 모두 사고 가장 큰 주가의 날에 모두 판다.
    > 찾은 날이 마지막 날이 아니면 찾은 날의 다음 날부터 똑같은 과정을 반복
    > 과정을 반복하며 얻은 이윤을 모두 더한다.
    '''
    test = [i for i in value]
    test.sort(reverse=True)
    result = 0
    if test != value:
        best = max(value)
        for i in range(day):
            now = value[i]
            if now != best:
                result += (best-now)
            else:
                if i != day-1:
                    best = max(value[i+1:])
    print(result)

for now in test_case:
    stock(now[0], now[1])