def kruskal(n, edges):
    edges = sorted(edges, key=lambda edge : edge[2])
    parent = list(range(n))
    def find_parent(i):
        if i != parent[i]:
            parent[i] = find_parent(parent[i])
        return parent[i]
    
    mst = []

    for edge in edges:
        parent_a = find_parent(edge[0])
        parent_b = find_parent(edge[1])
        if parent_a != parent_b:
            mst.append(edge)
            parent[parent_a] = parent_b

    return mst

def main():
    n, m = map(int, input().split())
    counter = 1
    while n != 0:
        graph = []
        for _ in range(m):
            x, y, z = map(int, input().split())
            edge = (x - 1, y - 1, z)
            graph.append(edge)
        mst = kruskal(n, graph)
        print(f'Teste {counter}')
        for edge in mst:
            no1 = edge[0] + 1
            no2 = edge[1] + 1
            if no1 < no2:
                print(f'{no1} {no2}')
            else:
                print(f'{no2} {no1}')
        print()
        counter += 1
        n, m = map(int, input().split())

if __name__ == '__main__':
    main()