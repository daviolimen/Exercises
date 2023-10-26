def removeSmallestM(arr, N, M):
    A = []
    for i in range(N):
        A.append([arr[i], i])
    A = sorted(A)
    B = []
    for i in range(M, N):
        B.append([A[i][1], A[i][0]])
    B = sorted(B)
    result = [b[1] for b in B]
    return result

def main():
    n, d = map(int, input().split())
    while (n != 0):
        arr = [c for c in input()]
        result = removeSmallestM(arr, n, d)
        print(''.join(result))
        n, d = map(int, input().split())

if __name__ == '__main__':
    main()