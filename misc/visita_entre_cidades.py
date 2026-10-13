import heapq

def dijkstra(graph, start, end):
    visited, heap = set(), [(0, start)]
    while heap:
        cost, u = heapq.heappop(heap)
        if u in visited:
            continue
        visited.add(u)
        if u == end:
            return cost
        for v, c in graph[u]:
            if v in visited:
                continue
            heapq.heappush(heap, (cost + c, v))

def main():
    n, a, b = map(int, input().split())
    graph = {i : set() for i in range(1, n + 1)}
    for _ in range(n - 1):
        p, q, d = map(int, input().split())
        graph[p].add((q, d))
        graph[q].add((p, d))
    ans = dijkstra(graph, a, b)
    print(ans)

if __name__ == '__main__':
    main()
