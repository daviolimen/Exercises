from collections import Counter

def main():
    n = int(input())
    pares = 0
    botas_destras = []
    botas_canhotas = []
    for _ in range(n):
        m, l = input().split()
        m = int(m)
        if l == 'D':
            botas_destras.append(m)
        else:
            botas_canhotas.append(m)
    botas_destras = Counter(botas_destras)
    botas_canhotas = Counter(botas_canhotas)
    for key in botas_canhotas.keys():
        if key in botas_destras.keys():
            pares += min(botas_destras[key], botas_canhotas[key])
    print(pares)


if __name__ == '__main__':
    main()
