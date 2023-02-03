#선 긋기
import sys

N = int(input())     #선을 그은 횟수
data = [list(map(int, sys.stdin.readline().split())) for _ in range(N)] #선의 시작점, 끝점

data.sort()          #시작점 순서대로 정렬

line = data[0]      #그은 선의 시작점, 끝점은 첫번째 배열로
count = line[1] - line[0]   #그은 선의 길이는 첫번째 배열의 길이로

for i in range(1, N):
    if data[i][0] <= line[1]:   #다음 배열의 시작점이 그은 선의 범위 안에 있을 때
        if line[1] < data[i][1]:    #다음 배열의 끝점이 그은 선의 범위 밖에 있을 때
            count += data[i][1] - line[1]
            line[1] = data[i][1]
        else :                      #다음 배열의 끝점이 그은 선의 범위 안에 있을 때
            continue
    else:                       #다음 배열이 그은 선과 겹치지 않을 때
        line = data[i]
        count += line[1] - line[0]
print(count)
