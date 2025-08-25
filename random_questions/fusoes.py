from collections import deque

def bfs(graph, start):
    visited, queue = set(), deque([start])
    visited.add(start)
    while queue:
        vertex = queue.popleft()
        for v in graph[vertex]:
            if v in visited:
                continue
            else:
                visited.add(v)
                queue.append(v)
    return visited

def main():
    n, k = map(int, input().split())
    graph = {str(i) : set() for i in range(1, n + 1)}
    for _ in range(k):
        c, a, b = input().split()
        if c == 'F':
            graph[a].add(b)
            graph[b].add(a)
        else:
            temp = bfs(graph, a)
            if b in temp:
                print('S')
            else:
                print('N')
    
if __name__ == '__main__':
    main()