#강의실 배정
"""
문제 : https://www.acmicpc.net/problem/11000
풀이 : https://www.notion.so/11000-3907e49c428e43a9a00c72e0f7649566
+ 백준에서는 런타임 에러가 뜨지만, 여러가지 테스트 했을 땐 정답이 나와서 문제점 피드백 부탁드립니다
"""
import sys
T = int(input())
#테스트 수만큼 반복문으로 입력받기
data = [list(map(int, sys.stdin.readline().split())) for _ in range(T)]
data.sort() #수업 시작 시간 정렬
count = T   #필요한 강의실 수

#비교할 시작 시간 기준
for i in range(T) :
    if data[i][0] != -1 :   #이미 강의실에 포함된 강좌일 경우 실행X

        #비교당할 끝나는 시간 기준
        for j in range(i+1, T) :
            if data[j][0] != -1 :   #이미 강의실에 포함된 강좌일 경우 실행X

                #j 강의의 시작 시간이 i 강의의 끝나는 시간보다 작거나 같을 때
                if data[i][1] <= data[j][0]:
                    data[i][1] = data[j][1]     #i, j강의 합치기
                    data[j] = [-1, -1]          #j강의 강의실에 포함되었음 표시
                    count -= 1                  #강의실에 포함된 강의는 count 제외

print(count)