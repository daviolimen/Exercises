import heapq

def dijkstra(graph, start, end):
    heap = [(0, start)]
    visited = set()
    while heap:
        (cost, u) = heapq.heappop(heap)
        if u in visited:
            continue
        visited.add(u)
        if u == end:
            return cost
        for v, c in graph[u]:
            if v in visited:
                continue
            next_item = cost + c
            heapq.heappush(heap, (next_item, v))
    return -1

def main():
    n, m = map(int, input().split())
    grafo = {i : set() for i in range(0, n + 2)}
    for _ in range(m):
        s, t, b = map(int, input().split())
        grafo[s].add((t, b))
    
    print(dijkstra(grafo, 0, n + 1))


if __name__ == '__main__':
    main()