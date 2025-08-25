from collections import deque

vr = (1, 0, -1, 0)
vc = (0, 1, 0, -1)

def flood_fill(matrix, rows, columns):
    visited, queue = set(), deque([(0, 0)])
    costa = 0
    while queue:
        r, c = queue.popleft()
        if (r, c) in visited:
            continue
        visited.add((r, c))
        counter = 0
        for i in range(4):
            nr = r + vr[i]
            nc = c + vc[i]
            if 0 <= nr < rows and 0 <= nc < columns:
                queue.append((nr, nc))
                if matrix[nr][nc] == '.':
                    counter += 1
            else:
                counter += 1
        if matrix[r][c] == '#' and counter != 0:
            costa += 1
    return costa


def main():
    m, n = map(int, input().split())
    mapa = [[x for x in input()] for _ in range(m)]
    resposta = flood_fill(mapa, m, n)
    print(resposta)

if __name__ == '__main__':
    main()