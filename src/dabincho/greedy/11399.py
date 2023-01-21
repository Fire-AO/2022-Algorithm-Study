#ATM
people = int(input())
value = list(map(int, input().split()))

def leastTIME(number, time):
    '''
    필요한 시간의 최소 합은 앞에서부터 누적된다.
    -> 앞쪽에 적은 시간의 사람, 뒤쪽에 많은 시간의 사람을 배치해서 누적되는 시간을 최소화한다.
    '''
    time.sort()
    for i in range(1, number):
        time[i] = time[i-1] + time[i]
    
    print(sum(time))

leastTIME(people, value)