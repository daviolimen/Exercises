def kruskal(num_nodes, edges):
    edges = sorted(edges, key=lambda edge: edge[2])
    parent = list(range(num_nodes))
    
    def find_parent(i):
        if i != parent[i]:
            parent[i] = find_parent(parent[i])
        return parent[i]

    minimum_spanning_tree_cost = 0

    for edge in edges:
        parent_a = find_parent(edge[0])
        parent_b = find_parent(edge[1])
        if parent_a != parent_b:
            minimum_spanning_tree_cost += edge[2]
            parent[parent_a] = parent_b
    
    return minimum_spanning_tree_cost

def main():
    n, m = map(int, input().split())
    edges = []
    for _ in range(m):
        u, v, c = map(int, input().split())
        edges.append((u - 1, v - 1, c))
    print(kruskal(n, edges))

if __name__ == '__main__':
    main()