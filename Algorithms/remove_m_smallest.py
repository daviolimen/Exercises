def removeSmallestM(arr, N, M):
    A = []
    for i in range(N):
        A.append([arr[i], i])
    A = sorted(A)
    B = []
    for i in range(M, N):
        B.append([A[i][1], A[i][0]])
    B = sorted(B)
    for i in range(len(B)):
        print(B[i][1], end = ' ')

def main():
    M = 3
    arr = [1, 2, 3, 1, 2, 3]
    N = 6
    removeSmallestM(arr, N, M)

if __name__ == '__main__':
    main()