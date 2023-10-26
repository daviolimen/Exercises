from collections import deque

def shortest_bfs(graph, start, dest):
    visited, queue = set(), deque([(start, 0)])
    visited.add(start)
    while queue:
        vertex, distance = queue.popleft()
        for neighbor in graph[vertex]:
            if neighbor == dest:
                return distance + 1
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append((neighbor, distance + 1))
    return 'No path from start to destination'

if __name__ == '__main__':
    graph = {
        'W': ['X', 'V'],
        'X': ['W', 'Y'],
        'V': ['W', 'Z'],
        'Y': ['X', 'Z'],
        'Z': ['Y', 'V']
    }
    shortest_path = shortest_bfs(graph, 'W', 'Y')
    print(shortest_path)