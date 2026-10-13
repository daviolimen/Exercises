def main():
    n = int(input())
    for _ in range(n):
        lista = input().split()
        lista.sort(key = lambda x : len(x), reverse=True)
        for i in range(len(lista) - 1):
            print(lista[i], end=' ')
        print(lista[len(lista) - 1])


if __name__ == '__main__':
    main()