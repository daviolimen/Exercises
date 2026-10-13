from collections import deque
import copy

def bfs(graph, start):
    counter = 0
    visited, queue = set(), deque([start])
    visited.add(start)
    while queue:
        vertex = queue.popleft()
        counter += 1
        for neighbor in graph[vertex]:
            if neighbor not in visited:
                queue.append(neighbor)
                visited.add(neighbor)
    return counter

def main():
    n = int(input())
    graph = {i : set() for i in range(1, n + 1)}
    edges = []
    diff = n - 2
    for _ in range(n - 1):
        tupla = tuple(map(int, input().split()))
        edges.append(tupla)
        graph[tupla[0]].add(tupla[1])
        graph[tupla[1]].add(tupla[0])
    for a, b in edges:
        copia = copy.deepcopy(graph)
        if len(copia[a]) > 1 and len(copia[b]) > 1:
            copia[a].remove(b)
            copia[b].remove(a)
            cidades0 = bfs(copia, a)
            new_diff = abs(n - 2 * cidades0)
            if new_diff < diff:
                diff = new_diff

    print(diff)

if __name__ == '__main__':
    main()