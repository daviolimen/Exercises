from collections import deque

def bfs(graph, start):
    visited, queue = set(), deque([start])
    visited.add(start)
    while queue:
        vertex = queue.popleft()
        print(str(vertex) + ' ', end='')

        for neighbor in graph[vertex]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)

if __name__ == '__main__':
    graph = {0: [1, 2], 1: [2], 2: [3], 3: [1, 2]}
    print("Following is Breadth First Traversal: ")
    bfs(graph, 0)