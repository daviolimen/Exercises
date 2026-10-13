from collections import deque

def bfs(graph):
    visited, queue = set(), deque([(1, 1)])
    custo_finais = []
    while queue:
        cost, u = queue.popleft()
        if u in visited:
            continue
        visited.add(u)
        if len(graph[u]) == 0:
            custo_finais.append(cost)
        for v in graph[u]:
            if v in visited:
                continue
            queue.append((cost + 1, v))
    return (visited, min(custo_finais))

def main():
    n = int(input())
    vertices = set(range(1, n + 1))
    graph = {i : set() for i in range(1, n + 1)}
    for i in range(1, n + 1):
        _, *caminhos = map(int, input().split())
        for x in caminhos:
            graph[i].add(x)
    paginas, k = bfs(graph)
    if paginas == vertices:
        print('Y')
    else:
        print('N')
    print(k)

if __name__ == '__main__':
    main()