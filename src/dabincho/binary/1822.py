ab = list(map(int, input().split()))
A = list(map(int, input().split()))
B = list(map(int, input().split()))

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


def minus(a, b):
    a.sort()
    b.sort()
    result = []

    for i in a:
        ind = binary_search(b, i, 0, ab[1]-1)
        if ind == -1:
            result.append(i)
    
    count = len(result)
    print(count)
    if count != 0:
        for n in result:
            print(n, end=' ')

minus(A, B)