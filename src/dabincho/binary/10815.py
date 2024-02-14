N = int(input())
sample_num = list(map(int, input().split()))
M = int(input())
sample_right = list(map(int, input().split()))

def binary_search(arr, n, start, end):
    while start <= end:
        mid = (start + end) // 2
        
        if arr[mid] == n:
            return mid
        elif arr[mid] > n:
            end = mid - 1
        else:
            start = mid + 1
    return -1

def find_num(number, right):
    number.sort()
    end = N - 1

    for i in range(M):
        ind = binary_search(number, right[i], 0, end)
        if ind == -1:
            right[i] = 0
        else:
            right[i] = 1

    for i in right:
        print(i, end = ' ')

find_num(sample_num, sample_right)