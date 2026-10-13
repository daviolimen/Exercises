def main():
    n, m = map(int, input().split())
    graph = {i : set() for i in range(1, n + 1)}
    for _ in range(m):
        u, v = map(int, input().split())
        graph[u].add(v)
        graph[v].add(u)
    