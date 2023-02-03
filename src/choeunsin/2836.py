#수상 택시
#상근이와 같은 방향으로 가는 승객은 고려할 필요X
#반대 방향으로 가는 사람들 중 승객끼리 겹치는 거리를 제거한 거리와, 그 거리만큼 방향을 반대로 돌아가는 값을 더한다.
#마지막으로 상근이 출발~최종 목적지 거리 더하면 된다.
import sys

N, M = map(int, sys.stdin.readline().split())   #손님의 수와 상근의 최종 목적지 거리 입력받기
data = [list(map(int, sys.stdin.readline().split())) for _ in range(N)] #승객들의 출발지/도착지 입력받기

go_back = []    #반대 방향으로 가는 승객들을 저장할 배열

for i in range(N):
    if data[i][0] > data[i][1]:
        go_back.append([data[i][1], data[i][0]])    #반대방향으로 가는 승객들을 출발지/도착지를 반대로 해서 정방향으로 저장

go_back.sort()  #출발지를 기준 오름차순 정렬

#2170의 선긋기와 동일한 go_back의 중복 제거 거리 구하기
line = go_back[0]
count = line[1] - line[0]

for i in range(1, len(go_back)):
    if go_back[i][0] <= line[1]:
        if line[1] < go_back[i][1]:
            count += go_back[i][1] - line[1]
            line[1] = go_back[i][1]
        else :
            continue
    else:
        line = go_back[i]
        count += line[1] - line[0]

#반대방향으로 가는 거리 count + 되돌아가는 거리 count + 상근이가 정방향으로 가야할 거리 M = 최솟값
print(2 * count + M)