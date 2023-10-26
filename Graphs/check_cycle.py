def check_cycle(graph: dict) -> bool:
    visited : set[int] = set()
    rec_stk : set[int] = set()
    return any(node not in visited and dfs(graph, node, visited, rec_stk) for node in graph)

def dfs(graph: dict, vertex: int, visited: set, rec_stk: set) -> bool:
    visited.add(vertex)
    rec_stk.add(vertex)

    for node in graph[vertex]:
        if node not in visited:
            if dfs(graph, node, visited, rec_stk):
                return True
        elif node in rec_stk:
            return True
    
    rec_stk.remove(vertex)
    return False
