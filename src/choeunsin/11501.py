#주식
import sys
T = int(input())
#테스트 수만큼 반복문으로 입력받기
for _ in range(T) :
    N = int(input())
    data = list(map(int, sys.stdin.readline().split()))

    present = 0     #현재 가진 돈 초기화

    while 1 == 1 :  #무한반복
        if len(data) <= 1 : #자르고 남은 리스트 길이가  1 이하일 때는 종료
            break

        #max_index에 리스트의 최댓값 index 저장
        max_index = data.index(max(data))

        #남은 리스트 중 최댓값의 index가 첫번째이면서 리스트가 내림차순일 때 종료
        #앞으로 현재 index보다 적을 일만 남으면 주식을 더 살 필요가 없기 때문
        if max_index == 0 and data == sorted(data, reverse=True):
            break

        #현재 가진 돈에 -(max_index전까지 산 주식 값들) +(max_index까지 샀던 주식 수*최댓값)
        present -= sum(data[:max_index], (-1) * max_index * data[max_index])

        #리스트를 max_index 뒷부분만 남겨두고 자르기
        data = data[max_index + 1:]

    #현재 가진 돈 출력
    print(present)