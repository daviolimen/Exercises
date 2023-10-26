def main():
    a, v = map(int, input().split())
    n = 1
    while ((a, v) != (0, 0)):
        lista = [0 for _ in range(a)]
        for _ in range(v):
            x, y = map(int, input().split())
            lista[x - 1] += 1
            lista[y - 1] += 1
        max = -1
        maiores = [0]
        for i in range(a):
            if lista[i] > max:
                max = lista[i]
                maiores.clear()
                maiores.append(i + 1)
            elif lista[i] == max:
                maiores.append(i + 1)
        maiores.sort()
        print(f"Teste {n}")
        for maior in maiores:
            print(maior, end=' ')
        print()
        n += 1
        a, v = map(int, input().split())

if __name__ == '__main__':
    main()