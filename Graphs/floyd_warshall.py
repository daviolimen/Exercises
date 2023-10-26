def floyd_warshall(graph, n):
    dist = [row.copy() for row in graph]
    for k in range(n):
        for i in range(n):
            for j in range(n):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
    return dist

def main():
    n, m = map(int, input().split())
    graph = [[float("inf") for _ in range(n)] for _ in range(n)]
    for _ in range(m):
        u, v, p = map(int, input().split())
        graph[u - 1][v - 1] = p
        graph[v - 1][u - 1] = p
    dist = floyd_warshall(graph, n)
    print(dist)

if __name__ == '__main__':
    main()