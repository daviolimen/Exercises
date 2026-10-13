import heapq

def dijkstra(graph, start, end):
    heap = [(0, start)]
    visited = set()
    while heap:
        cost, u = heapq.heappop(heap)
        if u in visited:
            continue
        visited.add(u)
        if u == end:
            return cost
        for v, c in graph[u]:
            if v not in visited:
                heapq.heappush(heap, (cost + c, v))
    

def main():
    n, m = map(int, input().split())
    graph = {i : set() for i in range(1, n + 1)}
    for _ in range(m):
        a, b, c = map(int, input().split())
        graph[a].add((b, c))
        graph[b].add((a, c))
    print(dijkstra(graph, 1, n))

if __name__ == '__main__':
    main()
