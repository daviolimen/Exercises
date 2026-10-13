from collections import deque

vr = (1, 0, -1, 0)
vc = (0, 1, 0, -1)

def bfs(matrix, n, f):
    visited, queue = set(), deque([(0, 0)])
    while queue:
        r, c = queue.popleft()
        if (r, c) in visited:
            continue
        visited.add((r, c))
        for i in range(4):
            a = r + vr[i]
            b = c + vc[i]
            if (0 <= a < n) and (0 <= b < n) and (matrix[a][b] != '*') and matrix[a][b] <= f:
                matrix[a][b] = '*'
                queue.append((a, b))
    return matrix

def main():
    n, f = map(int, input().split())
    matriz = [[int(c) for c in input()] for _ in range(n)]
    if matriz[0][0] <= f:
        matriz = bfs(matriz, n, f)
    for i in range(n):
        matriz[i] = map(str, matriz[i])
    string = ''
    for i in range(n - 1):
        string += ''.join(matriz[i]) + '\n'
    string += ''.join(matriz[n - 1])
    print(string)

if __name__ == '__main__':
    main()