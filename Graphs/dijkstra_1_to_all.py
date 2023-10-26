import heapq

def dijkstra(graph, n, start):
    queue = [(0, start)]
    dist = [float("inf")] * n
    dist[start] = 0
    while queue:
        d, u = heapq.heappop(queue)
        for v, weight in graph[u]:
            if dist[v] > dist[u] + weight:
                dist[v] = dist[u] + weight
                heapq.heappush(queue, (dist[v], v))
    return dist
    