def main():
    n, m = map(int, input().split())
    graph = {}
    respostas = []
    for _ in range(m):
        linha = list(map(int, input().split()))
        if linha[0] == 1:
            if linha[1] not in graph.keys():
                graph[linha[1]] = set()
            if linha[2] not in graph.keys():
                graph[linha[2]] = set()
            graph[linha[1]].add(linha[2])
            graph[linha[2]].add(linha[1])
        else:
            if linha[1]in graph.keys() and linha[2] in graph.keys():
                if linha[1] in graph[linha[2]] and linha[2] in graph[linha[1]]:
                    respostas.append(1)
                else:
                    respostas.append(0)
            else:
                respostas.append(0)
    for i in respostas:
        print(i)

if __name__ == '__main__':
    main()