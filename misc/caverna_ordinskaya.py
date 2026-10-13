def main():
    n, m = map(int, input().split())
    lista = [int(x) for x in input().split()]
    for i in range(n):
        if m - lista[i] < lista[i]:
            lista[i] = m - lista[i]
    for i in range(n - 1):
        if lista[i] > lista[i + 1]:
            lista[i + 1] = m - lista[i + 1]
    if lista == sorted(lista):
        print(sum(lista))
    else:
        print(-1)

if __name__ == '__main__':
    main()