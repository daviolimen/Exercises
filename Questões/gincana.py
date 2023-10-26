from collections import deque

def main():
    n, m = map(int, input().split())
    graph = {}
    nodes_left = []
    for i in range(1, n + 1):
        nodes_left.append(i)
        graph[i] = set()
    for _ in range(m):
        amigo1, amigo2 = map(int, input().split())
        graph[amigo1].add(amigo2)
        graph[amigo2].add(amigo1)
    counter = 0

    while len(nodes_left) > 0:
        counter += 1
        start = nodes_left[0]
        visited, queue = set(), deque([start])
        visited.add(start)
        while queue:
            vertex = queue.popleft()
            if vertex in nodes_left:
                nodes_left.remove(vertex)
            for neighbor in graph[vertex]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append(neighbor)
    
    print(counter)

if __name__ == '__main__':
    main()