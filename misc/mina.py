import heapq

vc = (1, 0, -1, 0)
vr = (0, 1, 0, -1)

def dijkstra(matriz, n, start, end):
    heap = [(0, start[0], start[1])]
    visited = set()
    while heap:
        cost, r, c = heapq.heappop(heap)
        if (r, c) in visited:
            continue
        visited.add((r, c))
        if (r, c) == end:
            return cost
        for i in range(4):
            a = r + vr[i]
            b = c + vc[i]
            if a >= 0 and a < n and b >= 0 and b < n:
                if (a, b) in visited:
                    continue
                next_item = cost + matriz[a][b]
                heapq.heappush(heap, (next_item, a, b))
    return -1

def main():
    n = int(input())
    matrix = [[int(x) for x in input().split()] for _ in range(n)]
    print(dijkstra(matrix, n, (0, 0), (n - 1, n - 1)))

if __name__ == '__main__':
    main()