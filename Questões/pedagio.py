from collections import deque

def bfs(graph, start, p):
    visited, queue = set(), deque([(0, start)])
    cidades = []
    while queue:
        cost, u = queue.popleft()
        if u in visited:
            continue
        if cost <= p and u != start:
            cidades.append(u)
        visited.add(u)
        for v in graph[u]:
            queue.append((cost + 1, v))
    cidades.sort()
    cidades = list(map(str, cidades))
    return cidades

def main():
    c, e, l, p = map(int, input().split())
    n = 1
    while (c, e, l, p) != (0, 0, 0, 0):
        print(f'Teste {n}')
        graph = {i : set() for i in range(1, c + 1)}
        for _ in range(e):
            x, y = map(int, input().split())
            graph[x].add(y)
            graph[y].add(x)
        resposta = bfs(graph, l, p)
        string = ' '.join(resposta)
        print(string)
        print()
        n += 1
        c, e, l, p = map(int, input().split())


if __name__ == '__main__':
    main()