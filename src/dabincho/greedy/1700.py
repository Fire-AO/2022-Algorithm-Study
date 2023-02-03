#멀티탭 스케쥴
n = list(map(int, input().split()))
schedule = list(map(int, input().split()))

#리스트와 요소가 주어졌을 경우 리스트 내에서 요소의 첫 번째 인덱스를 반환
def find(sequence, x):
    for i in range(len(sequence)):
        if sequence[i] == x:
            return i
    return -1

def sOFtab(tab_num, schedule_num, schedule):
    #사용할 전자기기의 수가 멀티탭의 구멍 수보다 적거나 같은 경우 계산 필요 x
    s = set(schedule)
    if tab_num >= len(s):
        print(0)
        return
    
    #tab = 현재 멀티탭에 꽂혀있는 전자기기(중복된 전자기기 제외, 빈칸이 없도록 세팅)
    #tab_index = 꽂혀있는 전자기기를 다음에 사용할 순서(더 이상 사용하지 않으면 가장 큰 수 부여)
    count = 0
    tab = [-1 for _ in range(tab_num)]
    for u in range(schedule_num):
        i = schedule[u]
        o = find(tab, -1)
        if o == -1:
            break
        else:
            if i not in tab:
                tab[o] = i
        schedule[u] = -1
        count += 1
    tab_index = [0 for _ in range(tab_num)]
    for i in range(tab_num):
        t = find(schedule, tab[i])
        if t == -1:
            t = max(schedule)
        tab_index[i] = t
    need = 0

    '''
    > 가능한 경우
    1. 이미 꽂혀있는 전자기기를 사용하는 경우
    2. 꽂혀있지 않은 전자기기를 사용하는 경우

    1) out != -1
    콘센트를 빼지 않아도 되므로 해당 전자기기의 다음 사용 순서만 갱신한다.

    2) out == -1
    현재 멀티탭에서 콘센트를 빼야한다.
    : 현재 멀티탭에 꽂혀있는 전자기기 중에서 가장 나중에 사용할 전자기기를 뽑는다.
    : 전자기기를 교체한 후 해당 전자기기의 다음 사용 순서를 갱신한다.
    '''
    for n in range(count, schedule_num):
        p = schedule[n]
        out = find(tab, p)

        if out == -1:
            out = find(tab_index, max(tab_index))
            tab[out] = p
            need += 1
        
        schedule[n] = -1
        change = find(schedule, p)
        if change == -1:
            tab_index[out] = max(schedule)
        else:
            tab_index[out] = change

    print(need)

sOFtab(n[0], n[1], schedule)