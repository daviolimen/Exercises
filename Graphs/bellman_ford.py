def bellman_ford(graph, vertex_count, src):
    dist = [float('inf')] * vertex_count
    dist[src] = 0.0
    for _ in range(vertex_count - 1):
        for u, v, w in graph:
            if dist[u] != float('inf') and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w

    # se já for sabido que o grafo não possui ciclos negativos, essa última parte pode ser ignorada

    for u, v, w in graph:
        if dist[u] != float('inf') and dist[u] + w < dist[v]:
            return 'negative cycle detected'
    return dist

