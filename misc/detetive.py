from collections import deque

def main():
    E, I, V = map(int, input().split())
    inverted_graph = {i : [] for i in range(1, E + 1)}
    for _ in range(I):
        a, b = map(int, input().split())
        inverted_graph[b].append(a)
    X = deque(map(int, input().split()))
    sure_events = []
    while X:
        current = X.popleft()
        sure_events.append(current)
        lista = inverted_graph[current]
        if len(lista) == 1:
            new = lista[0]
            X.append(new)
    sure_events.sort()
    for element in sure_events:
        print(element, end=' ')

if __name__ == '__main__':
    main()