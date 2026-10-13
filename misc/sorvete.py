def main():
    p, s = map(int, input().split())
    lista = []
    for _ in range(s):
        t = tuple(int(x) for x in input().split())
        lista.append(t)
    lista.sort()
    inicio, final = lista[0]
    for i in range(1, s):
        u, v = lista[i]
        if (u <= final) and (v > final):
            final = v
        elif (u > final):
            print(f"{inicio} {final}")
            inicio = u
            final = v
    print(f"{inicio} {final}")

if __name__ == '__main__':
    main()