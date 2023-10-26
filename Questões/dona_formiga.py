def longest_path(graph, start):
    visited = set()
    stack = []
    def dfs(node):
        visited.add(node)
        for neighbor in graph[node]:
            if neighbor not in visited:
                dfs(neighbor)
        stack.append(node)
    
    for node in graph:
        if node not in visited:
            dfs(node)
    
    distances = {node : float('-inf') for node in graph}
    distances[start] = 0

    while stack:
        node = stack.pop()
        if distances[node] != float('-inf'):
            for neighbor in graph[node]:
                new_distance = distances[node] + 1
                distances[neighbor] = max(distances[neighbor], new_distance)
    
    return max(distances.values())

def main():
    s, t, p = map(int, input().split())
    p -= 1
    alturas = list(map(int, input().split()))
    graph = {i : set() for i in range(s)}
    for _ in range(t):
        i, j = map(int, input().split())
        i -= 1
        j -= 1
        if alturas[i] > alturas[j]:
            graph[i].add(j)
        elif alturas[j] > alturas[i]:
            graph[j].add(i)
    print(longest_path(graph, p))

if __name__ == '__main__':
    main()