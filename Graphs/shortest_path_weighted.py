import heapq

def dijkstra(graph, start, end):
    heap = [(0, start)]
    visited = set()
    while heap:
        (cost, u) = heapq.heappop(heap)
        if u in visited:
            continue
        visited.add(u)
        if u == end:
            return cost
        for v, c in graph[u]:
            if v in visited:
                continue
            next_item = cost + c
            heapq.heappush(heap, (next_item, v))
    return -1

def main():
    G = {
    "A": {("B", 2), ("C", 5)},
    "B": {("A", 2), ("D", 3), ("E", 1), ("F", 1)},
    "C": {("A", 5), ("F", 3)},
    "D": {("B", 3)},
    "E": {("B", 4), ("F", 3)},
    "F": {("C", 3), ("E", 3)},
    }

    print(dijkstra(G, "E", "C"))

if __name__ == '__main__':
    main()