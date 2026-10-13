import heapq

def dijkstra(graph, n, start):
    queue = []
    heapq.heappush(queue, (0, start))
    dist = [float("inf")] * n
    dist[start - 1] = 0
    while queue:
        d, u = heapq.heappop(queue)
        for v, weight in graph[u]:
            if dist[v - 1] > dist[u - 1] + weight:
                dist[v - 1] = dist[u - 1] + weight
                heapq.heappush(queue, (dist[v - 1], v))
    return dist


def main():
    n, m = map(int, input().split())
    grafo = {i : set() for i in range(1, n + 1)}
    for i in range(m):
        u, v, p = map(int, input().split())
        grafo[u].add((v, p))
        grafo[v].add((u, p))
    s = int(input())
    pings = dijkstra(grafo, n, s)
    pings.pop(s - 1)
    print(max(pings) - min(pings))

if __name__ == '__main__':
    main()
