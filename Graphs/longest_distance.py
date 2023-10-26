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
