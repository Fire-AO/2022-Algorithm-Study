#ATM
import sys
T = int(input())
data = list(map(int, sys.stdin.readline().split()))

#누적된 기다리는 시간이 최소가 되려면 시간이 적게 걸리는 사람부터 해결하면 된다
data.sort()     #오름차순으로 정렬
total = 0       #총 시간 초기화
for i in range(T) :
    total += sum(data[:i+1])    #첫번째 사람부터 마지막 사람까지 기다린 시간 각각 sum()을 이용해 더해서 저장
print(total)