from collections import deque

def bfs(graph, start, end):
    visited, queue = set(), deque([(0, start)])
    while queue:
        cost, u = queue.popleft()
        if u in visited:
            continue
        visited.add(u)
        if u == end:
            return cost
        for v in graph[u]:
            if v in visited:
                continue
            queue.append((cost + 1, v))

def main():
    n, a, b = map(int, input().split())
    graph = {i : set() for i in range(1, n + 1)}
    for _ in range(n - 1):
        u, v = map(int, input().split())
        graph[u].add(v)
        graph[v].add(u)
    print(bfs(graph, a, b))

if __name__ == '__main__':
    main()